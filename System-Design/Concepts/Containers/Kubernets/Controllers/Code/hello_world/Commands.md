

# Commands

Check kubernetes state
```
# get: Check resource
$ kubectl get nodes
NAME             STATUS   ROLES           AGE   VERSION
docker-desktop   Ready    control-plane   21h   v1.32.2
```

Run this code
```bash
go run .

hello-controller started
desired state: pod default/hello-world should exist
pod hello-world is missing — creating it
created pod hello-world
pod hello-world is present — nothing to do
```

From Docker Desktop, Delete the container. It will create again in 3 seconds.


## See, Delete pod

```bash
kubectl get pods
kubectl get pod hello-world -o yaml
kubectl logs hello-world

kubectl delete pod hello-world
kubectl get pods -w

It will create again in 3 seconds.
```


