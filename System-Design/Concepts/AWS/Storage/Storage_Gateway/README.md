**Storage gateway**
- [Types](#ty)

### Storage gateway
 Service that connects an on-premises software application with a cloud-based storage, Eg: A on-prem smb drive is mapped to AWS cloud storage using GW.
 ```c
  |------OnPrem--------------------------------|             |-------  AWS Cloud------------
  |   G:(smb_share)     AWS-provided-hypervisor              |
  |   size: unlimited          Storage_gw <-------internet------> S3 Bucket
  |--------------------------------------------|             |------------------------------|
 ```
- Storage Gateway is a virtual appliance installed on a hyper visor in your premises.
    
<a name=ty></a>
### Types of storage gatways
- **1. File Gateway (NFS):** Using NFS store flat files in S3
- **2. Volume Gateways (iSCSI):** Block based storage. store the entire copy of your site data on AWS
- **3. Tape Gateway (VTL):** Archiving solution allows you to create virtual tapes and send them to S3
