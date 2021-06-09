## Detached Head
- **What?** 
  - We checkedout a commit and its detached, ie we can do the changes, play around will not affect on git, since its not attached to any branch.
  - We can think detached head as Branch without name.
- **How to Detach Head?** A situation where we have checked out a commit-id(instead of a branch), THIS means we want commit not branch.
```console
$ git clone https://github.com/amitkumar50/test-repo/
$ git checkout 4cd80c97557dca56192d7448c800850fbdb7d412             //Checkout commit. Usually we do  $ git checkout branch
You are in 'detached HEAD' state.

HEAD is now at 4cd80c9 test2
```
- **[How to merge changes done in detached head to master or branch?](Merge_Commits_From_Detached_Head)**
```c

$ git rev-list --left-right --count master...branch2
6       0

# Create temporary branch for your detached head
git branch tmp

# Go to master
git checkout master

# Merge in commits from previously detached head
git merge tmp

# Delete temporary branch
git branch -d tmp
```
