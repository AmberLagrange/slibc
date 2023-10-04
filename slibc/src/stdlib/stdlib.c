#include <stdlib.h>

#include <signal.h>
#include <syscall/syscall.h>

int write(int fd, const char *buf, int length)
{
    return __syscall_3(SYS_WRITE, fd, (reg64)buf, length);
}

__attribute__((noreturn)) void abort(void) {

    raise(SIG_ABORT);

    __builtin_unreachable();
}

__attribute__((noreturn)) void exit(int status) {
    
    __syscall_1(SYS_EXIT, status);

    __builtin_unreachable();
}
