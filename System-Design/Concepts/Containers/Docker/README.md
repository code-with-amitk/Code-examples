**Docker**
- Docker Terms
  - [Docker Host](#t1)
  - [Docker Image](#t2)
  - [Docker File](#t3)
  - [Docker Registry](#t4)
  - [Docker Compose](#t5)
- [Storing Data in Docker](#sd)
- [Docker Commands](#dcm)
- **Docker Networking**
  - [1. Bridge Networking](#bn)
    - [Example: Run 2 different Alpine containers on same docker host and commmunicate between them](#bn1)
  - [2. None Networking](#nn)
  - [3. Host Networking](#hn)
    - [Example: Nginx container binds directly to port 80 on the Docker host](#egn)
    
    
# Docker
- Docker is one of [container](../) implementation. Others are Rocket, Drawbridge, LXC.
- *Docker Inc.* is the company that sells the commercial version of Docker. Docker is also available as open source.
- **Docker Daemon / dockerd?** Manages Docker objects(Eg: Images, containers, networks, and volumes). dockerd also communicate with other daemons to manage Docker services.
- **Docker client / docker?** Users interact with docker client.
```c
  User 
$ docker run -----> [Docker Client]
                             --------------> [Docker Daemon/dockerd]
```
<a name=vs></a>
### Docker vs Kubernets
||Docker|Kubernets|
|---|---|---|
|What|Platform for developers|Container Orchestration system|
|Used for|To build,distribute applications in containers|Managing cluster of containers|
|Use case|Run containers on 1 host|Run containers on cluster of machines, providing scaling, self-healing, and rollback|

<a name=dterms></a>
### Docker Terms
<a name=t1></a>
#### Docker Host
Machine on which the Docker containers run. It can be a virtual machine or a physical machine.
<a name=t2></a>
#### Container Image/Docker Image 
This is used to start the container.
<a name=t3></a>
#### Docker File 
Shell script for creating Docker image/Container image.
```c
# vim application.Dockerfile 
FROM ubuntu:20.04                             //FROM Command: Installation is based image this OS, Since docker is not full OS.
RUN apt update \                              //RUN Command: Run some command
    apt-get install -y --no-install-recommends openssl \
    apt-get install -y --no-install-recommends iputils-ping \

COPY ./application.out ./a.txt /app/

CMD /app/application.out "--config" a.txt     //CMD Command: Start the application
```
<a name=t4></a>
#### Docker Registry
Stores docker images. Same as github,gitlab are for source code. Eg: dockerhub, elastic container registry(ecr)
<a name=t5></a>
#### Docker Compose
[Microservices](/System-Design/Concepts/MicroServices) can contact other microservice using DC. DC uses yaml configuration file.
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
<a name=t6></a>
#### [Docker Volume](https://docs.docker.com/storage/)


<a name=sd></a>
### Storing Data in Docker
- By Default, all files created inside a container are accessed only by that container. Data doesn’t persist when that container no longer exists.
- volumes, bind mounts, tmpfs all are seen as mounted directories to container.

||Volumes(shared directory on disk)|Bind Mounts|tmpfs(in memory/RAM)|
|---|---|---|---|
|Storage Type|Persistant|non persistant|non persistant|
|Data available after container stops|yes|no|no|
|How to create| a. `docker volume create` OR b. At container creation|||

#### 1. Volumes
- Volumes are stored on host filesystem which is managed by Docker (/var/lib/docker/volumes/ on Linux). Volumes are the best way to persist data in Docker.
- volumes stores the files on the host machine(so that the files are persisted even after the container stops)
#### 2. Bind mounts
#### 3. tmpfs

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
