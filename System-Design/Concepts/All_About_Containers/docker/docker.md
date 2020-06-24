## DOCKER
- **What**
  - Docker is an open source tool for building, deploying & managing containerized applications.
  - Container is sepearte OS for single process. ie Only one process is supposed to run in one Docker container. Only as much of OS is needed as is needed to run that process.
    - Distributions like Alpine Linux, which are just a few megabytes in size, only contain the most important tools, making them an ideal basis for Docker containers
  - `Docker Inc.` is the company that sells the commercial version of Docker. Docker is also available as open source to which many individuals contribute.
  - Docker provides a lightweight alternative to VM. Although Docker does not provide as much isolation as a virtualization, it is practically as lightweight as a process.
- **Why**
  - We can create containers without Docker but Docker makes it easier, simpler, and safer to build, deploy, and manage containers.
- **Docker Images**
  - File system which composes/makes a docker container is called Image. These images are stored in ***Docker registry***.
  - Creation of Docker images is done using files named ***docker file*** described below.
- **Docker Registry**
  - store house of docker images. Same as github,gitlab are for source code. Eg: Nexus, Artifact.
- **Comparison**

| | Docker | VM |
| --- | --- | --- |
| Kernel | shares kernel of OS | Each host has its own |
| Network Interface | seperate for each docker container | seperate | 
| No of units | 100's of dockers can be started on 1 laptop | 3-4 max |
| Overhead | less wrt VM | More |
| Processes | 1 process per container | All processes in 1 VM |

### DOCKER ARCHITECTURE
![ImgUrl](https://i.ibb.co/Hz89jmJ/dc.png)
  - **Docker Host** Machine on which the Docker containers run. It can be a virtual machine or a physical machine.
  - **Contianers**
    - Contains processes
    - Each container has its own network interface with its own IP address
    - Each container has its own file system.
    - All Docker containers share the kernel of the Docker host
    
### DOCKER FILES
  - The creation of Docker images is done via files named Dockerfile(which are easy to write).
  - This is bascically a shell scriting for installing the s/w.
```
FROM openjdk:11.0.2-jre-slim                            //base image on which the installation is based
COPY target/customer.jar .                              //copies files in the Docker image
CMD /usr/bin/java -Xmx400m -Xms400m -jar customer.jar   //what happens when the Docker container is started
EXPOSE 8080                                             //Port on which docker is available
```
  - Building docker image
```
# docker build --tag=<tag-name-of-image> <directory-name-where-docker-file-is-present>    //docker is command line tool
```

### DOCKER COMPOSE
  - **What** Microservices can contact other microservice using DC.
  - **How** Docker Compose configures the interaction of the Docker containers with a YAML configuration file named ***docker-compose.yml***
 ```
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
  
### DOCKER FOR MICROSERVICES, VMs are too heavy for MS
  - Microservices as separately deployable units(we can think them as Processes).
  - All processes/microservices should run in a cluster on different machine, because If all processes run on one server, then only a limited amount of hardware resources are available.
  - Kubernetes and Cloud Foundry support running microservices in a cluster.
  - **VMs are too heavy for MS**
    - Each microservice has its own instance of the operating system. This consumes a lot of memory in the RAM.
  - **Solution**
    - ideal solution would be a lightweight alternative to of VM, which has isolation of virtual machines, but consumes as little resources as processes do and easy to operate
