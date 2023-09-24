#include "../include/stdlib.h"
#include "../include/syscall.h"

// temp
int write(int fd, const char *buf, int length)
{
    struct __syscall_t syscall;
    syscall.syscall = (uint64_t)SYS_WRITE;
    syscall.first   = (uint64_t)fd;
    syscall.second  = (uint64_t)buf;
    syscall.third   = (uint64_t)length;

    return __syscall(syscall);
}

void __attribute__((noreturn)) _Exit(int status) {

    struct __syscall_t syscall;
    syscall.syscall = SYS_EXIT;
    syscall.first = status;

    __syscall(syscall);

    __builtin_unreachable();
}

void __attribute__((noreturn)) exit(int status) {
    _Exit(status);
}
