## Kubernets
- **What?** Container scheduler for managing cluster of machines(physical or virtual).
- **Benefits of kubernets** Zero-downtime deployments, fault tolerance, high availability, scaling, scheduling, and self-healing are in Kubernetes.
    
## Options for Creating kubernets cluster

|Option|How|
|---|---|
|1.With Vagrant| Create few nodes with Vagrant (a tool for building and managing virtual machine environments in a single workflow)|
|2.With VirtualBox| Create a VirtualBox image that would have all the required software pre-installed|
|3.With Ansible|Use Ansible to run provisioning of those images also execute all the commands required to join VMs into a cluster|
|4.With Minikube|Minikube creates a 1-node cluster inside a VM on your laptop|

### MINIKUBE
- **1. Install & Start minikube Server** Install Virtual Box and enable Virtualization support from BIOS.
```bash
# vim /etc/yum.repos.d/virtualbox.repo
[virtualbox]
name=Fedora $releasever - $basearch - VirtualBox
baseurl=http://download.virtualbox.org/virtualbox/rpm/fedora/$releasever/$basearch
enabled=1
gpgcheck=0

# yum install VirtualBox-6.1 -y

# minikube version
# minikube start --vm-driver=virtualbox         //Create VM containing Docker, rkt container engines, localkube library
$ minikube status
host: Running
kubelet: Running
apiserver: Running
kubeconfig: Configured
# minikube stop|delete
# minikube dashboard                           //Minikube dashboard
```

<img src="https://i.ibb.co/MRF7WHt/Screenshot-from-2020-06-06-13-19-57.png" width=600 />

- **2. Install Minikube client & connect to server**
```bash
# curl -LO https://storage.googleapis.com/kubernetes-release/release/$(curl -s https://storage.googleapis.com/kubernetes-release/release/stable.txt)/bin/linux/amd64/kubectl
# chmod +x ./kubectl
# sudo mv ./kubectl /usr/local/bin/kubectl
# kubectl version
Client Version: version.Info{Major:"1", Minor:"18", GitVersion:"v1.18.3", GitCommit:"2e7996e3e2712684bc73f0dec0200d64eec7fe40", GitTreeState:"clean", BuildDate:"2020-05-20T12:52:00Z", GoVersion:"go1.13.9", Compiler:"gc", Platform:"linux/amd64"}
The connection to the server localhost:8080 was refused - did you specify the right host or port?

# eval $(minikube docker-env)                           //Connecting client with minikube server
```
