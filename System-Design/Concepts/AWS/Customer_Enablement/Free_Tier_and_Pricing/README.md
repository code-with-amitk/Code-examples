**Pricing and Support**
- [AWS Free Tier](#ft)
- [Pricing Strategy](#ps)
- [Billing & Cost Management dashboard](#bc)
- [TCO Calculator](#tco)


## Pricing and Support
Services are divided into some categories and based on that falls into Tiers.

<a name=ft></a>
### AWS Free Tier

|Offers|What|Example|
|---|---|---|
|a. Always Free|Free for some extent, payable after that|Lambda allows 1 million free requests, DynamoDB allows 25 GB free storage/month|
|b. 12 Months Free|offers are free for 12 months then paid|S3 Standard Storage, CloudFront data transfer out|
|c. Short term free Trials|length of each trial might vary by number of days or the amount of usage|Inspector offers a 90-day free trial|

<a name=ps></a>
### Pricing Strategy
- _1. Pay for what you use:_ Pay for amount of resources that you actually use.
- _2. Pay less when you reserve:_ Some services offer reservation options that provide a significant discount.
- _3. Pay less with volume-based discounts:_ Per-unit cost is incrementally lower with increased usage.

#### Pricing Examples

|Service|How Charged?|Pricing|
|---|---|---|
|Lambda|Based on the number of requests your functions hit & time taken to run|Free (Requests=1 million, Compute Time=3.2 million sec)/month|
|EC2|Time for which instance is running|Use spot instances to save upto 90%|
|S3|1. size & number of objects stored 2. Features used(replication, analytics) 3. Requests made to S3||

<a name=tco></a>
### TCO Calculator
- Compare cost of Onprem application wrt AWS env.
- It takes following inputs & produces report
  - _1._ Number of servers (Physical or VMs)
  - _2._ Resource information (CPU, RAM)
  - _3._ DB or non-DB.
