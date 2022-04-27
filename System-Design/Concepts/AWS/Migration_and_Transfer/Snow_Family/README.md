**Snowball Family**
- [Types of snow device](#t)

## Snowball Family
- if customer want to copy huge data/exe (via internet) to AWS cloud it may take months. Example:
  - 1 GB/sec network connection may take 3 months to transfer 1 PB of data.
- **Snowball:** This is dust/rain/temperproof device for shipping the data to AWS site.
  - A dedicated security team comes with snowdevice to transfer your data encrypted to AWS site, then  AWS support will transfer data to cloud.
<img src=snowball.png width=100 />

<a name=t></a>
### Types of Snow devices

|Snow Device|Size|Storage|
|---|---|---|
|snow-Cone|Smallest|2 CPUs, 8 TB storage|
|snow-Ball|Medium||
|snow-Mobile|Large|100 PB. This is 45-foot long ruggedized shipping container, pulled by a semi trailer truck.|


#### Snowball

|Type|Storage|vCPUs|Usecase|
|---|---|---|---|
|2a. Edge Storage Optimized|80TB HDD, 1TB SATA|40|Large Scale Data Migration|
|2b. Edge Compute Optimized|42TB HDD, 7.68TB SATA|52|Machine Learning|

