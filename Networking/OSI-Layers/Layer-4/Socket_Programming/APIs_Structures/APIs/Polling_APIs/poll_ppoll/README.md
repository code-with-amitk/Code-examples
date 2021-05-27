## poll, ppoll
```c
int poll(struct pollfd *fds, nfds_t nfds, int timeout)
int ppoll(struct pollfd *fds, nfds_t nfds, const struct timespec *tmo_p, const sigset_t *sigmask);
```
- Newer than [select](../..)
- **Why?** For high performance networking server. It is much better designed and doesn’t suffer from most of the problems which select has.
- **Code**
```c
    struct pollfd fds[2];
    fds[0].fd = sock1;    fds[0].events = POLLIN;    //// Monitor sock1 for input
    fds[1].fd = sock2;    fds[1].events = POLLOUT;    //// Monitor sock2 for output
    int ret = poll( &fds, 2, 10000 );    // Wait 10 seconds
    if (ret == -1)    //poll failed
    else{
        // If we detect the event, zero it out so we can reuse the structure
        if ( pfd[0].revents & POLLIN ){    pfd[0].revents = 0;    //Input event on sock1    }
        if (pfd[1].revents & POLLOUT){    pfd[1].revents = 0;    //Output event on sock2    }
    }    
```
- *[Advantages of poll](Advantages.md), [Disadvantages of poll](Disadvantages.md)*
