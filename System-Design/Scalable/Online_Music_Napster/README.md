- **What is Napster?**
  - Music-focused online service sharing digital audio files(eg audio songs) encoded in MP3 format. 

## 5. HLD
- Each peer provides list of files maintained by it to centralized file server.
- **Steps**
  - *1.* Peers query the directory server in order to find other peers that hosts the files that peer need.
  - *2.* Once there is a match for a peer’s query, server forwards the address of the peer that stores the data item that matched the query
  - *3.* The peer that issued the matching query can directly contact the peer that has the data.
  
<img src="napster.JPG" width=400 />  

- **Advatanges**
  - *a.* Transfer of the file lists does not require much bandwidth.
- **Disadvatanges**
  - *b.* Single point of failure
