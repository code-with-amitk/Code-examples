**Container Orchestration**
- [Kubernets](#Kub)
  - [Kubernets Architecture](#ka) 
    - [Master Node](#mn)
    - [Worker Node](#wn)
      - [Pod](#pod)
      - [Namespaces](#ns)
  - Kubernets Terms
    - [configmap](#cm)
  - [Configure kubernets Cluster](#cfgk)
  - [Helm Chart](#hc)
    - [1. chart.yaml.j2](#h1)
    - [2. Values.yaml.j2](#h2)
    - [3. configmap-jams.yaml](#h3)
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
- handles workload. Worker nodes hosts [PODS](#pod). 1 Pod can contain 1 or more [containers](#con).
- **Daemons in worker node:** *1. Kubelet:* Process for communication with master, *2. [Docker](#doc):* A container runtime, *3. Kube Proxy:* for communication with other nodes in cluster.

<a name=pod></a>
#### POD 
- Complete package which Kubernets creates to install application on Worker Node. Pod can contain multiple containers(application). Pods run in isolated pvt enviornment. Memory is allocated to Pods using [Volumes](/Operating_Systems/Linux/Partitions_Mounting).
- Pod Contains: 
  - *1.* Container(Eg: [Docker](#doc))
  - *2.* Shared storage, as Volumes
  - *3.* Networking, as a unique cluster IP address,port,  *4.* other Information 

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
<a name=cm></a>
### Configmap
This is the configuration file that stores the configuration used by [POD](#ka)
#### Creating a configmap from File
```c
# cat test.properties
name=Amit
age=25
life=Great
worry=None

# kubectl create configmap amit-configmap --from-file=test.properties   //Create configmap
# kubectl get configmaps amit-configmap -o yaml                         //View configmap
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

<a name=cfgk></a>
## Configure kubernets Cluster(1 master, n workers)
#### a. Configuration file for deploying 2 containers. Containers having ngnix image.
```c
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

<a name=ck1></a>
## Helm Chart
**What?** This is collection of yaml files which contains configuration,installation information for service. HC is used to install/upgrade service in cluster. Files in HC:
```c
mychart/
  Chart.yaml.j2
  values.yaml.j2
  templates/
    configmap-jams.yaml       
    deployment.yaml
    ...
```
<a name=h1></a>
#### 1. Chart.yaml.j2           //Contains meta information of this chart
```c
$ cat chart.yaml.j2
apiVersion: v2
appVersion: 1.1
maintainers:
- email: amit@google.com
  name: Amit
name: app
type: application
version: 1.0
```
<a name=h2></a>
#### 2. Values.yaml.j2          //Contains default values for this chart, to be used by templated files
```c
$ cat values.yaml.j2                      
chart:
  name: app1
image:
  repository: artifactory-path
  version: "1.0"
  name: app1
  dbTag: 1.1.lmaslmd
database:
  enabled: true
  host: test.abc.com
  user: admin
  password: Passw0rd
  sslmode: require
k8sServices:
  service1_url: https://service1:9091
  service2_url: https://service2.serv:9091
```
<a name=h3></a>
#### 3. configmap-jams.yaml                    //Information related to configuration of this service
```c
$ cat configmap-jams.yaml
apiVersion: v1
kind: ConfigMap
metadata:
  name: jams-config
  labels:
    app: {{ .Values.image.app }}        //Take value from values.yaml
data:
  
```
### Install/upgrade/rollback application using helm chart_
```c
$ helm install app1{chartname}
$ helm upgrade app1{chartname}      //Upgrade the microservice instead of install
$ helm rollback app1{chartname}     //rollback to older version
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
```
