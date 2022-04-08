**Snowball Family**
- [Types of snow device](#t)

## Snowball Family
- if customer want to copy huge data/exe (via internet) to AWS cloud it may take months. Example:
  - 1 GB/sec network connection may take 3 months to transfer 1 PB of data.
- **Snowball:** This is dust/rain/temperproof device for storing/shipping the data to AWS site.
  - A dedicated security team comes with snowdevice to transfer your data encrypted to AWS site.
  - There AWS support will transfer data to cloud.

<a name=t></a>
### Types of Snow devices

#### 1. Snowcone
Smallest. 2 CPUs, 8 TB storage

#### 2. Snowball

|Type|Storage|vCPUs|Usecase|
|---|---|---|---|
|2a. Edge Storage Optimized|80TB HDD, 1TB SATA|40|Large Scale Data Migration|
|2b. Edge Compute Optimized|42TB HDD, 7.68TB SATA|52|Machine Learning|

#### 3. SnowMobile
- Exabyte-scale data transfer service. Transfer up to 100 petabytes of data
- A 45-foot long ruggedized shipping container, pulled by a semi trailer truck.
