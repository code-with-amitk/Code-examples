# Kubernets Architecture

## Master Node
- master node is responsible for Creating/destroying worker nodes/VMs. 
- Master node has following daemons.
### 1. Controller
- **What?** Monitors created containers/worker nodes. When worker node finishes the task(or load on cluster is low). VM/Worker node is bought down and when load becomes high a new worker node/VM is spawned again.
### 2. API Service
- **What?** Manages all communication with Worker nodes(using kubectl)

  

## Worker Node
## 1. Kubectl
- **What?** Daemon on worker node responsible for interating with Master node.
```bash

<---------------master Node---------------->              <---------Worker Node--------------->
  Controller   API-Service                                  kubectl
                  /\                                            /\
                   |--------------------------------------------|
```
  
