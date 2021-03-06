## Docker
- **What?** 
  - This is tool for building/deploying/managing [Containers](/System-Design/Concepts/All_About_Containers/Container.md), ie This is 1 of container implementation. Others are Rocket, Drawbridge, LXC.
  - Container runtime.
- **Docker Inc.** is the company that sells the commercial version of Docker. Docker is also available as open source to which many individuals contribute.
- **[Docker file?](Docker_Files)**
- **Docker Images?** File system which composes/makes a docker container is called Image. These images are stored in ***Docker registry***.
- **Docker Registry** store house of docker images. Same as github,gitlab are for source code. Eg: Nexus, Artifact.

### Docker Architecture
<img src="https://i.ibb.co/Hz89jmJ/dc.png" width=500 />

  - **Docker Host** Machine on which the Docker containers run. It can be a virtual machine or a physical machine.

### Docker Compose
- **What** [Microservices](/System-Design/Concepts/MicroServices/What_is_Microservice.md) can contact other microservice using DC. DC uses yaml configuration file named *docker-compose.yml*. VMs are too heavy for microservices.
 ```bash
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
