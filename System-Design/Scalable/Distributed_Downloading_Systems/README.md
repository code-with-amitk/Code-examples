## Distributed/Collaborative Downloading Systems
- **What?** 
  - n number of users(in nearby area) downloads chunks of Huge file(Eg: Movie video, TV Serial Video) and share fragment among them. User-1 downloads fragment-1, user-2=fragment-2 so on. Now some nearby user in network who does not have fragment-1 is supplied by user-1.
  - Integrity is provided using any of Hashing algorithms. SHA3/SHA2 etc.
- **Advantages?**
  - *1.* A low bandwidth user can download file quickly.
  - *2.* Saves network bandwidth, redundant/lost packets are lowered.
- **Examples**

|[P2P Networks](/Networking/OSI-Layers/Layer5/P2P_OverlayNetwork)|What|How|
|---|---|---|
|Napster|Music online service sharing digital audio files(mp3)|Centralized lookup|
|Gnutella||Flooding queries|
|Freenet, Chord||Routed Queries|
|Bittorrent|||
