package main

import (
	"context"
	"fmt"
	"os"
	"path/filepath"
	"time"

	corev1 "k8s.io/api/core/v1"
	apierrors "k8s.io/apimachinery/pkg/api/errors"
	metav1 "k8s.io/apimachinery/pkg/apis/meta/v1"
	"k8s.io/client-go/kubernetes"
	"k8s.io/client-go/tools/clientcmd"
)

const (
	namespace = "default"
	podName   = "hello-world"
)

func main() {
	client, err := newClient()
	if err != nil {
		fmt.Fprintf(os.Stderr, "could not talk to the cluster: %v\n", err)
		os.Exit(1)
	}

	fmt.Printf("desired state: pod %s/%s should exist\n", namespace, podName)
	fmt.Println("press Ctrl+C to stop")

	// This is the control loop. Real controllers do the same thing:
	// observe actual state, compare it to desired state, then act.
	for {
		if err := reconcile(client); err != nil {
			fmt.Printf("reconcile error: %v\n", err)
		}
		time.Sleep(3 * time.Second)
	}
}

// reconcile is one pass of the control loop.
// Desired state: a pod named hello-world exists in default.
// If it is missing, create it. If it is already there, do nothing.
func reconcile(client *kubernetes.Clientset) error {

	// https://code-with-amitk.github.io/Languages/Programming/Go/Modules/Context.html
	ctx := context.Background()
	fmt.Println("ctx: ", ctx)

	// get the pods
	pods := client.CoreV1().Pods(namespace)
	fmt.Println("pods: ", pods)

	_, err := pods.Get(ctx, podName, metav1.GetOptions{})
	if err == nil {
		fmt.Printf("pod %s is present — nothing to do\n", podName)
		return nil
	}
	if !apierrors.IsNotFound(err) {
		return err
	}

	fmt.Printf("pod %s is missing — creating it\n", podName)
	_, err = pods.Create(ctx, helloPod(), metav1.CreateOptions{})
	if err != nil {
		return err
	}
	fmt.Printf("created pod %s\n", podName)
	return nil
}

func helloPod() *corev1.Pod {
	return &corev1.Pod{
		ObjectMeta: metav1.ObjectMeta{
			Name:      podName,
			Namespace: namespace,
			Labels: map[string]string{
				"app":        "hello-world",
				"managed-by": "hello-controller",
			},
		},
		Spec: corev1.PodSpec{
			Containers: []corev1.Container{{
				Name:    "hello",
				Image:   "busybox:1.36",
				Command: []string{"sh", "-c", "echo Hello from a controller-managed pod && sleep 3600"},
			}},
			RestartPolicy: corev1.RestartPolicyAlways,
		},
	}
}

// newClient uses your local kubeconfig (~/.kube/config), the same file kubectl uses.
func newClient() (*kubernetes.Clientset, error) {
	home, err := os.UserHomeDir()
	if err != nil {
		return nil, err
	}
	fmt.Println("home: ", home)

	// https://code-with-amitk.github.io/Languages/Programming/Go/Modules/clientcmd.html
	config, err := clientcmd.BuildConfigFromFlags("", filepath.Join(home, ".kube", "config"))
	if err != nil {
		return nil, err
	}
	fmt.Println("config: ", config)

	return kubernetes.NewForConfig(config)
}
