**inotify**
- Code
  - [C](#c)
  - [Rust](#rs)

### [inotify / Filesystem monitor](https://man7.org/linux/man-pages/man7/inotify.7.html)
- The inotify API provides a mechanism for monitoring filesystem events.  Inotify can be used to monitor individual files, or to monitor directories.
- **File Monitor:** if file is modified/removed application is notified using event.
- **Directory monitored:** inotify will return events for the directory itself, and for files inside the directory are changed

### Code
<a name=c></a>
#### C
```c
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/inotify.h>
#define PATH_MAX 15

int main( int argc, char argv ) {
  const char *filename = "/home/kumara/amit_code/a.txt";
  int inotfd = inotify_init();
  int watch_desc = inotify_add_watch(inotfd, filename, IN_MODIFY | IN_CREATE | IN_DELETE);
  size_t bufsiz = sizeof(struct inotify_event) + PATH_MAX + 1;
  struct inotify_event* event = malloc(bufsiz);

  //Waiting for event
  //ssize_t read(int fd, void *buf, size_t count)
  if (read(inotfd, event, bufsiz) > 0)
    printf("Change in file");

  ( void ) inotify_rm_watch( fd, wd );
  close (inotfd);
}

//Change the file a.txt

$ ./a.out
Change in file
```

<a name=rs></a>
#### Rust
```rs
# Cargo.toml
[package]
name = "test"
version = "0.1.0"
edition = "2021"

[dependencies]
inotify = {version="0.10.0"}
serde_yaml = {version="0.8"}
serde = {version="1.0"}
serde_derive = {ersion="1.0"}

# src/main.rs
fn fun() {
    loop
    {
        let mut inotify = Inotify::init().expect("Error while initializing inotify instance");

        let watch_desc = inotify
            .add_watch(
                "/home/amit/a.txt",
                WatchMask::MODIFY,
            )
            .expect("Failed to add file watch");

        let mut buffer = [0; 1024];
        let events = inotify
            .read_events_blocking(&mut buffer)        //Block here until event happens on file
            .expect("Error while reading events");

        for e in events {
            inotify.rm_watch(watch_desc).expect("Failed to rm file watch");
            inotify.close().expect("Failed to close file watch");
            break;
        }
        prinln!("Some event on file");
        break;
    }
}
fn main() {
    let handle1 = thread::spawn(fun);
    handle1.join().unwrap();
}
``
