Versioning Control
- **gerrit**
  - [git vs gerrit](#vs)
  - gerrit issues
    - [Remote head refers to nonexistent ref](#rem)

## gerrit

<a name=vs></a>
### git vs gerrit

| | github/gitlab/bitbucket | gerrit |
| --- | --- | --- |
|What|Code Hosting tool|<ul><li>Github's product. Web based Code Review tool for github repositories</li></ul><ul><li>Once suggested changes are accepted, they can be merged to the target branch of the Git repository</li></ul><ul><li>Prevents developer to directly push changes on repo</li></ul>|
|Code review Capabilites|lesser|Extensive|
|Does not provide||Code browsing,search,Continious build,Code hosting|
|git history|not clean|cleaner|
|Permissions|not extensive|Much fine grained|

### gerrit issues
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
