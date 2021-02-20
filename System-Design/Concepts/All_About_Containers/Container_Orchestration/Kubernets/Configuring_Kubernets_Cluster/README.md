## Configuring kubernets Cluster
- **Kubernets cluster?** Complete deployment including kubernets master, worker nodes, containers etc is called kubernets cluster.
- In order to Deployment/Scaling up-down [Docker](/System-Design/Concepts/All_About_Containers/Docker/What_is_Docker.md) containers using kubernets following steps are required.
- **Steps**
  - *1.* Creating kubernets cluster
```bash
$ install

$ minikube version                              //Check version
  minikube version: v1.8.1
  
$ minikube start                                //Start minikube kubernets cluster

$ kubectl version
  Client Version: version.Info{Major:"1", Minor:"17"...}    //Worker node version
  Server Version: version.Info{Major:"1", Minor:"17",..}      //Master node version

$ kubectl get nodes                                       //How many nodes are in kubernetes cluster
NAME       STATUS   ROLES    AGE   VERSION
minikube   Ready    master   2m    v1.17.3
```
  - *2.* Deploy Application on cluster
    - Run command on [Master Node](/System-Design/Concepts/All_About_Containers/Container_Orchestration/Kubernets/Architecture/README.md), this will create Application=amit-app on any of available worker node/VM
```bash
$ kubectl create deployment amit-app --image=gcr.io/google-samples/kubernetes-bootcamp:v1
deployment.apps/amit-app created
$ kubectl get deployments.apps 
NAME                  READY   UP-TO-DATE   AVAILABLE   AGE
amit-app              1/1     1            1           111s
kubernetes-bootcamp   1/1     1            1           3m19s
```
  - *3.* Viewing [Pods & Workers/Nodes](/System-Design/Concepts/All_About_Containers/Container_Orchestration/Kubernets/Architecture/README.md)
```bash
$ kubectl get pods
$ kubectl describe pods
$ kubectl proxy         //Note, pods run on pvt network hence proxy is needed to communicate with them.

$ systemctl start apache    //Start Application inside container
```
