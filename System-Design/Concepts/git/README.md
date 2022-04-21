**Versioning Control**
- [git vs gerrit](#vs)
- [Terms](#terms)
- **Issues**
  - [Remote head refers to nonexistent ref](#rem)
  - [Merge Conflict](#mer)
- [Actions](#ac)

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

<a name=terms></a>
## Terms
- **Central repository(upstream)**: Organization's copy. Production Copy
- **[Cherry pick:](git-Commands)** means choose commit from 1 branch and apply to other branch. 
- **Clone:**    Making a local copy of code on your machine 
- **Fork:** Own duplicated copy of someone else's code. user1 created a repo. User2 wants a local copy of repo. user2 forks the repo. How to Fork?    
  - Login github > Search for repos > Click Fork.
  - Now under Your Profile you can see the forked repo. git clone it. Changes would not be reflected onto master branch
- **HEAD** is a reference to the last commit in the currently checked-out branch.
- **Detached Head**
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

## Issues
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
- Action is single task. We can combine actions to create jobs and a custom workflow.
- **Custom Action?** We can write custom code(action) which can interact with github repository and perform tasks.

### Types of Actions
#### 1. Docker container Action
#### 2. Javascript Action
