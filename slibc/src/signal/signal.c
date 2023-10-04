#include <signal.h>

#include <syscall/syscall.h>

int raise(int sig) {
    int ret;
    int pid;

    pid = __syscall_0(SYS_GET_PID);
    ret = __syscall_2(SYS_KILL, pid, sig);

    return ret;
}
