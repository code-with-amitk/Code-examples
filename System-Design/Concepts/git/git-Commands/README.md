**git commands**
- [Working on Review Comments](#rev)
- [Resolving Merge conflict, gerrit](https://osm.etsi.org/wikipub/index.php/Resolving_merge_conflicts)
- [Removing commits after push](#rem)
- [Sync your Branch with your master/Origin](#s)
- [Split pull request](#spl)


<a name=rev></a>
#### Working on Review Comments
```c
Open git bash
$ git clone; cd code
$ git checkout branch; git branch      //Change to existing branch
$ git pull origin branch               //Get latest code from repo
$ git pull my-changes                  //Find command on gerrit UI. Open Change Page > Download Patch > git pull. 
$ git rebase branch
$ git status
-> Do code change
$ git status              //Make sure changed files are there
$ git add file1 file2
$ git commit --amend
$ gitdir=<>
$ git push <complete command>
```

- **add:**    This adds files onto staging area, ie in-between cache
- **checkout:**
```c
  git checkout <branch>           //1. Work on older branch
  git checkout -b <branch>        //2. Creating a new branch
```
- **Cherry pick** means choose commit from 1 branch and apply to other branch. Ex: cherry pick changes from branch1 to master
```c
$ git branch
  master
  
gerrit$ git fetch .. && git cherry-pick FETCH_HEAD      //Command from gerrit PR > Download Patch > Cherry Pick
or
git$ git cherry-pick -x <commit-hash>                //This will keep original hash intact(for history)

$ git status
on master branch
Yout branch is a head of 'origin/master' by 1 commit

gerrit$ gitdir=<>
gerrit$ git push <>
```
- **clone:** Used to create a clone/copy of the target repository.
```c
# git config --global url "ssh://gerritgitmaster/".pushInsteadof "ssh://gerritgit/"
# git config --global user.name "Amit Kumar"
# git config --global user.email "name@company.com"
# git config --global pull.rebase true

//Generate ssh keys and upload on gerrit server
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

//Test connection
# ssh gerritgitmaster       //ssh master
..sucess message
# ssh gerritgit-mirror          //ssh mirror
--success message

$ git clone ssh://gerritgit-mirror/repo-name
```

- **commit:**    This is not Central Repo. but this is final local copy
```c
  # git rev-list -n 1 sssd-1_16_4_21      //finding commit-id of version
  # git log;   
  # git commit --amend    
  # git push origin branch -f     //Changing commit message
```
- **diff**
```c
$ git diff --output file        //Output in file
```
- **fetch:**    Download objects and refs from another repository
- **log:**    Shows commit logs.
```c
  # git log --graph
  # git log --grep 'openldap' --oneline
  # git log --since='<date>' --until='<date>' --pretty=oneline --grep openldap     //Look for commits between dates
  # git log commit-id-1 commit-id-2  --pretty=oneline                       //Look for commits between commit-ids
```
- **show** To see code changes that particular commit did
```c
  # git show commit
```
- **stash:** 
Dictionary meaning: store (something) safely in a hidden or secret place. git stash temporarily saves changes you've made to your working copy so you can work on something else, and then come back and re-apply them later on.
```git
$ git status
On branch main
Changes to be committed:
    new file:   style.css

$ git stash
Saved WIP: 5002d47 our new homepage HEAD is now at 5002d47 our new homepage

$ git status
On branch main
nothing to commit, working tree clean
```
- **merge:**    
Merge 2 or more development histories together.
- **push:** Pushing the changes onto main branch
```c
///gerrit///
$ git status                  //Check files changed
$ git diff                    //contents changed in files
$ git add file1 file2 file3
$ git commit -F commit-msg-file
$ git pull                        //Run these 2 else you will get merge conflict
$ git rebase
$ gitdir=$(git rev-parse --git-dir); scp -p -P 29481 user-id@<gerrit-server>:hools/commit-msg $(gitdir)/hooks
$ git push ssh://userId@bracnh HEAD:refs/for/branch%topic=<> , r=reviewer@test.com
```
- **pull:**
Synching with latest branch code
- **status:**    
tells what's modified by you, what's not modified on local repo
- **rebase:** 
Reapply commits on top of another base tip. When we have merge conflicts we do
```c
# git rebase master
```
<a name=rem></a>
#### Removing commits after push
```c
$ git clone
$ git checkout branch
$ git log
  abc           //Note commit ids which need to be removed
  def
$ git revert --no-commit abc
$ git revert --no-commit def
$ git commit -m "Reverting 2 commits"
$ git push origin branch
```

<a name=spl></a>
### Splitting pull request
```c
$ git clone repo
$ git pull origin branch
$ git reset HEAD~               //reset to parent commit
$ git status                       //Changes from last commit are unstaged
On branch master
Your branch is up to date with 'origin/master'.

Untracked files:
  (use "git add <file>..." to include in what will be committed)

        test_profian
        
```

<a name=s></a>
#### Sync your Branch with your master/Origin
```c
# git fetch origin                           # Updates origin/master
# git rebase origin/master            # Rebases current branch onto origin/master
```
