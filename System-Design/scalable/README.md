**Non-functional Requirements**
  - S<sup>3</sup>
      L<sup>3</sup>
      C<sup>2</sup>
      A<sup>3</sup>
      R<sup>2</sup>
      F
      - SOA, Secure, Scalable
      - Load, Latency, Logging
      - Cache(Cache invalidation, Negative cache)
      - Available, Authentication, Analyze, 
      - Reliable, Redundant(using DB), 
      - Fast(Lambda)
      
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
