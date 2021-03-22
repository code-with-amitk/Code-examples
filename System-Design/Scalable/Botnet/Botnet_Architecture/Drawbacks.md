## Drawbacks of [Architecture](./README.md)
  - **a. Centralized C&C is point of failure**
    - Solution-1: Decentralized C&C
      - Unstructured P2P Overlay. Random toplogies with different degrees of distribution.
      - Structured P2P Overlay. [DHT(Distributed Hash Table) approach](/System-Design/Scalable/Distributed_Downloading_Systems/BitTorrent)
      - Superpeer Overlays. All peers are not equal, some are selected as [superpeers](/System-Design/Scalable/Skype).
    - Solution-2: Random model C&C 
      - Bots does not contact bot-master or other bots. Instead, it waits for connection from botmaster.
      - *Advantages:*
        - *1.* Easy to implement, no communication protocol between bots and botmaster making it harder to detect.
