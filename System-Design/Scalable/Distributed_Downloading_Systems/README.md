## Distributed/Collaborative Downloading Systems
- **What?** 
  - n number of users(in nearby area/Domain) downloads a Huge file(Eg: Movie video, TV Serial Video) collaborativly by sharing fragment among them. User-1 downloads fragment-1, user-2=fragment-2 so on and share with each other to complete the file.
  - Integrity is provided using any of Hashing algorithms. SHA3/SHA2 etc.
- **Advantages?**
  - *1.* A low bandwidth user can download file quickly.
  - *2.* Saves network bandwidth, redundant/lost packets are lowered.
- **[UnStructured P2P Network Examples](/Networking/OSI-Layers/Layer-7/P2P_OverlayNetwork)**

|P2P Network|Napster|Gnutella|Freenet|Bittorrent|
|---|---|---|---|---|
|What|Music online service sharing digital audio files(mp3)|File Sharing|File Sharing|Downloading File|
|How|[Centralized lookup](/Networking/OSI-Layers/Layer5/P2P_OverlayNetwork/Types_of_Overlay_Network/Unstructured_Overlay/Exchanging_data.md)|[Flooding queries](/Networking/OSI-Layers/Layer5/P2P_OverlayNetwork/Types_of_Overlay_Network/Unstructured_Overlay/Exchanging_data.md)|Routed Queries|[Centralized lookup](/Networking/OSI-Layers/Layer5/P2P_OverlayNetwork/Types_of_Overlay_Network/Unstructured_Overlay/Exchanging_data.md)|
|Performance||Search until Time-To-Live expires|Search based on Hop-To-Live, no gurantee to locate data|Guarantee to locate data, good performance for popular data|
|Routing State||Constant|With small world property O(log n<sup>2</sup>)|Constant, choking may occur|
|Reliability||Performance degrades when the number of peers grow|No central point of failure|Tracker keeps track of the peers and pieces|
