### Bottlenecks

- **[1. Admission Control](Admission_Control)**
- **[2. Communication Control](Communication_Control)**
- **[3. Size Scaling](Size_Scaling)**
- **[4. Geographical Scalabilty](Geographical_Scalabilty)**
- **[5. Administrative Scalability](Administrative_Scalability)**    
- **[6. Consistency/Accuracy Problem](Consistency_Problem)**
- **7. DB becoming bottleneck**
  - When there are huge RW operations a shared database can easily become a performance bottleneck.
  - [Solution](/System-Design/Concepts/Databases/Database_Scaling)
- **[8. Developer designing Distributed system with following mindset](Developer_idealistic_mindset)**
- **9. [Flash Crowd](/System-Design/Concepts/Terms/)**
  - **Solutions**
    - *1.* Replicate the web document across multiple servers, as no requests increase, redirect to the replicas to offload the master. This is **overprovisioning** which is not good.
    - *2.*  dynamically create replicas when demand goes up.
    - *3.* Predicting flash crowd(not achieved yet, very difficult).
