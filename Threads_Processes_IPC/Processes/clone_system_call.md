## Clone(2)
> int clone(int (*fn)(void *), void *stack, int flags, void *arg, .../* pid_t *parent_tid, void *tls, pid_t *child_tid */ );

- **What?** API creates a new child process, in a manner similar to fork(2). 
- **Difference?** Unlike fork(2), the clone(2) allows the child process to share parts of its execution context with the calling process, such as the memory space, the table of file descriptors, and the table of signal handlers. You can pass different namespace flags to clone(2) to create new namespaces for the child process.
