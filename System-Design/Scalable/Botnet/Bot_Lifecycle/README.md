## Phases to become botnet
- **Phase-1: Initial Injection**
  - Host is infected by a regular computer infection procedure(eg: unwanted downloads of malware from websites, infected files attached to email messages, infected removable disks, etc)

- **Phase-2 Secondary Injection:** 1st phase should be completed successfully.
  - Infected host runs malware program which searches of binaries in a given network database.
  - Binaries are downloaded and run, this makes these hosts as real bots. 
  - Downloading bot binaries is usually performed by FTP, HTTP or P2P protocols.
  - Botnet client(bot) must contact a [command and control (C&C)](../Botnet_Architecture) server to receive instructions or updates

- **Phase-3 Connection or Rally:** establishing a connection with the [C&C](../Botnet_Architecture)
  - this phase is scheduled every time the host is restarted to ensure the botmaster that the bot are able to receive commands to perform malicious activities.
