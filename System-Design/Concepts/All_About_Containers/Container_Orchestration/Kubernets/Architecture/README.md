## Kubernets Architecture
### Master Node
- master node is responsible for Creating/destroying worker nodes/VMs. 
- Master node has following daemons.
- **1. Controller**
  - **What?** Monitors created containers/worker nodes. When worker node finishes the task(or load on cluster is low). VM/Worker node is bought down and when load becomes high a new worker node/VM is spawned again.
- **2. API Service**
  - **What?** Manages all communication with Worker nodes(using kubectl)
  - **Other?** This will automatically create an endpoint for each pod, based on the pod name, that is also accessible through the proxy.

### Worker Node
- **1. Kubectl**
  - **What?** Daemon on worker node responsible for interating with Master node using API Service.
- **2. Kubectl Proxy**
  - **What?** Does communication with other nodes in cluster.

### Diagram
```bash

                                                                                                Worker-Node
                                                                                                     /\
                                                                                                      |
<---------------Master Node---------------->              <---------Worker Node--------------->       |
  Controller   API-Service                                  kubectl     kubectl-Proxy                 |
                  /\                                            /\          /\                        |
                   |--------------------------------------------|            |------------------------|
```
  
### Terms
- **1. POD**
  - This is a Complete package which Kubernets create install application on Worker Node. Pod Contains:
    - *1.* Container(Eg: [Docker]()
