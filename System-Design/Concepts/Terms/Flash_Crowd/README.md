## Flash Crowd
- Legitimate sudden burst in requests for a specific Web document or website. Eg: on New year wishes sent on facebook.
- **Solutions**
  - *1.* Replicate the web document across multiple servers, as no requests increase, redirect to the replicas to offload the master. This is **overprovisioning** which is not good.
  - *2.*  dynamically create replicas when demand goes up.
  - *3.* Predicting flash crowd(not achieved yet, very difficult).
