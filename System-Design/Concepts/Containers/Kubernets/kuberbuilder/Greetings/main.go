package main

import (
	"context"
	"fmt"
	"os"
	"time"

	apierrors "k8s.io/apimachinery/pkg/api/errors" //
	"k8s.io/apimachinery/pkg/runtime"
	utilruntime "k8s.io/apimachinery/pkg/util/runtime"
	ctrl "sigs.k8s.io/controller-runtime"
	"sigs.k8s.io/controller-runtime/pkg/client"
	"sigs.k8s.io/controller-runtime/pkg/log/zap"
	metricsserver "sigs.k8s.io/controller-runtime/pkg/metrics/server"
)

const (
	namespace    = "default"
	greetingName = "hello"
	requeueAfter = 3 * time.Second
)

// GreetingReconciler is what Kubebuilder would put in internal/controller/.
// It uses the same desired-state idea as ../kubernets_controller, but for
// our Greeting kind instead of a built-in Pod.
type GreetingReconciler struct {
	client.Client
}

func main() {
	fmt.Println("main started")

	ctrl.SetLogger(zap.New(zap.UseDevMode(true))) // optional: structured logs

	//https://code-with-amitk.github.io/Languages/Programming/Go/
	// 1. Connect to the cluster
	// 2. Create a scheme to register the Greeting kind
	// 3. Create a directClient to talk to the cluster
	// 4. Check if the Greeting kind is installed
	// 5. Ensure the desired Greeting exists
	// 6. Create the Greeting if it doesn't exist
	// 7. Start the controller
	// 8. Wait for the controller to finish
	// 9. Stop the controller
	// 10. Exit the program
	scheme := runtime.NewScheme()
	utilruntime.Must(AddToScheme(scheme))

	// Same kubeconfig as kubectl and ../kubernets_controller (~/.kube/config).
	// controller-runtime's Manager is how Kubebuilder plugs into that client.
	cfg, err := ctrl.GetConfig()
	if err != nil {
		fmt.Fprintf(os.Stderr, "could not talk to the cluster: %v\n", err)
		os.Exit(1)
	}

	directClient, err := client.New(cfg, client.Options{Scheme: scheme})
	if err != nil {
		fmt.Fprintf(os.Stderr, "could not build client: %v\n", err)
		os.Exit(1)
	}

	if err := checkCRDInstalled(directClient); err != nil {
		fmt.Fprintf(os.Stderr, "Greeting kind is not installed.\n")
		fmt.Fprintf(os.Stderr, "Install it first: kubectl apply -f config/crd/greeting.yaml\n")
		fmt.Fprintf(os.Stderr, "%v\n", err)
		os.Exit(1)
	}

	// Same idea as ../kubernets_controller creating the pod if it is missing.
	if err := ensureDesiredGreeting(directClient); err != nil {
		fmt.Fprintf(os.Stderr, "could not ensure greeting %s/%s: %v\n", namespace, greetingName, err)
		os.Exit(1)
	}

	mgr, err := ctrl.NewManager(cfg, ctrl.Options{
		Scheme:  scheme,
		Metrics: metricsserver.Options{BindAddress: "0"},
	})
	if err != nil {
		fmt.Fprintf(os.Stderr, "could not create manager: %v\n", err)
		os.Exit(1)
	}

	if err := (&GreetingReconciler{Client: mgr.GetClient()}).SetupWithManager(mgr); err != nil {
		fmt.Fprintf(os.Stderr, "could not set up controller: %v\n", err)
		os.Exit(1)
	}

	fmt.Println("hello-greeting-controller started")
	fmt.Printf("desired state: greeting %s/%s should exist and be Up\n", namespace, greetingName)
	fmt.Println("press Ctrl+C to stop")

	if err := mgr.Start(ctrl.SetupSignalHandler()); err != nil {
		fmt.Fprintf(os.Stderr, "manager stopped: %v\n", err)
		os.Exit(1)
	}
}

func checkCRDInstalled(c client.Client) error {
	return c.List(context.Background(), &GreetingList{})
}

func ensureDesiredGreeting(c client.Client) error {
	ctx := context.Background()
	existing := &Greeting{}
	err := c.Get(ctx, client.ObjectKey{Namespace: namespace, Name: greetingName}, existing)
	if err == nil {
		fmt.Printf("greeting %s already exists\n", greetingName)
		return nil
	}
	if !apierrors.IsNotFound(err) {
		return err
	}

	fmt.Printf("greeting %s is not up — creating it\n", greetingName)
	if err := c.Create(ctx, desiredGreeting()); err != nil {
		return err
	}
	fmt.Printf("created greeting %s\n", greetingName)
	return nil
}

func (r *GreetingReconciler) SetupWithManager(mgr ctrl.Manager) error {
	return ctrl.NewControllerManagedBy(mgr).
		For(&Greeting{}).
		Complete(r)
}

// Reconcile is one pass of the control loop, same job as reconcile() in
// ../kubernets_controller:
//
//	Get the object → if missing, create it → if present, check that it is up.
//
// The Manager calls this when a Greeting changes, and we also requeue every
// 3 seconds so the loop looks like the other controller.
func (r *GreetingReconciler) Reconcile(ctx context.Context, req ctrl.Request) (ctrl.Result, error) {
	result := ctrl.Result{}
	if req.Namespace == namespace && req.Name == greetingName {
		result.RequeueAfter = requeueAfter
	}

	greeting := &Greeting{}
	err := r.Get(ctx, req.NamespacedName, greeting)
	if err == nil {
		if greetingIsUp(greeting) {
			fmt.Printf("greeting %s is up — nothing to do\n", req.Name)
			return result, nil
		}

		fmt.Printf("greeting %s is present but not up — marking it Up\n", req.Name)
		greeting.Status.Phase = "Up"
		greeting.Status.Said = greeting.Spec.Message
		if err := r.Status().Update(ctx, greeting); err != nil {
			return ctrl.Result{}, err
		}
		fmt.Printf("greeting %s is up  spec.message=%q  status.said=%q\n",
			req.Name, greeting.Spec.Message, greeting.Status.Said)
		return result, nil
	}

	if !apierrors.IsNotFound(err) {
		return ctrl.Result{}, err
	}

	if req.Namespace != namespace || req.Name != greetingName {
		return ctrl.Result{}, nil
	}

	fmt.Printf("greeting %s is not up — creating it\n", greetingName)
	if err := r.Create(ctx, desiredGreeting()); err != nil {
		return ctrl.Result{}, err
	}
	fmt.Printf("created greeting %s\n", greetingName)
	return result, nil
}
