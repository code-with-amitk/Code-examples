- [What is Botnet](#what)
  - [Purpose](#pur)
  - [Characteristics of Machine choosen by botmaster](#ch)
- [Phases to become botnet / Lifecycle](#life)
- [Architecture](#arch)
  - [Drawbacks of this arch](#draw)
- [Preventing Botnet Attacks](#pre)

<a name=what></a>
## Botnet / Robot network
Networks that are formed by compromised machines. These machines runs programs(called bots(malicious codes running on host computers)) controlled by master running on single machine called BOT-MASTER. Bots allows botmaster to control hosts. 
- Bots communicate with master and each other using any protocols, such as IRC, HTTP and P2P.
- Example: Rustock, the largest known botnet(in 2010), had over 1 million bots under its control.

<a name=pur></a>
### Purpose of Botnet
Mostly disruptive activities. Examples
- Spamming
- performing DDoS attacks
- distribution of malicious software (Trojan horses, spyware, keyloggers)
- software piracy, information harvesting, extortion
- identity theft and manipulating online games or surveys
- cyber wars, Unwanted wars between countries.

<a name=ch></a>
### Characteristics of Machine choosen by botmaster
- High Internet Speed/transmission rates: This can practically paralyse any service available in the Internet.
- Easy availability
- Low levels of security
- Low monitoring rates
- Distant locations

<a name=life></a>
## Phases to become botnet / Lifecycle
Phase-1: Initial Injection
- Host is infected by(eg: unwanted downloads of malware from websites, infected files attached to email messages, infected removable disks, etc)

Phase-2 Secondary Injection: 1st phase should be completed successfully.
- Infected host runs malware program which searches of binaries in a given network database.
- Binaries are downloaded(using ftp,http or p2p) and run, this makes these hosts as real bots. 
- Botnet client(bot) must contact a [command and control (C&C)](#arch) server to receive instructions or updates.

Phase-3 Connection or Rally: Establishing a connection with the [C&C](#arch)
- This phase is scheduled every time the host is restarted to ensure the botmaster that the bot are able to receive commands to perform malicious activities.
- Bots contact C&C server using [DNS](/Networking/OSI-Layers/Layer5/Protocols/DNS), some complex bots may run DNS algo internally to compute dynamic DNS.

Phase-4 Malicious Activities: 
- After establishing the C&C channel, the bot waits for commands from C&C to perform malicious activities.

Phase-5 Maintainence & Upgrading:
- Updating codes of bots by botmaster. This involves file exchanges.

<img src=lifecycle-of-bot.JPG width=400 />

<a name=arch></a>
## Architecture
Command-and-control infrastructure (C&C) 
- Centralized or decentralized control entity. One or more communication protocols are used by the botmaster(s) to command slave computers and coordinate their actions.

<img src=Botnet_Architecture.JPG width=400 />

<a name=draw></a>
### Drawbacks of this Arch
Centralized C&C is point of failure
- Solution-1: Decentralized C&C
  - Unstructured P2P Overlay. Random toplogies with different degrees of distribution.
  - Structured P2P Overlay.
  - Superpeer Overlays. All peers are not equal, some are selected as [superpeers](/System-Design/Scalable/Skype).
- Solution-2: Random model C&C 
  - Bots does not contact bot-master or other bots. Instead, it waits for connection from botmaster.
  - This is Easy to implement, no communication protocol between bots and botmaster making it harder to detect.

<a name=pre></a>
## Preventing Botnet attacks
_1. Reactive:_ 1st detect malicious activity and then react to the attack by reducing malicious traffic to acceptable levels. Disadvantages:
  - *a.* Need large infra/AI to judge the mailicious activity and adjustable network to work as per situation.
  - *b. Timing:* By the time its detected, system is already under attack(some percent of it).
_2. Preventive:_ Taking preventive measures before attack can happen. Detecting machines involved in the preparation of an attack, and deactivating them. Example by forcing users to be authenticated
_3. Others:_
  - *a.* Understanding DNS pattern of bots. bots communicates with botmaster using [dynamic DNS](#ddns). See [Connection & Rally Phase-3](Bot_Lifecycle)
  - *b.* Understanding File exchange patterns. Bot-master sends code files to bots during upgrade. See [Maintainence & Upgrading Phase-5](Bot_Lifecycle)
_4. Hoynets to capture bots / Intrusion Detection systems (IDSs)_
  - Collect information from bots. After collecting information, it is possible to reach bot-master.
  - Get bot binaries, inflate them with information and reach bot-master.


