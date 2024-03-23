#include <mman/mman.h>

#include <syscall/syscall.h>

int munmap(void *addr, unsigned long len) {

    return (int)__syscall_2(SYS_MUNMAP, (reg64)addr, (reg64)len);
}
