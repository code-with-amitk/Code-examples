## Shell
- **What?** Computer program which exposes OS services to User or programs.

<img src=shell.PNG width=500 />

### Types of shells?    
- **a. Bash shell:** Comes with .bash_profile.
  - `~/.bash_profile?` Executed for shell Logins. 
    - Shell Login? When you are at remote machine, Login via ssh(type username/password) Before 1st time Command prompt arrives, bash_profile is executed
- **b. ksh/bourne shell(Default):** comes with .profile file.   
- **c. kcsh shell:** comes with .login file
  - `~/.bashrc?` Executed for non-shell logins.
    - Non-Shell login? You have already logged onto machine, now you open a new terminal window using xterm, vnc, KDE bashrc is executed.

### [How shell works](How_Shell_Works)
