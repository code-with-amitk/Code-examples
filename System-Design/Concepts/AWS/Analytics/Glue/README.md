**Glue**

### Glue
- This service is used to create ETL(Extract, transform, load) jobs to extract data from inputs sources and place data into dataware houses for further analysis.
- Glue transforms semi-structured, structured data to load into warehouse.
- glue is [Serverless](/System-Design/Concepts/AWS/Terms#sl)
```c
Input source
  RDS         ---------\
  S3 Bucket   ---data------ GLUE -----> ETL scripts --> load data--> Redshift(Data warehouse)
  other sources -------/                user can                     - Does analysis
  Semi-Strutured -----/                 edit scripts
  Structured data ---/
```
