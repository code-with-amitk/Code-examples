- [Different Options to Install kubernets](#opt)
  - [Minikube](minikube)

<a name=opt></a>
### Different Options to Install kubernets
There are several ways of Installing kubernets cluster.
|Option|What|
|---|---|
|[1. minikube](minikube)|single node Kubernetes cluster locally on your machine(not for production)|
|2. Managed Kubernetes services|Provided by AWS, Axure, GCP|
|3. Kubernetes distributions|Eg: Red Hat OpenShift, Rancher, and VMware Tanzu|


<a name=cfgk></a>
## Configure kubernets Cluster(1 master, n workers)
#### a. Configuration file for deploying 2 containers. Containers having ngnix image.
```yaml
$ vim test.yaml
apiVersion: app/v1
kind: Development
metadata:
  name: nginx-deployment
  labels:
    app: nginx
sped:
  replicas: 3                       //Number of pods to be running at a time
  selector:
    matchlabels:
      app: nginx
  template:
    metadata:
      labels:
        app: nginx
      spec:
        containers:
        - name: nginx
          image: nginx:1.7.9
          ports:
          - containerPort: 80
```
#### b. Create container using kubectl command
```c
$ kubectl apply -f test.yaml
```
#### c. Install,start kubernets master, worker nodes
```c
$ install
$ minikube start                                            //Start minikube kubernets cluster
$ kubectl version
  Client Version: version.Info{Major:"1", Minor:"17"...}    //Worker node version
  Server Version: version.Info{Major:"1", Minor:"17",..}    //Master node version
$ kubectl get nodes                                         //How many nodes are in kubernetes cluster
NAME       STATUS   ROLES    AGE   VERSION
minikube   Ready    master   2m    v1.17.3
```
#### d. Deploy Application on cluster
```c
//Run command on Master Node. This will create Application=amit-app on any of available worker node/VM
$ kubectl create deployment amit-app --image=gcr.io/google-samples/kubernetes-bootcamp:v1
  deployment.apps/amit-app created

$ kubectl get deployments.apps 
NAME                  READY   UP-TO-DATE   AVAILABLE   AGE
amit-app              1/1     1            1           111s
kubernetes-bootcamp   1/1     1            1           3m19s
```
#### e. Check Pods and worker nodes
```c
$ kubectl get pods
$ kubectl describe pods
$ kubectl proxy                               //Note, pods run on pvt network hence proxy is needed to communicate with them.
$ systemctl start apache                      //Start Application inside container
```
