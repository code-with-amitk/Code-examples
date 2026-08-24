
## [Kubebuilder](https://code-with-amitk.github.io/System_Design/Concepts/Kubernets/Terms.html)

- **Kubebuilder** is a Go toolkit for adding your own Kubernetes kinds. It does not replace a [Kubernetes controller](https://code-with-amitk.github.io/System_Design/Concepts/Kubernets/Architecture.html).
- It plugs into the same controller-manager.
- This program talks to the [API server](https://code-with-amitk.github.io/System_Design/Concepts/Kubernets/Architecture.html) on control plane, through [controller-runtime](https://code-with-amitk.github.io/System_Design/Concepts/Kubernets/Architecture.html) (the library Kubebuilder generates). It keeps one **custom** kind alive: `Greeting`.
