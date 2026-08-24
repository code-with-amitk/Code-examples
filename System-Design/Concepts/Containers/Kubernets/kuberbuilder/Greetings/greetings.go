package main

import (
	metav1 "k8s.io/apimachinery/pkg/apis/meta/v1"
	"k8s.io/apimachinery/pkg/runtime"
	"k8s.io/apimachinery/pkg/runtime/schema"
)

const (
	greetingKind       = "Greeting"
	greetingAPIVersion = "demo.example.com/v1"
)

var (
	// SchemeGroupVersion is the API group/version of our custom kind.
	// Kubebuilder would generate this from `kubebuilder create api --group demo --version v1 --kind Greeting`.
	SchemeGroupVersion = schema.GroupVersion{Group: "demo.example.com", Version: "v1"}
)

// GreetingSpec is the desired state: what you asked for.
type GreetingSpec struct {
	Message string `json:"message"`
}

// GreetingStatus is the observed state: what the controller saw.
type GreetingStatus struct {
	// Phase is "Up" after a successful reconcile.
	Phase string `json:"phase,omitempty"`
	// Said is a copy of spec.message after the controller handled it.
	Said string `json:"said,omitempty"`
}

// Greeting is our custom kind. It is not a Pod, Deployment, or Service.
// The API server only accepts it after the CRD in config/crd/greeting.yaml is installed.
type Greeting struct {
	metav1.TypeMeta   `json:",inline"`
	metav1.ObjectMeta `json:"metadata,omitempty"`

	Spec   GreetingSpec   `json:"spec,omitempty"`
	Status GreetingStatus `json:"status,omitempty"`
}

// GreetingList is required so the manager can list/watch Greeting objects.
type GreetingList struct {
	metav1.TypeMeta `json:",inline"`
	metav1.ListMeta `json:"metadata,omitempty"`
	Items           []Greeting `json:"items"`
}

func (in *Greeting) DeepCopyInto(out *Greeting) {
	*out = *in
	out.TypeMeta = in.TypeMeta
	in.ObjectMeta.DeepCopyInto(&out.ObjectMeta)
	out.Spec = in.Spec
	out.Status = in.Status
}

func (in *Greeting) DeepCopy() *Greeting {
	if in == nil {
		return nil
	}
	out := new(Greeting)
	in.DeepCopyInto(out)
	return out
}

func (in *Greeting) DeepCopyObject() runtime.Object {
	if c := in.DeepCopy(); c != nil {
		return c
	}
	return nil
}

func (in *GreetingList) DeepCopyInto(out *GreetingList) {
	*out = *in
	out.TypeMeta = in.TypeMeta
	in.ListMeta.DeepCopyInto(&out.ListMeta)
	if in.Items != nil {
		out.Items = make([]Greeting, len(in.Items))
		for i := range in.Items {
			in.Items[i].DeepCopyInto(&out.Items[i])
		}
	}
}

func (in *GreetingList) DeepCopy() *GreetingList {
	if in == nil {
		return nil
	}
	out := new(GreetingList)
	in.DeepCopyInto(out)
	return out
}

func (in *GreetingList) DeepCopyObject() runtime.Object {
	if c := in.DeepCopy(); c != nil {
		return c
	}
	return nil
}

// AddToScheme registers Greeting with a runtime.Scheme so controller-runtime
// can encode/decode our kind. This is the plug-in point for a custom API.
func AddToScheme(scheme *runtime.Scheme) error {
	scheme.AddKnownTypes(SchemeGroupVersion, &Greeting{}, &GreetingList{})
	metav1.AddToGroupVersion(scheme, SchemeGroupVersion)
	return nil
}

func desiredGreeting() *Greeting {
	return &Greeting{
		TypeMeta: metav1.TypeMeta{
			APIVersion: greetingAPIVersion,
			Kind:       greetingKind,
		},
		ObjectMeta: metav1.ObjectMeta{
			Name:      greetingName,
			Namespace: namespace,
		},
		Spec: GreetingSpec{
			Message: "Hello World",
		},
	}
}

func greetingIsUp(g *Greeting) bool {
	return g.Status.Phase == "Up" && g.Status.Said == g.Spec.Message
}
