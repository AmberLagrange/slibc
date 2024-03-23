#include <stdlib.h>

#include <signal.h>
#include <syscall/syscall.h>

__attribute__((noreturn)) void abort(void) {

    raise(SIG_ABORT);

    __builtin_unreachable();
}

__attribute__((noreturn)) void exit(int status) {
    
    __syscall_1(SYS_EXIT, status);

    __builtin_unreachable();
}
