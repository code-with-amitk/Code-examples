**GCP / Google Cloud Platform**
- [Storage](#sto)
  - [Based on Location](#loc)
  - [Choices](#typ)
- **Services**
  - [Network Services](#net)
  - [Big Data Services](#bd)
  - [ML Services](#ml)
  - [Identity Services](#id)
- **[Deploying GCE(Google Compute Engine)](#dep)**
  - [1. Instance Groups](#ins)
  - [2. Autohealing](#ah)
- **GKE(Google Kubernets Engine**
  - [Deploy, Connect](#gked)

<img src=gcp.JPG width=1000>

## GCP
- Create project `https://console.cloud.google.com/`.
- Add user. Dashboard > Project > IAM > Add > Email (Role:Admin)
- Create Billing account. Google will take 48 hours for verification.

<a name=sto></a>
## Storage
<a name=loc></a>
### On Location
```c
    Type   | Availability 
-----------|------------------------------------
  Standard | Highest (at multiple geo locations)
  Nearine  | Low-cost, data accessed less than once 1 month
  Coldline | Low-cost, data accessed less than once 1 quarter
  Archive  | Low-cost, data accessed less than once 1 year
```
<a name=typ></a>
### Choices
**SQL(Relational DB)**
```c
      Name      |           Desc                                                               | Applications
----------------|------------------------------------------------------------------------------|---
Filestore       | Users can provision NAS(Network attached storage) to integrate with GCE,GKE  |
Cloud SQL       | Fully managed(mySQL or Postgre) having data replication,backup,monitoring etc|
Cloud Spanner   | Relational DB with non-relational DB Capabilities. 99.99% availability SLA   | Trading,banks
```
**Non-SQL**
```c
      Name      |       Desc                      | Used in Applications
----------------|---------------------------------|-----------
Cloud Datastore | Fully managed                   | 
Cloud Firestore | next Gen cloud datastore        |
Big Table       | Massive scale with 10ms latency | Gmail, Gmaps
```

<a name=net></a>
### Network Services
GCP is based on SDN(Software defined networking), hence users can deliver all networking services programatically.
- **VPC(Virtual Private cloud):** Each user can create VPC, this is cloud version of physical network. VMs in VPC can talk to each other. Traffic over VPCs goes via VPC Peering.
```c
  |--VPC1-------|                      |------VPC2------|
  | VM1 VM2..   |---- internet --------|  VMn VMn+1     |
  |-------------|                      |----------------|
```
- **Load Balancers**
```c
  Http(s) LB
  SSL proxy LB
  TCP proxy LB
  Network LB
  Internal TCP/UDP LB
```
- **VPN:** VPC's communicate using VPN
- **Cloud Interconnect:** Low latency. Traffic does not go thru internet.
  - _Dedicated interconnect:_ 10Gbps piped directly to google datacenter.
  - _Partner interconnect:_ 50Mbps - 10Gbps thru google partner
- **Cloud Router**
- **Cloud DNS**
- Cloud CDN
- Cloud NAT
- Firewall
- IDP(Identity awre proxy)
- **Cloud Armor** Service that protects against DDoS attacks.

<a name=bd></a>
### Big Data Services
Process large amound of data and answer complex problems.
- **Big Query** Cloud datawarehouse with build in ML.
- **Pub/Sub (Publisher/Subscriber):** async messaging service. We can loosely couple application components and communicate using it.
- **Dataproc:** Fully managed [Apache spark, Hadoop cluster](). Billed per sec.
- **Dataflow** For processing data in stream and batches, based on [Apache Beam]()
- **Dataprep** Tool to perform data visualization without any coding skill requirement.
- **Datalab:** Explore, analiyze, transform data.
- **Data Studio:** consume data and visualize in form of reports and dashboard.

<a name=ml></a>
### ML Services
- **Cloud ML Engine:** User has to train and host ML model. Used [Tensorflow]() for training.
- **Pretrained APIs:** Eg: Google cloud video intelligence, cloud speech, cloud vision, natural language, translation
- **Auto ML:** Service to train ML models for those who does not have deep knowledge of Data science.
- **DialogFlow:** Conversation applications that interact with humans.

<a name=id></a>
### Identity Services
- **IAM(Identity & Access Management)** Control authorization of GCP services.
- **Cloud Identity:** Thsi is IDaaS(Identity as service). 

<a name=dep></a>
### Deploying GCE
`https://console.cloud.google.com/` > Dashboard > Compute Engine > VM Instances > Create Instance > Select Region > OS(Windows Server 2019) > Create > RDP(Set Window's password)
- Create pre-emptible instance so that after work it can tear down and save billing.
- Delete disk when VM Instance is deleted. Check this box to delete the disk to avoid unneccessary billing.
- _Sole Tenancy_ means all your VM's will lie on 1 machine and there would be no other company's VMs on that hardware.
- _GPUs_ can also be added at time of VM instance creation, but these are available on specific locations only.
- _TPUs(Tensor Processing Unit)_ can be assigned for ML processing.

<a name=ins></a>
#### 1. Instance Groups
> `Compute Engine > Instance Group > Create New Instance Template`
- Instance groups let's us organize VM instances or use them in a load-balancing backend service ie [autoscaling](/System-Design/Concepts/Terms)

<a name=ah></a>
#### 2. Autohealing
A healthcheck message is sent to each VM in [instance group](#ins). If response is not recieved intime, its assumed VM is not healthy and new VM is instantiated in its place.

## GKE / Google Kubernet Engine
Google's kubernets software. GKE provides a managed environment for deploying, managing, & scaling [containerized applications](/System-Design/Concepts/All_About_Containers) using Google infrastructure.
<a name=gked></a>
### Deploy, Connect GKE
- `https://console.cloud.google.com/` > Kubernets Engine > Enable. 
- Create Cluster > Standard > Location(Zonal), Control plane version(Release) > Create
- Node Pool(These are seperate instance groups running in GKE) > No of nodes, config > Ok

<img src=gke.JPG width=500/>

Once cluster is ready Choose connect button, run following command in cloud shell.
```
$ gcloud container clusters get-credentials cluster-1 --zone us-central1-c --project amit-project-323006
```
