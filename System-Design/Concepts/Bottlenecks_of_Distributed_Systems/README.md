## Bottlenecks

- **[1. Admission Control](Admission_Control)**
- **[2. Communication Control](Communication_Control)**
- **[3. Size Scaling](Size_Scaling)**
- _[4. Geographical Scalabilty](#gs)_
- **[5. Administrative Scalability](Administrative_Scalability)**    
- **[6. Consistency/Accuracy Problem](/System-Design/Concepts/Terms)**
- **7. DB becoming bottleneck**
  - When there are huge RW operations a shared database can easily become a performance bottleneck.
  - [Solution](/System-Design/Concepts/Databases/Database_Scaling)
- **[8. Developer designing Distributed system with following mindset](Developer_idealistic_mindset)**
- **9. [Flash Crowd](/System-Design/Concepts/Terms/)**

<a name=gs></a>
### 4. Geographical Scalabilty
- *Synchronous/Blocking* Communication not good on [WAN](System-Design/Concepts/Terms) socket is created as blocking and blocks on read()/write() system calls. client will block until reply from server, this may work on LAN.
  - Solution: Writing non-blocking applications. `fcntl(sockfd, F_SETFL, O_NONBLOCK);`

