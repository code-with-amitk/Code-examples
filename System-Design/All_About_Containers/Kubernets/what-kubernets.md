## Kubernets?
  - Container scheduler for managing cluster of machines(physical or virtual). These hosts runs containers. 
  - kubernets controls the resources inside multi container applications how they interconnect.
  - **Benefits of kubernets**
    - Zero-downtime deployments, fault tolerance, high availability, scaling, scheduling, and self-healing are in Kubernetes.
    
## Creating kubernets cluster
  - **Options**
    1. create a few nodes with Vagrant (a tool for building and managing virtual machine environments in a single workflow) 
    2. create a VirtualBox image that would have all the required software pre-installed
    3. use Ansible to run provisioning of those images also execute all the commands required to join VMs into a cluster
    4. Using ***Minikube***:
      - Minikube creates a 1-node cluster inside a VM on your laptop. 

### Working with Minikube

- Installation
'''
# curl -LO https://storage.googleapis.com/kubernetes-release/release/$(curl -s https://storage.googleapis.com/kubernetes-release/release/stable.txt)/bin/linux/amd64/kubectl
# chmod +x ./kubectl
# sudo mv ./kubectl /usr/local/bin/kubectl
'''

-Verification
```
# kubectl version
Client Version: version.Info{Major:"1", Minor:"18", GitVersion:"v1.18.3", GitCommit:"2e7996e3e2712684bc73f0dec0200d64eec7fe40", GitTreeState:"clean", BuildDate:"2020-05-20T12:52:00Z", GoVersion:"go1.13.9", Compiler:"gc", Platform:"linux/amd64"}
The connection to the server localhost:8080 was refused - did you specify the right host or port?
```
