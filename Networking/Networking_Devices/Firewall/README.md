## Firewall / Packet Filter
-  **What?** Every packet entering/leaving company will pass thru firewall.
- **How?**  Firewall rules are defined at firewall(Eg: using firewalld in RHEL). Packets matching the rules are forwarded normally. Packets failing the rules are dropped. Example
```c
  Allowed Ports: 80(HTTP), 25(Mail)
  Blocked Ports:  79(Finger Service to look at email)  //Drop all incoming packets to 79
```  
- **DMZ (DeMilitarized Zone)?** Part of company, here Public-facing servers can be placed. Eg: Web servers(with minumum and none secure information)
  - *Why?* Outsiders can contact Web-server(hosting company website) and no internal machine is compromised.
- **Stateful Firewalls?** Map packets to connections and use TCP/IP header fields to keep track of connections.
