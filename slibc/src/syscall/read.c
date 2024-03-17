#include <syscall/syscall.h>

int read(int file_descriptor, void *buf, unsigned long count) {
    return (int)__syscall_3(SYS_READ, (reg64)file_descriptor, (reg64)buf, (reg64)count);
}
