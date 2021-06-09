## [Merge changes/commmits from detached head](https://stackoverflow.com/questions/7124486/what-to-do-with-commit-made-in-a-detached-head)
- `branch2` is 6 commits behind master.
```console
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
