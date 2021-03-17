## How to prevent botnet attack?
- **1. Reactive?** 1st detect malicious activity and then react to the attack by reducing malicious traffic to acceptable levels.
  - **Disadvantages?**
    - *a.* Need large infra/AI to judge the mailicious activity and adjustable network to work as per situation.
    - *b. Timing:* By the time its detected, system is already under attack(some percent of it).

- **2. Preventive?** Taking preventive measures before attack can happen. Detecting machines involved in the preparation of an attack, and deactivating them.
  - **How?** Forcing users to be authenticated

- **3. Others:**
  - *a.* Understanding DNS pattern of bots. bots communicates with botmaster using dynamic DNS. See [Connection & Rally Phase-3](Bot_Lifecycle)
  - *b.* Understanding File exchange patterns. Bot-master sends code files to bots during upgrade. See [Maintainence & Upgrading Phase-5](Bot_Lifecycle)

- **4. Hoynets to capture bots / Intrusion Detection systems (IDSs)**
  - Collect information from bots. After collecting information, it is possible to reach bot-master.
  - Get bot binaries, inflate them with information and reach bot-master.

