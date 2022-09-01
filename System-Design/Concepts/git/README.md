**Versioning Control**
- [git vs gerrit](#vs)
- [How git works](#how)
- **Terms**
  - [Branch: feature, master](#b)
  - [Central repository(upstream)](#u)
  - [Clone](#c)
  - [Fork](#f)
  - [HEAD, Detached HEAD](#h)
  - [origin](#o)
  - [master](#mas)
  - [remote](#re)
- **Commands**
  - [add](#add)
  - [checkout](#co)
  - [cherry pick](#cp)
  - [clone](#clone)
  - [commit](#com)
  - [diff](#diff)
  - [log](#log)
  - [show](#sh)
  - [stash](#st)
  - [merge](#mr)
  - [push](#push)
  - [pull](#pull)
  - [status](#st)
  - [rebase](#re)
  - [Split pull request](#spl)
  - [sync with upstream](#sync)
- **Issues**
  - [Remove commit after push](#rcap)
  - [Remote head refers to nonexistent ref](#rem)
  - [Merge Conflict](#mer)
- [**Actions**](#ac)

<a name=vs></a>
### git vs gerrit
```c
                       | github/gitlab/bitbucket | gerrit 
-----------------------|-------------------------|--------------
  What                 |  Code Hosting tool      | Github's product. Code Review tool for github repositories, Prevents developer to directly push changes on repo.
Code review Capabilites|      lesser             | Extensive
Does not provide       |                         | Code browsing,search,Continious build,Code hosting
git history            |    not clean            |  cleaner
Permissions            |    not extensive        | Much fine grained
```

<a name=how></a>
### How git works
```c
<---------- My-PC ----------->
Working-Dir       Staging-Area         Committed-files         Remote-Repo
git status
        - git add ->
                            - git commit ->
                                                     - git push ->
                                                     <- git fetch -
         <-------- git checkout ------------
         <-------- git merge ---------------
```

## Terms
<a name=b></a>
### Branching
- Developers can work on branch of repo for (bug fixing, new features). By working on branch, master branch is not affected.
- **master branch:** generally represents the stable version of your code, which is released or published

<a name=u></a>
### Central repository(upstream)
Organization's copy. Production Copy

<a name=c></a>
### Clone
Making a local copy of code on your machine 

<a name=f></a>
### Fork 
Own duplicated copy of someone else's code. user1 created a repo. User2 wants a local copy of repo. user2 forks the repo. How to Fork?    
  - Login github > Search for repos > Click Fork.
  - Now under Your Profile you can see the forked repo. git clone it. Changes would not be reflected onto master branch

<a name=h></a>
### Head
- HEΑD is a pointer, which alwαys points to the latest commit in the brαnch. Whenever we make a commit head point to latest commit. Head is stored in 
```c
$ cαt .git/refs/heαds/mαster
570837e7d58fα4bccd86cb575d884502188b0c49
```
#### Detached Head
  - We checkedout a commit and its detached, ie we can do the changes, play around will not affect on git, since its not attached to any branch.
  - We can think detached head as Branch without name.
  - *How to Detach Head?* A situation where we have checked out a commit-id(instead of a branch), THIS means we want commit not branch.
```console
$ git clone https://github.com/amitkumar50/test-repo/
$ git checkout 4cd80c97557dca56192d7448c800850fbdb7d412             //Checkout commit. Usually we do  $ git checkout branch
You are in 'detached HEAD' state.

HEAD is now at 4cd80c9 test2
```
  - _[Merge changes/commmits from detached head](https://stackoverflow.com/questions/7124486/what-to-do-with-commit-made-in-a-detached-head)_
```console
branch2 is 6 commits behind master.

$ git checkout branch2
$ git rev-list --left-right --count master...branch2        //Checking How many commits master is head of branch2
6       0

$ git checkout 4cd80c9                              //Creating Detached Head!! Wow
$ git branch
* (HEAD detached at 4cd80c9)
  branch2
  master
  
$ vim test1/hello-rust.rs                           //Done changes in Detached head
$ git diff
+       println!("There");
 }
 ```
- **.git/HEAD?** Stores commit-id of most recent/latest commit on the branch.
- **Master/Trunk/Main/Head Branch:** Main branch (as of tree). Like trunk of tree. 
  - _upstream/master:_    Master branch of upstream
  - _Other Branches:_ These are like twigs of trunk. Finally trunk is main branch which keeps on going up    
    - Origin: Your fork from original/upstream

<a name=o></a>
#### origin
- "origin" is a shorthand name for the remote repository that a project was originally cloned from.
```c
$ git clone https://github.com/amitkumar50/test-repo    //origin=https://github.com/amitkumar50/test-repo
```

<a name=mas></a>
#### master
- master is name of branch on remote repository.

<a name=re></a>
#### remote 


## Commands
<a name=rev></a>
### Working on Review Comments
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

<a name=add></a>
#### add
This adds files onto staging area, ie in-between cache
```c
Working Directory --------------> Staging Area  --------------------> git repository
                    git add a.c                   git commit -m ""
```

<a name=co></a>
#### checkout
```c
  git checkout <branch>           //1. Work on older branch
  git checkout -b <branch>        //2. Creating a new branch
```

<a name=cp></a>
#### Cherry pick
Means choose commit from 1 branch and apply to other branch. Ex: cherry pick changes from branch1 to master
```c
$ git checkout test                               //Move to target branch where you want apply
$ git pull
$ git cherry-pick -x <commit-hash>                //This will keep original hash intact(for history)
$ git status
Yout branch is a head of 'origin/master' by 1 commit
gerrit$ git push <>
```

<a name=clone></a>
#### clone
Used to create a clone/copy of the target repository.
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

<a name=com></a>
#### commit
Move from [staging area](#add) to git repo
```c
  # git rev-list -n 1 sssd-1_16_4_21      //finding commit-id of version
  # git log;   
  # git commit --amend    
  # git push origin branch -f     //Changing commit message
```
<a name=diff></a>
#### diff
```c
$ git diff --output file        //Output in file
```
#### fetch
Download objects and refs from another repository

<a name=log></a>
#### log    
Shows commit logs.
```c
  # git log --graph
  # git log --grep 'openldap' --oneline
  # git log --since='<date>' --until='<date>' --pretty=oneline --grep openldap     //Look for commits between dates
  # git log commit-id-1 commit-id-2  --pretty=oneline                              //Look for commits between commit-ids
```
<a name=sh></a>
#### show
To see code changes that particular commit did
```c
  # git show commit
```

<a name=st></a>
#### stash
- Dictionary meaning: store (something) safely.
- _Example:_ You are working on change and customer esclation comes. Now you need to work on customer issue but you cannot drop your existing code. Stash it.
- git stash temporarily saves changes you've made to your working copy so you can work on something else, and then come back and re-apply them later on.
```c
$ git clone https://github.com/amitkumar50/test-repo
$ cd test-repo/
$ vim wip1
change

//Something committed in upstream
$ git pull
error: Your local changes to the following files would be overwritten by merge:
        wip1
Please commit your changes or stash them before you merge.
Aborting
$ git stash
Saved working directory and index state WIP on master: 29cb07c Update wip1
$ git pull
$ git stash list
stash@{0}: WIP on master: 29cb07c Update wip1
$ git stash pop
Auto-merging wip1
CONFLICT (content): Merge conflict in wip1        //Resolve merge conflict
$ git add wip1
$ git commit -m 'test'
$ git push origin master
```

<a name=mr></a>
#### merge
Merge 2 or more development histories together.

<a name=push></a>
#### push
- [origin](#o), [master](#mas)
```c
$ git add test.c
$ git commit -m 'msg'
$ git push origin branch1         //Push changes on branch1
$ git push origin master         //Push changes on master
```

<a name=pull></a>
#### pull
Synching with latest branch code

<a name=st></a>
#### status
tells what's modified by you, what's not modified on local repo

<a name=re></a>
#### rebase
Reapply commits on top of another base tip. When we have merge conflicts we do
```c
# git rebase master
```

<a name=spl></a>
#### [Split pull request]https://www.youtube.com/watch?v=e26Zx9K3cdQ)
```c
$ git clone repo

$ git pull origin branch

$ git log --oneline --decorate                        //reset to Head's parent commit(ie 3939039)
b899500 (HEAD -> main, origin/more_fixes) more testing
3939039 (origin/main, origin/HEAD) initial commit

$ git reset HEAD~                                    //reset to parent commit
Unstaged changes after reset:
M       README.md
M       src/main.rs
$ git diff                                            //go a head and create new commits

//Stage code related to feature1. 
//-p: Interactively choose hunks of patch between the index and the work tree and add them to the index.
//
$ git add -p                                          
...
Stage this hunk [y,n,q,a,d,e,?]? y
Stage this hunk [y,n,q,a,d,e,?]? e              //edit

..
$ git diff --staged
$ git commit -m "splitted commit"              //commit
[main 9f0685f] splitted commit
 2 files changed, 14 insertions(+), 7 deletions(-)
 
$ git diff                                        //Now commit deleted part
+const MEM_SIZE: usize = 0x2000;
+const CODE_SIZE: usize = 0x1000;
$ git add .
$ git commit -m "splitted commit2"                 

//Using this way, git history would be clean
$ git log --oneline                                //Now 2 seperate commits
3e98cf8 (HEAD -> main) splitted commit2
9f0685f splitted commit
3939039 (origin/main, origin/HEAD) initial commit
```

<a name=sync></a>
#### sync with upstream
```c
# git fetch origin                           # Updates origin/master
# git rebase origin/master            # Rebases current branch onto origin/master
```

## Issues
<a name=rcap></a>
#### Remove commit after push
```c
$ git clone
$ git checkout branch
$ git log
  abc           //Note commit ids which need to be removed
  def
$ git revert --no-commit abc
$ git revert --no-commit def
$ git commit -m "Reverting 2 commits"
$ git push ssh://amit@git:<path> HEAD:refs/for/master,r=reviwer-1,r=reviewer-2
```

<a name=rem></a>
#### Remote head refers to nonexistent ref
- Head(.git/HEAD) is a file storing reference to checkout branch
- ref: ref is a file storing hash of recent commit on checkout branch
- This error means:HEAD exists, but ref(File storing SHA-1 of recent commit on remote branch) is missing
- To resolve the issue(Admin can create symbolic links)# cd path/to/repo; git symbolic-ref HEAD refs/heads/master
```c
# git checkout test-repo
test-repo$ git branch
  * master
test-repo$ cat .git/HEAD                    <<HEAD exist
  ref: refs/heads/master
test-repo$ cat .git/refs/heads/master       <<ref does not exist
  257143e8aded4f0fca7712105581567162cab60c
test-repo$
```
<a name=mer></a>
#### Merge Conflict
- _1._ Use rebase button on gerrit UI to resolve merge conflict.
- _2._ If you want to make changes in PR.

<a name=ac></a>
## Actions
- Everytime some event happens to your repository on github a action is initiated
  - Events can be: PR created, PR merged, Issue created, contributor joines etc
- Action is single task. We can combine actions to create jobs and a custom workflow.
- **Custom Action?** We can write custom code(action) which can interact with github repository and perform tasks.

### Types of Actions
#### 1. Docker container Action
#### 2. Javascript Action
