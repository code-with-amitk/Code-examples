## TCP Header
- Size: Min(20 bytes), Max(60 bytes)
```c
|src Port (2 byte)|	Dst Port (2 byte)| Seq No (4 byte) | Ack No (4 byte) |	HdrLength /Data Offset (4 bit) | Reserved (6 bit) |	Control Bits (6 bit) | 	WindowSize/ Receiving BufferSize (2 byte) |	Complete Packet Checksum (16 bit) | Urgent Ptr (16 bit) |	Options (0-40bytes) |	Pad |

Control Bits: URG ACK PSH RST SYN FIN 
```
