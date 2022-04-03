- [Availabilty zones](#az)
- [Geographic Region](#gr)
- [Edge Location](#el)
- [GovCloud](#gc)
- [Amazon VPC(Virtual Private Cloud)](#vpc)

<a name=az></a>
### Availabilty zones
- Single or Group of data centers owned by AWS is called AZ.
- Naming convention of AZ is {Geographic location}{letter}. Example AZs for us-east are: us-east-1a, us-east-1b
- Latency between AZ's is <10ms, AZ are located 10s of miles apart from each other.
- A best practice is to run a application across at least 2 Availability Zones in a Region.
```c
   ---------------------------------  Region   ---------------------------------
   
   |-----------AZ-1---------------|             |-----------AZ-2---------------|
   | Data-center1  Data-center2   | > 10 miles  | Data-center-n  Data-center-m |
   |------------------------------|             |------------------------------|
```

<a name=gr></a>
### [Geographic Region](https://aws.amazon.com/about-aws/global-infrastructure/regions_az/?p=ngi&loc=2)
- AWS region consists of multiple, isolated, physically seperated [Availablity Zones](#az)**
- **Largest Region of AWS is US-EAST(ie North Virginia)**, new services becomes available here 1st.
```c
  -------US-east-----------
   |---GR---|
   |AZ1 AZn |
   |--------|
```
|<img src=regions_and_az.JPG width=500 />|<img src=north-america-political-map.jpg width=500 />|
|---|---|

#### In which region should I place my service?
**Factors to consider before choosing a region:**
- _1. Compliance with data governance and legal requirements:_ Depending on your company and location, you might need to run your application in specific areas. For example, if your company requires all of its data to reside within the boundaries of the UK, you would choose the London Region.
- _2. Proximity to your customers:_ Selecting a Region that is close to your customers will help you to get content to them faster.
- _3. Available services within a Region:_ Sometimes, the closest Region might not have all the features that you want to offer to customers. Eg: Amazon Braket (AWS quantum computing platform) is not yet available in every AWS Region around the world, so choose that region in which service is available.
- _4. Pricing:_ Suppose that you are considering running applications in both the United States and Brazil. The way Brazil’s tax structure is set up, it might cost 50% more to run wrt US.


<a name=el></a>
### Edge Location
- These are also Datacenters but located very near to customer, wrt to actual datacenter which hosts the customer's data. Example:
   - Suppose Company's main datacenter is Brazil and customer is in China. Getting data from Brazil will cause huge latency.
   - Instead required data is cached near to customer's location(in local datacenter) from where Amazon CloudFront pulls and delivers the data.
```c
                               |-------------China-----------|
                               |       |-data-> Customer     |
                               |       |                     |
                               |  cloudfront                 |
                               |     /\                      |
                               | Local-datacenter(CDN)       |
                               |-----------------------------|
   Brazil
Company's Maindatacenter
```
**[WORLD MAP](https://geology.com/world/world-map.shtml)**

<a name=gc></a>
### GovCloud Region
- [Geographic Region](#gr) for highly sensative data storage. Eg: US DOD, US DOJ(dept of justice) etc. Presently only 2 GovCloud Regions: US-West, US-East.
- Person using GovCloud need to be US citizen and located in US only.
