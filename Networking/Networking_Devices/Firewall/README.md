## Firewall / Packet Filter

- [1. Firewall](#what)
  - [1.1 Duties of firewall](#duties)
- [Types of firewalls](#types)
- [Zones](#zone)
  - [DMZ Zone](#dmz)

<a name=what></a>
## 1. Firewall
- Every packet entering/leaving company will pass thru firewall.
- Firewall rules are defined at firewall(Eg: using firewalld in RHEL). Packets matching the rules are forwarded normally. Packets failing the rules are dropped. Example
```c
  Allowed Ports: 80(HTTP), 25(Mail)
  Blocked Ports:  79(Finger Service to look at email)  //Drop all incoming packets to 79
``` 

<a name=duties></a>
## 1.1 Firewall Duties
- Stateful packet processing ie keep track of sessions
- NAT & PAT
- VPN Establishment
- Can implement other security elements, eg: SSL,ALG(Application level gateway),IDP(Intrusion detection & Prevention) etc

<a name=types></a>
## Types of firewalls
- Stateful Firewalls  
  - Inspects TCP & IP header fields to keep track of connections. SF works on Layer 3 and 4.
    - Drawback: It cannot inspect Application layer traffic.
- Application Firewalls

<a name=zone></a>
## Zones in firewall

<a name=dmz></a>
### DMZ (DeMilitarized Zone) 
- Part of company, here Public-facing servers can be placed. Eg: Web servers(with minumum and none secure information)
  - *Why?* Outsiders can contact Web-server(hosting company website) and no internal machine is compromised.
