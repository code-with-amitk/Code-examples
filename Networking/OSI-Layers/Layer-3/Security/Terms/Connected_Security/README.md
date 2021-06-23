- [1. What is Connected Security](#What)
- [2. How CS Works](#Pillars)
  - [2.1 Threat Detection Engine](#TDE)

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
## 2. How Connected Security Works
- **A. See** ie routing devices(routers, switches) detects the threat.
- **B. Automate/Threat Engine/Policy Engine** 
  - Looks into Feed provided by routing components, decides whether its Threat/malware if yes tells policies to execute.
  - Informs firewalls to enforce/execute policy. Examples:ATP(Advanced Threat Prevention) device, Cloud ATP
- **C. Protect/Firewall/IPS** Enforcement of policies at network (eg: firewalls, IPS etc) takes policies from Threat engine and execute/enforces policies, blocks the threat.
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

<a name="TDE"></a>
### 2.1 Threat Detection Engine
- _a. Threat Feed:_ 
- _b. Ondemand detection engine:_ Takes feed does anlysis/sandboxing/ML and says provides verdict that it's a threat or not.
- _c. Mitigation:_ Gives verdict that these devices are botnets.
