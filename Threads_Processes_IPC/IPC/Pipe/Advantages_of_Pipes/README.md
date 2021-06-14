## Advantages of Pipes
### 1. Advantages over plain/regular files
  - With a regular file also, a process could write all its output and hand it over to the next process.
  - But processes has to lock and then signal(like a semaphore) to let each other know when they were done reading or writing.
  - Pipes eliminate all this complexity, kernel does all internally.
