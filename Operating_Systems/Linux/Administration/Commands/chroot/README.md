## chroot
- Every process/command in Linux has root directory. chroot changes the root directory for currently running processes as well as its child processes.
- **jailed Directory?** A process/command that runs in such a modified environment cannot access files outside the root directory. This modified environment is known as “chroot jail” or “jailed directory”.
- **Use cases?** To create a test environment, To recover the system or password, To reinstall the bootloader.

**Steps:** Creating new root directory
- *1.* Create a “jail” directory inside the “home” directory, which will be our new root.
```c
  $ mkdir $HOME/jail
```
- *2:* Create bin, lib64 inside “$HOME/jail”:
```c
  $ mkdir -p $HOME/jail/{bin, lib64}
  $ cd $HOME/jail
```
- *3:* Copy /bin/bash and /bin/ls into $HOME/jail/bin/ location.
```c
  $ cp -v /bin/{bash, ls} $HOME/jail/bin
```
- *4:* Use ldd command to print shared libraries used by /bin/bash
```c
  $ ldd /bin/bash
...
```
- *5:* Copy required libraries into $HOME/jail/lib64/.
```c
  $ cp -v libraries/displayed/by/above/command $HOME/jail/lib64
```
- *6.* Similarly, copy the libraries of ls command into $HOME/jail/lib64 location.
- *7:* Finally, chroot into your mini-jail:
```c
  $ sudo chroot $HOME/jail /bin/bash
```

