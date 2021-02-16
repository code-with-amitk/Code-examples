## IPC Design Issues
- **1. Communication:** How one process can pass information to other?
- **2. No Interference:** Making sure two or more processes do not changes each other's data.
- **3. Sequence:** Proper sequencing when dependencies are present: if process A produces data and process B prints them, B has to wait until A has produced some data before starting to print.
