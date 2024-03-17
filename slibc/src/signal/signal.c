#include <signal.h>

#include <syscall/syscall.h>

int raise(int sig) {

    int pid = (int)__syscall_0(SYS_GET_PID);
    return (int)__syscall_2(SYS_KILL, pid, sig);
}
