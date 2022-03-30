**EC2(Elastic Compute Cloud)**
- [EC2 Instance Types](#it)
- [EC2 Pricing](#p)



## EC2(Elastic Compute Cloud)
- This is server hosted in AWS cloud, where we can create EC2 instances(or VMs). Helpful in scaling up/down.
  - With EC2, we can spun/delete instances when needed/not needed & pay only for the compute time.
- **without EC2(Old world):** if we need an new server, 1st decide how big server is required(how many cores etc), purcharse, installation around 2+ months
    
<a name=it></a>
### EC2 instance types
EC2 instance types are optimized for different tasks. When selecting an instance type, consider the specific needs of your workloads and applications.

|Type|What|Areas where used|
|---|---|---|
|1. General Purpose Instance|provide a balance of compute, memory, and networking resources|application servers, gaming servers, backend servers for enterprise applications, small and medium databases|
|2. Compute optimized instances|Have High-performance processors|web, application, and gaming servers|
|3. Memory optimized instances|For processing large datasets in memory|databases|
|4. Accelerated computing instances|Use hardware accelerators, or coprocessors to perform operations faster|floating-point number calculations, graphics processing, and data pattern matching|
|5. Storage optimized instances|For workloads that require high, sequential read and write access to large datasets on local storage. Measured using input/output operations per second (IOPS).|Distributed file systems, data warehousing applications|

| Family | Speciality | Use case |
| --- | --- | --- |
| D2 | Dense storage | File server/data warehouse/hadoop |
| R4 | Memory optimization | Memory intensive AppDBs |
| M4 | General purpose | Application servers |
| C4 | Compute Optimized | CPU Intensive AppDBs |
| G2 | Graphics Intensive | |
| H2| High speed storage | |
| F1 | Field programmable Gate Array | |
| T2 | Lowest cost general purpose | |
| P2 | Graphics/General Purpose| |
| X1 | Memory optmized |

<a name=p></a>
### EC2 Pricing


