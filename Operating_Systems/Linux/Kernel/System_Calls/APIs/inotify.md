**inotify**

### [inotify / Filesystem monitor](https://man7.org/linux/man-pages/man7/inotify.7.html)
- The inotify API provides a mechanism for monitoring filesystem events.  Inotify can be used to monitor individual files, or to monitor directories.
- **File Monitor:** if file is modified/removed application is notified using event.
- **Directory monitored:** inotify will return events for the directory itself, and for files inside the directory are changed

### Code
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
