**EC2(Elastic Compute Cloud)**
- [EC2 Instance Types](#it)
- [EC2 Pricing](#p)
- [EC2 Auto scaling](#as)
  - [Auto Scaling group](#asg)
  - [Auto scaling Approaches](#app)



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
|Pricing Type|What|Example| Pay For |
| --- | --- |---| --- |
|1. On-Demand|Ideal for short term, Irregular work loads|Create a instance for learning and tear it| Whatever time you use it |
|2. Savings Plans(1 yr, 3 yr)|Ideal for Longer workloads which can run for 1 or 3 years ||Save upto 66%|
|3. Reserved Instances|Standard Reserved and Convertible Reserved Instances for a 1-year or 3-year term, and Scheduled Reserved Instances(for 1-year term)|Ends when we terminate the instance|
|4. Spot Instances|Ideal for workloads with flexible start and end times which can can withstand interruptions. if you make a Spot request and Amazon EC2 capacity is unavailable, the request is not successful until capacity becomes available. |Batch Processing|Save upto 90%|
|5. Dedicated Hosts(Most Expensive)|EC2 server fully dedicated to your use|

### EC2 Auto scaling
This means scaling automatically as load increases and reducing instances as load decreases
<a name=asg></a>
#### Auto Scaling group?
Min/Max number of EC2 instances that would spun up. Configuration:
- _a. Min Capacity = x._ These many intances will always be running. if x=2, then min 2 instances will always be there.
- _b. Desired Capacity = y._ In case of load switch to desired. if y=4, then 4 instances will run in case of load.
- _c. Max Capacity = z:_ Max instances which can spun is z. Even load is more than that, instances will not be spun.

<a name=app></a>
#### Auto scaling Approaches
- **1. Dynamic scaling:** As load increases spun up more instances.
- **2. Predictive scaling:** Predict the need in advance and scale as per prediction.

