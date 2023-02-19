- [Docker vs Kubernets](/System-Design/Concepts/Containers/Docker/README.md#vs)
- [Kubernets Architecture](#ka) 
  - [Master Node](#mn)
  - [Worker Node](#wn)
    - [Pod](#pod)
- [Terms: configMap, Objects(kind: service, kind: Role, kind: configmap, namespace](Terms)
- [Installing Kubernets](Install_Kubernets)
- Commands
  - [namespace](#ns)
  - [services](#svc)
  - [Pods](#p)


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
<img src=images/kubernets_architecture3.png width=1200/>

<a name=mn></a>
### A. Master Node / Control Plane
- User Intercts with Master node(using yaml file). Master node create/destroy worker nodes.
#### Daemon in master node
- **1. API Server:** Manages all communication with Worker nodes(using kubelet).
- **2. etcd `<key,value>` store:** Stores state of kubernets cluster.
- **3. Scheduler:** Schedules pods to run on worker nodes.
- **4. Controller Manager:** Runs controllers that monitors state of cluster and maintains desired state.
  - _Replication Controller:_ Manages replication sets.
  - _Node Controller:_ Monitor health of worker nodes.
- **5. Add-ons:** Provides additional functionality.

<a name=wn></a>
### B. Worker Node
- handles workload. Worker nodes hosts [PODS](#pod). 1 Pod can contain 1 or more [containers, Eg: docker](#doc).
#### Daemon in Worker node
- **1. Kubelets:** Recieves instructions from master node to run/manage container.
- **2. Container Runtime:** This actually runs the container. Several runtimes kubernets supports:
  - Docker
  - containerd
  - CRI-O
- **3. Kube-proxy:** for communication with other nodes in cluster
- **4. Add-Ons:** Additional functionality.
- **5. Node status & Meta-data:** Each worker node maintains meta-data about itself. Example:
  - IP Address, hostname
  - Current status (Ready, Not Ready, Out of Disk space etc)

<a name=pod></a>
#### POD 
- POD is smallest deployable unit in kubernets.
- Each POD has its own:
  - IP & namespace.
- Containers in POD share resources and can communicate using 'localhost'.
- Complete package which Kubernets creates to install application on Worker Node. 
- Memory is allocated to Pods using [Volumes](/Operating_Systems/Linux/Partitions_Mounting).


<a name=kcmd></a>
### Kubernets commands (kubectl -h)
<a name=ns></a>
#### namespace
```c
# kubectl get namespaces    //Get all namespaces on node
NAME              STATUS   AGE
default           Active   4d8h
keycloak          Active   3d22h
kube-node-lease   Active   4d8h
kube-public       Active   4d8h
kube-system       Active   4d8h
```

<a name=svc></a>
#### Services
```c
# kubectl get pods --namespace=default          //Services inside namespace

# kubectl get pods                              //All services
```

<a name=p></a>
#### PODS
```c
# kubectl get pods --namespace=default          //Pods inside namespace

$ kubectl get pods -A                             //List all pods

$ kubectl get pods -A | grep kafka                //All pods named kafka*

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
