
# Hello World Kubernetes Controller

A tiny Go controller that keeps **one pod** named `hello-world` alive.

If the pod is missing, the controller creates it.
If you delete the pod, the controller creates it again.

## How this example works

On startup the program:

1. Reads `~/.kube/config` (the same file `kubectl` uses)
2. Connects to your cluster
3. Every 3 seconds:
   - asks the API server: "does pod `default/hello-world` exist?"
   - if **no** → creates a `busybox` pod
   - if **yes** → prints "nothing to do"
