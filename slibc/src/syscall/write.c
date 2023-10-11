#include <syscall/syscall.h>

int write(int fd, const char *buf, int length){
    return __syscall_3(SYS_WRITE, fd, (reg64)buf, length);
}
