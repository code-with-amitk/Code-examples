**Juniper SRX**
- [History](#history)
- [Terminology](#Terminology)
- [SRX Series](#series)

<a name=history></a>
## History
- ScreenOS(came 1st) > JunoOS(followed) > SRX OS(latest)

||ScreenOS|JunoOS|SRX|
|---|---|---|---|
|What|Created on BSD Kernel. All processes/tasks runs inside kernel space|Modular wrt screenOS||
|Drawbacks|if any process crashes, entire screenOS crashes. Never designed for deep packet inspection.|||
|Adv||Addition of new services was easy.Simpified provisioning of n/w||

<a name=Terminology></a>
## Terminology
- CP(Central Point):
- NUMA(Non uniform memory access):
- RSS(Recieve Side Scaling): Microsoft's technology for distribtuing flow in queues.
- **Paths:** 
  - SlowPath: When 1st time packet comes it takes more time called slow path.
  - FastPath: Subsequent packets goes faster.
  - ExpressPath: Done in hardware
- SPU(Service Processing Unit): 
- SPC(Service Processing Card): Number of SPU's in 1 card

<a name=series></a>
## SRX Series
- [SRX-Series Types](SRXSeries_Types)
