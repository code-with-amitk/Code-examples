
||signal()|sigaction()|
|---|---|---|
|1.Blocking signal2 while signal1 is being processed|No|Yes,sigaction blocks other signals while current signal is processed, then delivers the signal|
|2.Resetting signal action back to SIG_DFL (default) for all signals|Yes|No|
|3.Different behaviours across systems|Yes|No|
