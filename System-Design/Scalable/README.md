|Power of 2|Name|Value|
|---|---|---|
|10|1K (Kilo)|10<sup>3</sup>|
|20|1M (Million/Mega)|10<sup>6</sup>|
|30|1G (Billion/Giga)|10<sup>9</sup>|
|40|1T (Trillon/Tera)|10<sup>12</sup>|
|50|1P (Peta/quadrillion)|10<sup>15</sup>|
|60|1E (Exa/quintillion)|10<sup>18</sup>|
|70|1Z (Zeta/sextillion)|10<sup>21</sup>|

**Donot Spend major time on Minor Things. Eg: BOE**

### To Cover (SD is Iterative process. Start from 1 then scale to 1M)
- **1. Requirements: 2 min** CRUD(Create, Read, Update, Delete)
  - *1a. Functional(Basic functionality, should work)*
  - *1b. Non-functional(defines quality)*
  - *1c. Extended:  S<sup>3</sup> L<sup>3</sup> A<sup>3</sup> C<sup>2</sup> R<sup>2</sup> F<sup>2</sup>: *   
    - Scalable, Secure, SOA
    - Logging, Load, [Latency](Terms)
    - Available, Accurate, Analyze, Authenticate
    - Cache(Invalidation, negative cache)
    - Reliable, Redundant(Using DB)
    - Fast, Fault Tolerant
- **2. Back of Envelope Calculations: 3 min** Storage estimates, QPS
- **3. API Design. 5 min**
- **4. HLD: 20 min** _For 2, 100, 1 lac users_. Include Components(Application server, Load Balancer, DB, Caches, CDN, Message Queues)
- **5. Database schema: 10 min**. Discuss(SQL vs NoSQL)
- **6. Scaling the system under load**. Discuss(Sharing, Replication, Partioning)
- **7. Failure Handling**. Discuss(Replicas, Fallbacks, Retries)
  
| | CDN | AWS Cloud |
| --- | --- | --- |
| SOA/modular | API G/W | ECS (containerized) |
| Secure | WAF, Shield | SSL-Term: https, encrypt(Web-server on ECS), least privileges(22 for SSH to only whitelisted IPs), Create a private subnet, smartcard access |
| Scaling | | |
| Logging | | cloudwatch-logs |
| Load | | Autoscalar, Elastic-LB |
| Cache | | ElasticCache, varnish(not aws product) |
| Combine & Derive | | Sagemaker |
| Authentication | S3 Auth frontend  | |
| Analyze | | Kinetics |
| Redundant | | DynamoDB(noSQL), Aurora(SQL) |
| Fast | Lambda | Lambda |
| User-pass-store | Cognito | |      
