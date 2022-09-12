|Power of 2|Name|Value|
|---|---|---|
|10|1K (Kilo)|10<sup>3</sup>|
|20|1M (Mega)|10<sup>6</sup>|
|30|1G (Giga)|10<sup>9</sup>|
|40|1T (Tera)|10<sup>12</sup>|
|50|1P (Peta)|10<sup>15</sup>|
|60|1E (Exa)|10<sup>18</sup>|
|70|1Z (Zeta)|10<sup>21</sup>|

**Donot Spend major time on Minor Things. Eg: BOE**

### To Cover (SD is Iterative process. Start from 1 then scale to 1M)
- **1. Requirements:**
  - *1a. Functional(Basic functionality, should work)*
  - *1b. Non-functional(defines quality)*
  - *1c. Extended:  S<sup>3</sup> L<sup>3</sup> A<sup>3</sup> C<sup>2</sup> R<sup>2</sup> F<sup>2</sup>: *   
    - Scalable, Secure, SOA
    - Logging, Load, [Latency](Terms)
    - Available, Accurate, Analyze, Authenticate
    - Cache(Invalidation, negative cache)
    - Reliable, Redundant(Using DB)
    - Fast, Fault Tolerant
- **2. Back of Envelope Calculations:** Storage estimates, QPS(Queries per second)
- **3. API Design**
- **4. HLD:** _For 2, 100, 1 lac users_
- **5. Database schema**
- **6. Tradeoffs/Bottlenecks & correction**
- **7. Adjusting to changing requirements**
  
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
