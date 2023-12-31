#include <mman/mman.h>

#include <syscall/syscall.h>

void *mmap(void *addr, unsigned long len, unsigned long prot, unsigned long flags, unsigned long fd, unsigned long offset) {
    
    unsigned long ret;
    ret = __syscall_6(SYS_MMAP, (reg64)addr, (reg64)len, (reg64)prot, (reg64)flags, (reg64)fd, (reg64)offset);

    return (void *)ret;
}
