#include <stdlib.h>

#include <signal.h>
#include <syscall/syscall.h>

void abort(void) {

    (void)raise(SIG_ABORT);

    __builtin_unreachable();
}

void exit(int status) {
    
    (void)__syscall_1(SYS_EXIT, status);

    __builtin_unreachable();
}
