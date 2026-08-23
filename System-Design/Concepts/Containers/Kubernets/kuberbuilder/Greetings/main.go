package main

import (
	"fmt"

	metav1 "k8s.io/apimachinery/pkg/apis/meta/v1"
)

// GreetingSpec is the desired state: what you asked for.
type GreetingSpec struct {
	Message string
}

// GreetingStatus is the observed state: what the controller did.
type GreetingStatus struct {
	Said string
}

// Greeting is a tiny stand-in for a Kubebuilder custom resource.
// In a real project this type is generated from your API and stored in the cluster.
type Greeting struct {
	metav1.TypeMeta
	metav1.ObjectMeta
	Spec   GreetingSpec
	Status GreetingStatus
}

// Reconcile is the function Kubebuilder asks you to fill in.
// Kubernetes calls it whenever a Greeting changes. Here we just run it once.
func Reconcile(greeting *Greeting) {
	fmt.Printf("Hello World from Kubebuilder: %s says %q\n", greeting.Name, greeting.Spec.Message)
	greeting.Status.Said = greeting.Spec.Message
}

func main() {
	greeting := &Greeting{
		TypeMeta: metav1.TypeMeta{
			APIVersion: "demo.example.com/v1",
			Kind:       "Greeting",
		},
		ObjectMeta: metav1.ObjectMeta{
			Name:      "hello",
			Namespace: "default",
		},
		Spec: GreetingSpec{
			Message: "Hello World",
		},
	}

	fmt.Printf("applied %s/%s  spec.message=%q  status.said=%q\n",
		greeting.Kind, greeting.Name, greeting.Spec.Message, greeting.Status.Said)

	Reconcile(greeting)

	fmt.Printf("after reconcile  spec.message=%q  status.said=%q\n",
		greeting.Spec.Message, greeting.Status.Said)
}
