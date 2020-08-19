## CLONE

- Open Linux terminal which can ping git server and configure following
```
# git config --global url "ssh://gerritgitmaster/".pushInsteadof "ssh://gerritgit/"
# git config --global user.name "Amit Kumar"
# git config --global user.email "name@company.com"
# git config --global pull.rebase true
```

- Generate ssh keys and upload on gerrit server
```
# ssh-keygen -t rsa -C 'emailID'
# cat ~/.ssh/id_rsa.pub
<<<<<<<<<<<<Add this key to gerrit server>>>>>>>>>>>>>>>
# vim ~/.ssh/config
Host *
  ServerAliveInterval 20
Host gerrit*
  User <username without @>
  Port <>
Host gerritgit-mirror              //This is mirror server
  HostName <>
Host gerritgitmaster        //This is master server.
  Hostname <>
# chmod 0600 ~/.ssh/config  
```

- Test connection
```
# ssh gerritgitmaster       //ssh master
..sucess message
# ssh gerritgit-mirror          //ssh mirror
--success message
```

- Use **Mirror** for Clone/Fetch/Pull
```
# git clone ssh://gerritgit-mirror/repo-name
```
