## Kubernets?
  - Container scheduler for managing cluster of machines(physical or virtual). These hosts runs containers. 
  - kubernets controls the resources inside multi container applications how they interconnect.
  - **Benefits of kubernets**
    - Zero-downtime deployments, fault tolerance, high availability, scaling, scheduling, and self-healing are in Kubernetes.
    
## Options for Creating kubernets cluster
1. create a few nodes with Vagrant (a tool for building and managing virtual machine environments in a single workflow) 
2. create a VirtualBox image that would have all the required software pre-installed
3. use Ansible to run provisioning of those images also execute all the commands required to join VMs into a cluster
4. Using ***Minikube***:
  - Minikube creates a 1-node cluster inside a VM on your laptop. 

### Working with Minikube

#### Minikube server installation
- Install Virtual Box from [here](https://www.virtualbox.org/wiki/Linux_Downloads) and enable Virtualization support from BIOS. OR Install VirtualBox like this
```
# vim /etc/yum.repos.d/virtualbox.repo
[virtualbox]
name=Fedora $releasever - $basearch - VirtualBox
baseurl=http://download.virtualbox.org/virtualbox/rpm/fedora/$releasever/$basearch
enabled=1
gpgcheck=1
repo_gpgcheck=1
gpgkey=https://www.virtualbox.org/download/oracle_vbox.asc

 yum install VirtualBox-6.1 -y
```
- Install, start, verify minikube.
```
# curl -Lo minikube https://storage.googleapis.com/minikube/releases/latest/minikube-linux-amd64 && chmod +x minikube && sudo mv minikube /usr/local/bin/
# minikube version

# minikube start --vm-driver=virtualbox
😄  minikube v1.11.0 on Fedora 32
✨  Using the virtualbox driver based on user configuration
🛑  The "virtualbox" driver should not be used with root privileges.
💡  If you are running minikube within a VM, consider using --driver=none:
📘    https://minikube.sigs.k8s.io/docs/reference/drivers/none/

# su - amit
[amit@localhost ~]$ minikube start --vm-driver=virtualbox
😄  minikube v1.11.0 on Fedora 32
✨  Automatically selected the virtualbox driver
💿  Downloading VM boot image ...
    > minikube-v1.11.0.iso.sha256: 65 B / 65 B [-------------] 100.00% ? p/s 0s
    > minikube-v1.11.0.iso: 174.99 MiB / 174.99 MiB  100.00% 898.23 KiB p/s 3m2
👍  Starting control plane node minikube in cluster minikube
💾  Downloading Kubernetes v1.18.3 preload ...
    > preloaded-images-k8s-v3-v1.18.3-docker-overlay2-amd64.tar.lz4: 526.01 MiB
🔥  Creating virtualbox VM (CPUs=2, Memory=2200MB, Disk=20000MB) ...
❗  This VM is having trouble accessing https://k8s.gcr.io
💡  To pull new external images, you may need to configure a proxy: https://minikube.sigs.k8s.io/docs/reference/networking/proxy/
🐳  Preparing Kubernetes v1.18.3 on Docker 19.03.8 ...
🔎  Verifying Kubernetes components...
🌟  Enabled addons: default-storageclass, storage-provisioner
🏄  Done! kubectl is now configured to use "minikube"
[amit@localhost ~]$ minikube status
minikube
type: Control Plane
host: Running
kubelet: Running
apiserver: Running
kubeconfig: Configured
# minikube stop|delete
```
![Imgurl](https://i.ibb.co/MRF7WHt/Screenshot-from-2020-06-06-13-19-57.png)

**Understanding the process under the hood**
- minikube start command will create a new VM based on minikube image. VM will contain:
  - Docker, rkt container engines, localkube library. 
- Minikube will start a virtual machine locally and deploy the necessary Kubernetes components into it.
- The VM will get configured with Docker and Kubernetes via a single binary called localkube.  
> rkt is an application container engine.

> localkube library includes all the components necessary for running Kubernetes.
  
- Checking minikube dashboard
```
# minikube dashboard
```


- Important minikube commands
```
# minikube docker-env   //output the environment variables
export DOCKER_TLS_VERIFY="1"
export DOCKER_HOST="tcp://192.168.99.100:2376"
export DOCKER_CERT_PATH="/Users/educative/.minikube/certs"
export DOCKER_API_VERSION="1.23"
# Run this command to configure your shell:
# eval $(minikube docker-env)
```

#### Minikube client installation
- Installation
```
# curl -LO https://storage.googleapis.com/kubernetes-release/release/$(curl -s https://storage.googleapis.com/kubernetes-release/release/stable.txt)/bin/linux/amd64/kubectl
# chmod +x ./kubectl
# sudo mv ./kubectl /usr/local/bin/kubectl
```
- Verification
```
# kubectl version
Client Version: version.Info{Major:"1", Minor:"18", GitVersion:"v1.18.3", GitCommit:"2e7996e3e2712684bc73f0dec0200d64eec7fe40", GitTreeState:"clean", BuildDate:"2020-05-20T12:52:00Z", GoVersion:"go1.13.9", Compiler:"gc", Platform:"linux/amd64"}
The connection to the server localhost:8080 was refused - did you specify the right host or port?

# kubectl version --output=yaml
clientVersion:
  buildDate: "2020-05-20T12:52:00Z"
  compiler: gc
  gitCommit: 2e7996e3e2712684bc73f0dec0200d64eec7fe40
  gitTreeState: clean
  gitVersion: v1.18.3
  goVersion: go1.13.9
  major: "1"
  minor: "18"
  platform: linux/amd64

```
- Connecting client with minikube server
```
# eval $(minikube docker-env)
```


