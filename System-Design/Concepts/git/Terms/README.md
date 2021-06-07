## Terms
- **Central repository(upstream)**: Organization's copy. Production Copy
- **Clone:**    Making a local copy of code on your machine 
- **Fork:** Own duplicated copy of someone else's code. user1 created a repo. User2 wants a local copy of repo. user2 forks the repo. How to Fork?    
  - Login github > Search for repos > Click Fork.
  - Now under Your Profile you can see the forked repo. git clone it. Changes would not be reflected onto master branch
- **Head (.git/HEAD)?**  When you clone and switch to particular branch, then HEAD file stores name of that branch
```c
# cat .git/HEAD 
  ref: refs/heads/test-branch
  ref(reference) (.git/refs/heads/test-branch)? 
  git commit -> |SHA-1-HASH| -> Commit-Hash(12901210928391dasdjkan1)     //ref is a file storing hash of recent commit on checkout branch
  
  # vim .git/refs/heads/test-branch
    12901210928391dasdjkan1
```        
- **Master/Trunk/Main/Head Branch:** Main branch (as of tree). Like trunk of tree. 
  - _upstream/master:_    Master branch of upstream
  - _Other Branches:_ These are like twigs of trunk. Finally trunk is main branch which keeps on going up    
    - Origin: Your fork from original/upstream
