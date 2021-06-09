## git commands
- **add:**    This adds files onto staging area, ie in-between cache
- **checkout:**
  - _1._ When we want to create a new branch OR
  - _2._ When we want to go onto existing branch.
```c
  git checkout <branch>           //1. Work on older branch
  git checkout -b <branch>        //2. Creating a new branch
```
- **clone:** Used to create a clone/copy of the target repository.
- **commit:**    This is not Central Repo. but this is final local copy
```c
  # git rev-list -n 1 sssd-1_16_4_21      //finding commit-id of version
  # git log;   
  # git commit --amend    
  # git push origin branch -f     //Changing commit message
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
- **merge:**    Merge 2 or more development histories together.
- **push:**    Pushing the changes onto main branch
- **pull:**    Synching with latest branch code
- **status:**    tells what's modified by you, what's not modified on local repo
- **rebase:** Reapply commits on top of another base tip. When we have merge conflicts we do
```c
# git rebase master
```
