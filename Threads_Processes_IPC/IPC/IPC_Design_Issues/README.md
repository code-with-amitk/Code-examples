### IPC Design Issues
- _1. Communication:_ How one process can pass information to other?
- _2. No Interference:_ Making sure two or more processes do not changes each other's data.
- _3. Sequence:_ Proper sequencing when dependencies are present: if process A produces data and process B prints them, B has to wait until A has produced some data before starting to print.
