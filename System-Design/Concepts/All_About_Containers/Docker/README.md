## Docker
- [What_is_Docker](#What_is_Docker)
  - [Docker_Architecture](#Docker_Architecture)
  - [Advantages](#Advantages)
- [Docker_Terms](#Docker_Terms)
  - [Docker_Host](#Docker_Host)
  - [Docker_Image](#Docker_Image)
  - [Docker_File](#Docker_File)
  - [Docker_Registry](#Docker_Registry)
  - [Docker_Compose](#Docker_Compose)
- [Install_Docker_Run_Container](#Install_Docker_Run_Container)
- [How_Containers_communicate_with_eachother_and_outside_world](#How_Containers_communicate_with_eachother_and_outside_world)

## What_is_Docker 
- This is tool for building/deploying/managing [Containers](../Containers), ie This is 1 of container implementation. 
- Others are Rocket, Drawbridge, LXC. Docker is Container runtime. 
- **Docker Inc.** is the company that sells the commercial version of Docker. Docker is also available as open source.

#### Docker_Architecture
- **Docker Daemon / dockerd?** Manages Docker objects(Eg: Images, containers, networks, and volumes). dockerd also communicate with other daemons to manage Docker services.
- **Docker client / docker?** Users interact with docker client.
```
  User 
$ docker run -----> [Docker Client]
                             -----------------> [Docker Daemon/dockerd]
```
#### Advantages
- *1. Nothing break at client side due to mistached libraries* All developers work and deliver in standardized and freezed enviornment. Same libraries and build is delivered to client.
- *2. No special hardware requirements* Docker containers can run on a developer’s local laptop, on physical or virtual machines in a data center, on cloud providers, or in a mixture of environments.
- *3. Running more workloads at same hardware.* 2 builds can run parallely on 2 containers on same host.


## Docker_Terms
### Docker_Host 
- Machine on which the Docker containers run. It can be a virtual machine or a physical machine.

### Docker_Image
- Image is a read-only template with instructions for creating a Docker container. Often, an image is based on another image, with some additional customization. 
- We can create our own images or use those created by others and published in a registry.
- Docker image is created using **Docker File**

### Docker_File
- Creation of Docker images is done using docker files.
- This is shell script for installing the s/w.
```bash
FROM openjdk:11.0.2-jre-slim                            //base image on which the installation is based
COPY target/customer.jar .                              //copies files in the Docker image
CMD /usr/bin/java -Xmx400m -Xms400m -jar customer.jar   //what happens when the Docker container is started
EXPOSE 8080                                             //Port on which docker is available
```
- Building docker image
```bash
# docker build --tag=<tag-name-of-image> <directory-name-where-docker-file-is-present>    //docker is command line tool
```

### Docker_Registry
- **What?** Stores docker images hub.docker.com. Same as github,gitlab are for source code.

## Docker_Compose
- **What** [Microservices](/System-Design/Concepts/MicroServices) can contact other microservice using DC. DC uses yaml configuration file.
 ```bash
 # cat docker-compose.yml
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

## Install_Docker_Run_Container
**Install**
- *1.* Download Docker Installer from https://hub.docker.com/.
- *2.* Check Hyper-V and Containers Windows features must be enabled.
- *3.* Add your username to docker-users group. Local Users and Groups > Groups > docker-users. Restart Computer. Done

**Running Container**
- *1.* Start docker from desktop. It will present a CLI. 
```c
$ cd C:/Users/amit/
```
- *2.* Clone the tutorial repo to build the docker image. 
```c
$git clone https://github.com/docker/getting-started.git
```
- *3.* Build the Docker Image.  
```c
$ cd getting-started; docker build -t docker101tutorial .
```
- *4.* Start the [Container](../../Containers) based on image build in step-3. 
```c
$ docker run -d -p 80:80 -name docker-tutorial docker101tutorial`
```

## [How_Containers_communicate_with_eachother_and_outside_world](Docker_Networking)
