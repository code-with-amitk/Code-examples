## Steps of Creating new root directory
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
