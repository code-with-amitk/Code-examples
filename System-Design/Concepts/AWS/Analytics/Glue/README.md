**Glue**

### Glue
This service is used to create ETL(Extract, transform, load) jobs to extract data from inputs sources and place data into dataware houses for further analysis.
```c
Input source
  RDS         ---------\
  S3 Bucket   ---data--- GLUE ---load data--> Redshift(Data warehouse)
  other sources -------/                      - Does analysis
```
