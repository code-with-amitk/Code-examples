- **Kubernets cluster is 1 master and multiple worker nodes.**

## Entities in Kubernets Architecture
### A. Master Node
- This is responsible for Creating/destroying worker nodes/VMs. Worker nodes runs containerized applications.
- Master node has following daemons.
  - **1. Controller:** Monitors created containers/worker nodes. When worker node finishes the task(or load on cluster is low). VM/Worker node is bought down and when load becomes high a new worker node/VM is spawned again.
  - **2. API Service:** Manages all communication with Worker nodes(using kubelet)

### B. Worker Machine/Node
- This is Physical or VM on which containerized applications run. Every Worker is managed by master. 
- Master handles scheduling pods(See Below) inside worker nodes after looking at available resources on each node.
- Worker has following daemons.
  - **1. Kubelet:** Process for communication with master.
  - **2. [Docker](/System-Design/Concepts/All_About_Containers/Docker):** A container runtime.
  - **3. Kubectl Proxy:** Does communication with other nodes in cluster.

### C. User
- User can only ineracts with master node using YAML(yet another markup language), which defines how many applications,replicas to be run etc.
- 
### Diagram
```bash

    User(application.yaml)
                  |                                                                            Worker-Node1
                  |                                                                                  /\
                 \/                                                                                   |
<---------------Master Node---------------->              <---------Worker Node--------------->       |
  Controller   API-Service                                  kubelet     kubectl-Proxy                 |
                  /\                                            /\          /\                        |
                   |--------------------------------------------|            |------------------------|------>worker node2
```
  
### Terms
- **1. POD**
  - This is a Complete package which Kubernets creates to install application on Worker Node. Pod can contain multiple applications. Pods run in isolated pvt enviornment. Pod Contains:
    - *1.* Container(Eg: [Docker](/System-Design/Concepts/All_About_Containers/Docker))
    - *2.* Shared storage, as Volumes
    - *3.* Networking, as a unique cluster IP address
    - *4.* Information about how to run each container, such as the container image version or specific ports to use

<img src=./kubernets_pod_worker_node.png width=1000 />
