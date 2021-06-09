## Head
- **What?** HEAD is a reference to the last commit in the currently checked-out branch.
- **[Detached Head?](Detached_Head)**

### .git/HEAD
- When we clone and switch to particular branch, then HEAD file stores name of that branch
```c
# cat .git/HEAD 
  ref: refs/heads/test-branch
  ref(reference) (.git/refs/heads/test-branch)? 
  git commit -> |SHA-1-HASH| -> Commit-Hash(12901210928391dasdjkan1)     //ref is a file storing hash of recent commit on checkout branch
  
  # vim .git/refs/heads/test-branch
    12901210928391dasdjkan1
```
