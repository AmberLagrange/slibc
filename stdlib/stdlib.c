#include "../include/stdlib.h"
#include "../include/syscall.h"

// temp
int write(int fd, const char *buf, int length)
{
    return __syscall_3(SYS_WRITE, fd, (reg64)buf, length);
}

void __attribute__((noreturn)) _Exit(int status) {

    __syscall_1(SYS_EXIT, status);

    __builtin_unreachable();
}

void __attribute__((noreturn)) exit(int status) {
    _Exit(status);
}
