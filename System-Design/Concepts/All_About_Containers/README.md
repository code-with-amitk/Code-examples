- **Containers**
  - [What](#wc)
  - [Steps of Building a Container Image(also called docker image) & running application in container](#bc)
- **Docker**
  - [Docker Terms: Host, Image, File, Registry, Compose](#dterms)
  - [Docker Commands](#dcm)
  - **Docker Networking**
    - [1. Bridge Networking](#bn)
      - [Example: Run 2 different Alpine containers on same docker host and commmunicate between them](#bn1)
    - [2. None Networking](#nn)
    - [3. Host Networking](#hn)
      - [Example: Nginx container binds directly to port 80 on the Docker host](#egn)
- **Container Orchestration**
  - [Kubernets](#Kub)
    - [Kubernets Architecture](#ka) 
      - [Master Node](#mn)
      - [Worker Node](#wn)
        - [Pod](#pod)
        - [Namespaces](#ns)
    - [Configuring kubernets Cluster](#cfgk)
      - [Install/Upgrade service in cluster = Helm Chart](#ck1) 
    - [Commands](#kcmd)


# Container
<a name=wc></a>
### What is container?
This is a self contained package that contains everything that your binary/application need to run.
```c
    |-------------------------------------------------------------------------|
    | binary(*.exe), runtime(tokio-1.2), libraries(utc.so...), other packages |
    |----------------------------Container------------------------------------|
```
- Only 1 Application can run inside container and all its dependent libraries. Each container has its own: Network interface, IP address, file system, All containers share the kernel of the host.
- **Containerization** means Packaging software code and all its dependencies in a bundle.
- **Issue without containers?** When an company develops an S/W-Application, its tightly coupled with Libraries provided by particular OS Version. If OS update happens, libraries would get updated and Application may break, as it depends on particular OS version libraries.
- Isolated(Isolation is achieved using kernel namespace, [cgroups](/Operating_Systems/Linux/Resource_Control)) processes running on single host. Isolated from other processes.

<img src=TraditionalOS_vs_Containers.jpg width=400/>

<a name=bc></a>
### Steps of Building a [Container Image(also called docker image)](#dterms) & running application in container inside kubernets
- _1._ Get [dockerfile](#dterms) and Application to run
```c
# tar tvf application1.tgz
application1.Dockerfile      //See how file looks like below
application1.out
```
- _2._ Create a docker image
```c
# docker build . -f Application.Dockerfile --tag tag1   //--tag=<tag-name-of-image> <directory-name-where-docker-file-is-present>
````
- _3._ Store docker image created in step-2 to [Docker repository](#dterms)
```c
# docker tag tag1 artifactory/application-1/tag1
# docker push artifactory/application-1/tag1
```
- _4._ Deploy docker image into container. //Now Application1.out will start running.
```c
# docker container run artifactory/application-1/tag1
application1 initializing...
listening on port 453
application1 started
```
- _5._ Run contianer inside [kubernets](#Kub).

<img src=docker_image_to_container.PNG width=600/>

<a name=add></a>
**Advantages**
- *1. lightweight* Use less memory:* Simple web application running inside container takes 100MB space.
- *2. Secure:* Reduces the chance that malicious code present in one container impacting other containers or invade the host system.
- *3. Portable:* abstraction from the host operating system makes containerized applications portable ie able to run on any OS,VM.

**Disadvantages:** Some application may not be suited for a containerized environment. Ex: applications accessing low-level hardware information.

<a name=vs></a>
### Container vs VM
```c
                 Container   |     VM
-----------|-----------------|--------------------  
size       |    smaller      | Bigger wrt container
capability |    smaller      | big
What       | Pacakaged s/w   | Copy of OS 
```

<a name=doc></a>
# Docker
- Docker is one of [container](#con) implementation. Others are Rocket, Drawbridge, LXC.
- *Docker Inc.* is the company that sells the commercial version of Docker. Docker is also available as open source.
- **Docker Daemon / dockerd?** Manages Docker objects(Eg: Images, containers, networks, and volumes). dockerd also communicate with other daemons to manage Docker services.
- **Docker client / docker?** Users interact with docker client.
```c
  User 
$ docker run -----> [Docker Client]
                             --------------> [Docker Daemon/dockerd]
```

<a name=dterms></a>
### Docker Terms
- **Docker Host** Machine on which the Docker containers run. It can be a virtual machine or a physical machine.
- **Container Image/Docker Image:** This is used to start the container.
- **Docker File:** Shell script for creating Docker image/Container image.
```c
# vim application.Dockerfile 
FROM ubuntu:20.04                             //FROM Command: Installation is based image this OS, Since docker is not full OS.
RUN apt update \                              //RUN Command: Run some command
    apt-get install -y --no-install-recommends openssl \
    apt-get install -y --no-install-recommends iputils-ping \

COPY ./application.out ./a.txt /app/

CMD /app/application.out "--config" a.txt     //CMD Command: Start the application
```
- **Docker Registry:** Stores docker images. Same as github,gitlab are for source code. Eg: dockerhub, elastic container registry(ecr)
- **Docker Compose** [Microservices](/System-Design/Concepts/MicroServices) can contact other microservice using DC. DC uses yaml configuration file.
 ```yaml
 $ cat docker-compose.yml
 version: '3'
services:
  common:                                   // is a web application that is supposed to deliver common artifacts.
    build: ../scs-demo-esi-common/
  order:                                   //is a web application for processing orders.
    build: ../scs-demo-esi-order
  varnish:                                //is a web cache to coordinate the two web applications.
    build: varnish
    links:
     - common
     - order
    ports:
     - "8080:8080"
```

<a name=dn></a>
## Docker Networking
Connecting Docker Containers with each other and with outside world. Docker’s networking subsystem is pluggable using drivers forming networks.
- **Types of Docker Networking**
```c
      Network      |        Description
-------------------|-----------------------------
  1.Bridge         |  default network driver
  2.Host           |  Use Host Networking
  3.Overlay        |  Containers running on **different Docker hosts** want to communicate OR when multiple applications work together using swarm services
  4.macvlan        |  Assign a MAC address to a container, making it appear as a physical device
  5.None           |  disable all networking. This is not available for swarm services.
  6.Network Plugins|  Integrate Docker with specialized network stacks/3rd party stacks.
```

<a name=bn></a>
### 1. Bridge Networking
This is default network driver. Used when multiple containers want to communicate on the **same Docker host**.
- **Types of Bridge**
```c
                    User Defined          |         Default Bridge
----------|-------------------------------|-----------------------------------
What      | Can only connect using        | This is created by default, but its better to use user defined bridge
            IP Address or hostname          Can only connect using IP Address.
Isolation | provides a scoped network in  | Not better
            which only containers attached 
            to that network are able to 
            communicate
```

<a name=bn1></a>
##### Example: Run 2 different [Alpine containers](https://hub.docker.com/_/alpine#:~:text=Alpine%20Linux%20is%20a%20Linux,than%20other%20BusyBox%20based%20images.&text=Read%20more%20about%20Alpine%20Linux,at%20home%20with%20Docker%20images) on same docker host and commmunicate between them
```c
////Overall Pictutre
    Container-1(172.17.0.2)
    Container-2(172.17.0.3)
                    Bridge(172.17.0.1)                    
    Docker host


1. Start Docker desktop. Start Windows Powershell and list the network.

ps> docker network ls

NETWORK ID      NAME       DRIVER     SCOPE
17e324f45964    bridge     bridge     local   //Default bridge network
6ed54d316334    host       host       local
7092879f2cc8    none       null       local

$ docker run -dit --name alpine1 alpine ash   //2. Start 2 alpine containers, running ash(This is default alpine shell rather than bash).
$ docker run -dit --name alpine2 alpine ash

$ docker container ls                        //3. Check containers have started or not?
CONTAINER ID        IMAGE      COMMAND     CREATED          STATUS             PORTS        NAMES
602dbf1edc81        alpine     "ash"       4 seconds ago    Up 3 seconds                   alpine2
da33b7aa74b0        alpine     "ash"       17 seconds ago   Up 16 seconds                  alpine1

$ docker network inspect bridge              //4. Check Brigde network to see to what containers are connected to?

[
    {
        "Name": "bridge",
        "Id": "17e324f459648a9baaea32b248d3884da102dde19396c25b30ec800068ce6b10",
        "Created": "2017-06-22T20:27:43.826654485Z",
        "Scope": "local",
        "Driver": "bridge",
        "EnableIPv6": false,
        "IPAM": {
            "Driver": "default",
            "Options": null,
            "Config": [
                {
                    "Subnet": "172.17.0.0/16",
                    "Gateway": "172.17.0.1"         //Gateway between docker host and Bridge N/W
                }
            ]
        },
        "Internal": false,
        "Attachable": false,
        "Containers": {
            "602dbf1edc81813304b6cf0a647e65333dc6fe6ee6ed572dc0f686a3307c6a2c": {
                "Name": "alpine2",
                "EndpointID": "03b6aafb7ca4d7e531e292901b43719c0e34cc7eef565b38a6bf84acf50f38cd",
                "MacAddress": "02:42:ac:11:00:03",
                "IPv4Address": "172.17.0.3/16",
                "IPv6Address": ""
            },
            "da33b7aa74b0bf3bda3ebd502d404320ca112a268aafe05b4851d1e3312ed168": {
                "Name": "alpine1",
                "EndpointID": "46c044a645d6afc42ddd7857d19e9dcfb89ad790afb5c239a35ac0af5e8a5bc5",
                "MacAddress": "02:42:ac:11:00:02",
                "IPv4Address": "172.17.0.2/16",
                "IPv6Address": ""
            }
        },
        "Options": {
            "com.docker.network.bridge.default_bridge": "true",
            "com.docker.network.bridge.enable_icc": "true",
            "com.docker.network.bridge.enable_ip_masquerade": "true",
            "com.docker.network.bridge.host_binding_ipv4": "0.0.0.0",
            "com.docker.network.bridge.name": "docker0",
            "com.docker.network.driver.mtu": "1500"
        },
        "Labels": {}
    }
]

$ docker attach alpine1                         //5. Since containers are running in background. Run attach command to connect to container.

/ # ip addr show      //list IP Address
# ping google.com     //Connected to internet
PING google.com (172.217.3.174): 56 data bytes
64 bytes from 172.217.3.174: seq=0 ttl=41 time=9.841 ms
64 bytes from 172.217.3.174: seq=1 ttl=41 time=9.897 ms

# ping 172.17.0.3     //Ping another container
PING 172.17.0.3 (172.17.0.3): 56 data bytes
64 bytes from 172.17.0.3: seq=0 ttl=64 time=0.086 ms
64 bytes from 172.17.0.3: seq=1 ttl=64 time=0.094 ms

//7. Detach from alpine1 without stopping it by using the detach sequence, CTRL + p CTRL + q (hold down CTRL and type p followed by q). 
//8. Stop and remove both containers

$ docker container stop alpine1 alpine2
$ docker container rm alpine1 alpine2
```

<a name=dcm></a>
### [Docker commands](https://docs.docker.com/engine/reference/commandline/docker/)
```
$ docker
  -d: start the container detached (in the background)
  -i: Interactive, (with the ability to type into it)
  --network host: Start host driver
  --rm: remove the container once it exits/stops. 
  -t: With tty
```

### 2. None Networking
This completely disables the networking stack on the container. Within the container, only the loopback device is created. Example:
```c
$ docker run --rm -dit  --network none  --name no-net-alpine   alpine:latest   ash

//Check the container’s network stack... no eth0 created
$ docker exec no-net-alpine ip link show
1: lo: <LOOPBACK,UP,LOWER_UP> mtu 65536 qdisc noqueue state UNKNOWN qlen 1
    link/loopback 00:00:00:00:00:00 brd 00:00:00:00:00:00
2: tunl0@NONE: <NOARP> mtu 1480 qdisc noop state DOWN qlen 1
    link/ipip 0.0.0.0 brd 0.0.0.0
3: ip6tnl0@NONE: <NOARP> mtu 1452 qdisc noop state DOWN qlen 1
    link/tunnel6 00:00:00:00:00:00:00:00:00:00:00:00:00:00:00:00 brd 00:00:00:00:00:00:00:00:00:00:00:00:00:00:00:00
    
//Stop the container. It is removed automatically because it was created with the --rm flag
$ docker stop no-net-alpine    
```

<a name=hn></a>
### 3. Host Networking
[Container's](#con) network stack is same as host network stack. IP Address of container is same as host OS. Useful in situtation where container needs to listen/read/write on large number of ports.
- **Advantages**
  - *1.* Expose 1 port and IP access the service. Example: 50 Game servers are running in Docker containers on same host. Requests are routed using [kubernets](/System-Design/Concepts/All_About_Containers/Container_Orchestration) to free game server.
- **Disadvantages:** Host networking driver only work on linux not on Windows and MAC. 
 
<a name=egn></a>
#### Example: Nginx container binds directly to port 80 on the Docker host
Start ngnix in container with host networking, ngnix listens on port 80 which is same as docker host.
```c
# docker run --rm -d --network host --name my_nginx nginx         //Create and start container as detached process
# ip addr show 
# sudo netstat -tulpn | grep :80                                  //Check which process is binded to port 80.
# docker container stop my_nginx                                  //Stop the container, it will be removed automatically since start with -rm switch
```

# Container Orchestration
**Orhestration?** Managing the lifecycles of containers. These are GUI/tools to automate following tasks: Deployment, Scaling up/down, Movement of containers from one host to another, Load balancing, Health monitoring.
  - *Examples of Container Orhestrators:* Kubernets, Docker swarm, Nomad

<a name=kub></a>
## Kubernets
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
### Kubernets Architecture
```c

User               |------MASTER_NODE--------|      |--------WORKER_NODE-1 ---|
   --*.yaml-->     |Controller  API_service <--------> Kubelet Kubectl_Proxy------> Worker_Node-2
                   |                         |      |                  |----------> Worker_Node-3
                   |Scheduler     etcd       |      | docker                  |
                   |-------------------------|      |     |------POD------|   |
                                                    |     | container1    |   |
                                                    |     | container2    |   |
                                                    |     |---------------|   |
                                                    |-------------------------|
```
<a name=mn></a>
#### A. Master Node
- User Intercts with Master node(using yaml file). Master node create/destroy worker nodes.
- **Daemon in master node**
  - *1. Controller Manager:* Monitors created containers/worker nodes. When worker node finishes the task(or load on cluster is low). VM/Worker node is bought down and when load becomes high a new worker node/VM is spawned again.
  - *2. API Service:* Manages all communication with Worker nodes(using kubelet)
  - _3. Scheduler:_ For placing pods across nodes to balance resource consumption.
  - 4. _etcd:_ Database that hosts cluster state information.

<a name=wn></a>
#### B. Worker Node
- handles workload. Worker nodes hosts [PODS](#pod). 1 Pod can contain 1 or more [containers](#con).
- **Daemons in worker node:** *1. Kubelet:* Process for communication with master, *2. [Docker](#doc):* A container runtime, *3. Kube Proxy:* for communication with other nodes in cluster.

<a name=pod></a>
##### POD 
- Complete package which Kubernets creates to install application on Worker Node. Pod can contain multiple containers(application). Pods run in isolated pvt enviornment. Memory is allocated to Pods using [Volumes](/Operating_Systems/Linux/Partitions_Mounting).
- Pod Contains: 
  - *1.* Container(Eg: [Docker](#doc))
  - *2.* Shared storage, as Volumes
  - *3.* Networking, as a unique cluster IP address,port,  *4.* other Information 

<img src=kubernets_pod_worker_node.png width=400>

<a name=ns></a>
##### Namespaces
- Collection of pods ie Virtual clusters inside kubernets cluster. Multiple pods can run inside a namespace.
- 3 predefined namespaces:
  - _a. Default_ 
  - _b. Kube-system:_ resources created by kubernets
  - _c. Kube-public:_ reserved for future
```c
$ kubectl create namespace test                       //Creating new namespace
$ kubectl --namespace=test  run ngnix --image=nginx   //Deploy namespace
```

<a name=cfgk></a>
### Configuring kubernets Cluster(1 master, n workers)
```c
//////////////1. Configuration file for deploying 2 containers/pods. Containers hainvg ngnix image.////////////////
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

////////////2. Create container(ie pod) using kubectl command////////////////////
$ kubectl apply -f test.yaml

//////////////1. Install kubernets master, worker nodes///////////////////////////////
$ install
$ minikube version                                          //Check version
  minikube version: v1.8.1
$ minikube start                                            //Start minikube kubernets cluster
$ kubectl version
  Client Version: version.Info{Major:"1", Minor:"17"...}    //Worker node version
  Server Version: version.Info{Major:"1", Minor:"17",..}    //Master node version
$ kubectl get nodes                                         //How many nodes are in kubernetes cluster
NAME       STATUS   ROLES    AGE   VERSION
minikube   Ready    master   2m    v1.17.3

///////////////2. Deploy Application on cluster/////////////////////////////
//Run command on Master Node. This will create Application=amit-app on any of available worker node/VM
$ kubectl create deployment amit-app --image=gcr.io/google-samples/kubernetes-bootcamp:v1
  deployment.apps/amit-app created

$ kubectl get deployments.apps 
NAME                  READY   UP-TO-DATE   AVAILABLE   AGE
amit-app              1/1     1            1           111s
kubernetes-bootcamp   1/1     1            1           3m19s

///////////////3. Check Pods and worker nodes///////////////////////////////////
$ kubectl get pods
$ kubectl describe pods
$ kubectl proxy                               //Note, pods run on pvt network hence proxy is needed to communicate with them.

$ systemctl start apache                      //Start Application inside container
```

<a name=ck1></a>
#### 1. Install/Upgrade Service in Cluster using Helm Chart
- _1. Create a helm chart for applicaton:_ 
  - **Helm chart:** This is collection of yaml files which contains configuration,installation information for service. Files present in helm chart
```c
mychart/
  Chart.yaml                  //Contains meta information of this chart
  value.yaml                 //Contains default values for this chart, to be used by templated files
  templates/
    configmap.yaml       
    deployment.yaml
    ...
  
$ cat chart.yaml                      
apiVersion: v2
appVersion: 1.1
maintainers:
- email: amit@google.com
  name: Amit
name: app
type: application
version: 1.0

$ cat values.yaml                      
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

$ cat configmap.yaml                    //Information related to configuration
apiVersion: v1
kind: ConfigMap
metadata:
  name: app1-config
  labels:
    app: {{ .Values.image.app }}        //Take value from values.yaml
```
- _2. Install/upgrade/rollback application using helm chart_
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
