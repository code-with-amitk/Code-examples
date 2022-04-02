- Terms
  - [Geographic Region](#gr)
  - [Availabilty zones](#az)
  - [Edge Location](#el)
  - [GovCloud](#gc)

<a name=t></a>
## Terms
<a name=gr></a>
### [Geographic Region](https://aws.amazon.com/about-aws/global-infrastructure/regions_az/?p=ngi&loc=2)
- Each Region has atleast **2 AZ**
- **Largest Region of AWS is US-EAST(ie North Virginia)**, new services becomes available here 1st.
```c
  -------US-east-----------
   |---GR---|
   |AZ1 AZn |
   |--------|
```
<img src=regions_and_az.JPG width=500 />

<img src=north-america-political-map.jpg width=500 />

<a name=az></a>
### Availabilty zones
- 1 or more data center owned by AWS, collectively called AZ.
- Naming convention of AZ is {Geographic location}{letter}. Example AZs for us-east are: us-east-1a, us-east-1b
- Latency between AZ's is <10ms (Hence these AZs are purposely positioned to be that apart).
```c
   |-----------AZ---------------|
   | Data-center1  Data-center2 |  Data-centern
   |----------------------------|
```

<a name=el></a>
### Edge Locations
- Datacenters owned by trusted AWS partner, which has direct connection to AWS network.

<a name=gc></a>
### GovCloud Region
- [Geographic Region](#gr) for highly sensative data storage. Eg: US DOD, US DOJ(dept of justice) etc. Presently only 2 GovCloud Regions: US-West, US-East.
- Person using GovCloud need to be US citizen and located in US only.
