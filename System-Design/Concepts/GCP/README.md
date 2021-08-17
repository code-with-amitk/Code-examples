**GCP / Google Cloud Platform**
- [Storage](#sto)
  - [Based on Location](#loc)
  - [Choices](#typ)
- [Network Services](#net)

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
## Network Services
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
