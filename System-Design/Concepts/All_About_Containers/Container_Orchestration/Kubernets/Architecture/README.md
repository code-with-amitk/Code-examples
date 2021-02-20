## Kubernets Architecture

### 1. Master Node
> Master node has following daemons.
#### 1. Controller
- **What?** Monitors created containers/worker nodes. When worker node finishes the task(or load on cluster is low). VM/Worker node is bought down and when load becomes high a new worker node/VM is spawned again.
- *Responsibilites?**
  - Creating/destroying worker nodes/VMs.
  


```bash

<---------------master Node---------------->              <---------Worker Node--------------->
  Controller  

```
  
