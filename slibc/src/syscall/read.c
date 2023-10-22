#include <syscall/syscall.h>

int read(int fd, void *buf, unsigned long count) {
    
    int ret;

    ret = __syscall_3(SYS_READ, (reg64)fd, (reg64)buf, (reg64)count);

    return ret;
}
