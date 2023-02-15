- [Docker vs Kubernets](/System-Design/Concepts/Containers/Docker/README.md#vs)
- [Kubernets Architecture](#ka) 
  - [Master Node](#mn)
  - [Worker Node](#wn)
    - [Pod](#pod)
- [Terms: configMap, Objects(kind: service, kind: Role, kind: configmap, namespace](Terms)
- [Installing Kubernets](Install_Kubernets)
- [Commands](#kcmd)


## Kubernets: Container Orchestrator
**Orhestration?** Managing the lifecycles of containers. These are GUI/tools to automate following tasks: Deployment, Scaling up/down, Movement of containers from one host to another, Load balancing, Health monitoring.
- *Examples of Container Orhestrators:* Kubernets, Docker swarm, Nomad
- Kubernets Cluster has different microservices inside it.
```c
  <--------------------k8s cluster----------------------------------->
    |----control-plane,master-------|   |---------Worker node-----|
    | micro_service1                |   |micro_service2           |
    |               micro_service4  |   |       micro_servicen    |
    |-------------------------------|   |-------------------------|
```

<a name=ka></a>
## Kubernets Architecture
<img src=images/kubernets_architecture.JPG width=800/>

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
