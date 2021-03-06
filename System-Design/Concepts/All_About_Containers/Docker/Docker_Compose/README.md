## Docker Compose
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
