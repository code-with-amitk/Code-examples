## UNIX Time-sharing System / uts
- **What?** Allows us to unshare the domain and hostname from the current host system.
```c
> sudo unshare -u
# hostname
nb
# hostname new-hostname
# hostname
new-hostname
```
