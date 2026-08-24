

This Code is reference [here](https://code-with-amitk.github.io/System_Design/Concepts/Kubernets/Terms.html#Kubebuilder): Donot Delete

## [What is Kubebuilder?](https://code-with-amitk.github.io/System_Design/Concepts/Kubernets/Terms.html#Kubebuilder)

### What `main.go` does

1. Builds a `Greeting` named `hello` whose spec message is `Hello World`.
2. Calls `Reconcile`, the same function you would fill in with Kubebuilder.
3. Copies the spec message into `status.said`

That is the Hello World: desired state in spec, observed state in status.

```bash
go build -o hello-world .
./hello-world
```
