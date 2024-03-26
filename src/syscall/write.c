#include <syscall/syscall.h>

int write(int file_descriptor, const char *buf, int count){
    return (int)__syscall_3(SYS_WRITE, file_descriptor, (reg64)buf, count);
}
