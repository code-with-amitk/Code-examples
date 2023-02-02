**Container Orchestration**
- [Kubernets](#Kub)
  - [Kubernets Architecture](#ka) 
    - [Master Node](#mn)
    - [Worker Node](#wn)
      - [Pod](#pod)
      - [Namespaces](#ns)
  - Kubernets Terms
    - [configmap](#cm)
    - [Kubernets Objects](#ko)
      - Types of k8 objects
        - [1. deployment](#dep)
        - [2. configmap](#cm)
        - [3. service](#ser)
  - [Configure kubernets Cluster](#cfgk)
  - [Commands](#kcmd)


## Container Orchestration
**Orhestration?** Managing the lifecycles of containers. These are GUI/tools to automate following tasks: Deployment, Scaling up/down, Movement of containers from one host to another, Load balancing, Health monitoring.
  - *Examples of Container Orhestrators:* Kubernets, Docker swarm, Nomad

<a name=kub></a>
# Kubernets
Cluster having different microservices inside it.
```c
  |--------------k8s cluster------------|
  | micro_service1      micro_service4  |
  |                                     |
  |   micro_service2                    |
  |                                     |
  |           micro_servicen            |
  |-------------------------------------|
```
<a name=ka></a>
## Kubernets Architecture
```c

User               |------MASTER_NODE--------|      |--------WORKER_NODE-1 -------|
   --*.yaml-->     |Controller  API_service <--------> Kubelet Kubectl_Proxy--------> Worker_Node-2
                   |                         |      |                  |------------> Worker_Node-3
                   |Scheduler     etcd       |      |                             |
                   |-------------------------|      |  |------POD---------------| |
                                                    |  | |-container1(docker)-| | |
                                                    |  | | Application-1,libs | | |
                                                    |  | |--------------------| | |
                                                    |  |                        | |
                                                    |  | |-container2(docker)-| | |
                                                    |  | | Application-1,libs | | |
                                                    |  | |--------------------| | |
                                                    |  |                        | |
                                                    |  |------------------------| |
                                                    |-----------------------------|
```
<a name=mn></a>
### A. Master Node
- User Intercts with Master node(using yaml file). Master node create/destroy worker nodes.
- **Daemon in master node**
  - *1. Controller Manager:* Monitors created containers/worker nodes. When worker node finishes the task(or load on cluster is low). VM/Worker node is bought down and when load becomes high a new worker node/VM is spawned again.
  - *2. API Service:* Manages all communication with Worker nodes(using kubelet)
  - _3. Scheduler:_ For placing pods across nodes to balance resource consumption.
  - 4. _etcd:_ Database that hosts cluster state information.

<a name=wn></a>
### B. Worker Node
- handles workload. Worker nodes hosts [PODS](#pod). 1 Pod can contain 1 or more [containers, Eg: docker](#doc).
- **Daemons in worker node:** *1. Kubelet:* Process for communication with master, *2. [Docker](#doc):* A container runtime, *3. Kube Proxy:* for communication with other nodes in cluster.

<a name=pod></a>
#### POD 
- Complete package which Kubernets creates to install application on Worker Node. Pod can contain multiple containers(application). Pods run in isolated pvt enviornment. Memory is allocated to Pods using [Volumes](/Operating_Systems/Linux/Partitions_Mounting).
- Pod Contains:
  - *1.* Container(Eg: [Docker](#doc))
  - *2.* Shared storage, as Volumes
  - *3.* Networking, as a unique cluster IP address,port
  - *4.* other Information 

<img src=kubernets_pod_worker_node.png width=600>

<a name=ns></a>
#### Namespaces
- Collection of pods ie Virtual clusters inside kubernets cluster. Multiple pods can run inside a namespace.
- 3 predefined namespaces:
  - _a. Default_ 
  - _b. Kube-system:_ resources created by kubernets
  - _c. Kube-public:_ reserved for future
```c
$ kubectl create namespace test                       //Creating new namespace
$ kubectl --namespace=test  run ngnix --image=nginx   //Deploy namespace
```

## Kubernets Terms
<a name=ko></a>
## [Kubernets Objects](https://kubernetes.io/docs/concepts/overview/working-with-objects/kubernetes-objects/)
A Kubernetes object always exist once we create them. k8 objects stores:
- Containerized applications configuration, Resources available to those applications, Policies of those applications(restart,upgrades etc)
### Types of k8 objects
<a name=dep></a>
#### 1. Deployment
Represent an application running on your cluster
```yaml
//test.yaml
apiVersion: apps/v1       #(Required) Which version of the Kubernetes API you're using to create this object
kind: Deployment          #(Required) What kind of object you want to create
metadata:                 #(Required) Data that helps uniquely identify the object
  name: nginx-deployment
spec:                     #(Required) What state you desire for the object
  selector:
    matchLabels:
      app: nginx
  replicas: 2 # tells deployment to run 2 pods matching the template

$ kubectl apply -f test.yaml
```
<a name=cm></a>
#### [2. ConfigMap](https://kubernetes.io/docs/concepts/configuration/configmap/#configmap-object)
- Object storing configuration of [POD](#ka)
- Unlike most Kubernetes objects(Eg: [Deployment](#dep) that have a spec), a ConfigMap has data and binaryData fields. Both the data field and the binaryData are optional
#### Creating a configmap
We can copy
```yaml
# cat test.properties
name=Amit
age=25
life=Great
worry=None

# kubectl create configmap amit-configmap --from-file=test.properties   //Create configmap

# kubectl get configmaps amit-configmap -o yaml                         //View configmap. 
apiVersion: v1
kind: ConfigMap
metadata:
  creationTimestamp: "2022-02-17T12:41:43Z"
  name: amit-configmap
  namespace: fs-central
  resourceVersion: "55390398"
  uid: 65e65104-d94c-4054-9359-16f5dc221b53
data:
  test.properties: |
    name=Amit
    age=25
    life=Great
    worry=None
```

<a name=ser></a>
#### 3. Services
- In Kubernetes, Service/microservice = `logical set of Pods`.
- Application is not aware to which pod its communicating, even at t=1 and t=n number of pods serving application(s) need maybe different.
- Service exposes REST endpoints(eg: POST) & application interacts with service by calling these endpoints.
##### Defining a service object = service-object-amit1
  - Kubernetes will assign this Service a IP address/"cluster IP", which is used by the Service proxies
  - The controller will scans all Pods, those matching selector POST/REST Requests are sent to them.
```yml
apiVersion: v1
kind: Service
metadata:
  name: service-object-amit1
spec:
  selector:
    app.kubernetes.io/name: MyApp   //Every pod has this label
  ports:
    - protocol: TCP
      port: 80
      targetPort: 9376        //Every pod listens on this TCP port
```

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

<a name=kcmd></a>
### Kubernets commands (kubectl -h)
<a name=ser></a>
#### Services
```c
//ssh to kubernets VM running microservices
# kubectl get svc -A                        //List all services on this VM
$ kubectl get service --all-namespaces      //IP Addresses of all services in cluster in all namespaces
NAMESPACE     NAME                       TYPE        CLUSTER-IP      EXTERNAL-IP   PORT(S)         AGE
default       kubernetes                 ClusterIP   10.32.0.1       <none>        443/TCP         6d
kube-system   csi-attacher-doplugin      ClusterIP   10.32.159.128   <none>        12345/TCP       6d
kube-system   csi-provisioner-doplugin   ClusterIP   10.32.61.61     <none>        12345/TCP       6d
kube-system   kube-dns                   ClusterIP   10.32.0.10      <none>        53/UDP,53/TCP   6d
kube-system   kubernetes-dashboard       ClusterIP   10.32.226.209   <none>        443/TCP 
$ kubectl -n name_space get service         //Get all services within namespace
```
<a name=pc></a>
#### Pods
```c
$ kubectl get pods -A                             //List all pods
NAMESPACE               POD-NAME                  READY   STATUS      RESTARTS   AGE
nsa                     pod1                      1/1     Running     0          48d      //2 pods in namespace=nsa
nsa                     pod2                      0/2     Completed   0          7d3h
nsb                     pod1                      0/2     Completed   0          7d3h
nsb                     pod2                      0/2     Completed   0          7d3h

$ kubectl get pods -A | grep kafka                //All pods named kafka*
Namespace              Pod-name         READY   STATUS      RESTARTS   AGE
n1                      kafka-0         2/2     Running     0          38d
n1                      kafka-1         2/2     Running     0          38d
n1                      kafka-2         2/2     Running     0          38d

$ kubectl -n namespace get pods                 //All pods in namespace

//////////Commands from inside the POD//////////////
$ kubectl exec -it testing{pod_name} -n namespace /bin/bash   //Go inside POD

root@testing:/opt/# ping namespace.service_name               //Pinging service

```
<a name=lc></a>
#### Logs of Container in Pod
```c
$ kubectl logs -h                             //Print the logs for a container in a pod

$ kubectl get pods -A | grep kafka            //Get All pods named kafka*
namespace               pods
ns1                     kafka-a     2/2     Running     0          46d
ns1                     kafka-b     2/2     Running     0          46d
ns1                     kafka-c     2/2     Running     0          46d

$ kubectl logs kafka-c -n ns1                 //In pod kafka-c, 3 containers are running.
error: a container name must be specified for pod kafka-c, choose one of: [prometheus-jmx-exporter kafka-broker]

//Get logs of container kafka-broker
$ kubectl logs kafka-2 -n ns1 kafka-broker> t.txt    //kubectl logs podname namespace containerName

//Live tail
$ kubectl logs kafka-2 -n ns1 kafka-broker --follow
```

<a name=mk></a>
### [Running Minikube](https://minikube.sigs.k8s.io/docs/start/)
```ps
//1. Run on powershell
New-Item -Path 'c:\' -Name 'minikube' -ItemType Directory -Force
Invoke-WebRequest -OutFile 'c:\minikube\minikube.exe' -Uri 'https://github.com/kubernetes/minikube/releases/latest/download/minikube-windows-amd64.exe' -UseBasicParsing

//2. Add the binary in to your PATH.
//Make sure to run PowerShell as Administrator.

$oldPath = [Environment]::GetEnvironmentVariable('Path', [EnvironmentVariableTarget]::Machine)
if ($oldPath.Split(';') -inotcontains 'C:\minikube'){ `
  [Environment]::SetEnvironmentVariable('Path', $('{0};C:\minikube' -f $oldPath), [EnvironmentVariableTarget]::Machine) `
}

cmd> minikube start
cmd> minikube kubectl -- get po -A
NAMESPACE              NAME                                        READY   STATUS    RESTARTS        AGE
kube-system            coredns-64897985d-hwhgc                     1/1     Running   0               2d17h
kube-system            etcd-minikube                               1/1     Running   0               2d17h
kube-system            kube-apiserver-minikube                     1/1     Running   10 (112m ago)   2d17h
kube-system            kube-controller-manager-minikube            1/1     Running   0               2d17h
kube-system            kube-proxy-6cq9t                            1/1     Running   0               2d17h
kube-system            kube-scheduler-minikube                     1/1     Running   0               2d17h
kube-system            storage-provisioner                         1/1     Running   19 (105m ago)   2d17h
kubernetes-dashboard   dashboard-metrics-scraper-58549894f-qwp9k   1/1     Running   0               2d17h
kubernetes-dashboard   kubernetes-dashboard-ccd587f44-9gdfz        1/1     Running   15 (106m ago)   2d17h

cmd> minikube status
minikube
type: Control Plane
host: Running
kubelet: Running
apiserver: Running
kubeconfig: Configured
```
