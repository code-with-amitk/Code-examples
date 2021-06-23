- [What is Connected Security](#What)
- [How CS Works](#Pillars)

<a name="What"></a>
## What is Connected Security?
- **Presently day scenario:** All security devices work indivisually ie seperately protects the orgnization. Works in phylo.
```c
<--------------------------- 1 Orgnization ------------------------->
                      |
  site-1  router-1  firewall(Cisco)
                      |                                                               internet
                                                     |
                                  router-n    DDos Defense(Palo Alto)
                                                     |
```
- **Solution?** Connected Security
  - All components are connected, even belonging to different vendors.
  - Each component is leveraged euqally ie Network and security elements are used equally.
  - Turns routing devices(routers, switches) into security devices(eg: firewall, IPS etc).

<a name="Pillars"></a>
## How Connected Security Works
- **1. See** ie routing devices(routers, switches) detects the threat.
- **2. Automate/Threat Engine/Policy Engine** Solution(Software/hardware) that selects Policy to executed. Selects policy and informs firewalls to enforce/execute policy.
- **3. Protect/Firewall/IPS** Enforcement of policies at network (eg: firewalls, IPS etc) takes policies from Threat engine and execute/enforces policies, blocks the threat.
```c
//CS is not a devie its a architecture

                (Eye,mouth)                 (Brain)                  (Hands)
                Switch                      Automate                  Protect            Company-network
internet        NFX250                    SRX300/SRX4000              SRX5400
      -- threat-->
                Detects threat -- inform ---->
                                        Selects policy to run
                                              ---------- policy --> 
                                                                    Executes policy
                                                                    Threat BLOCKED
```
