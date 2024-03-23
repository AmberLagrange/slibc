#include <mman/mman.h>

#include <syscall/syscall.h>

void *mmap(void *addr, unsigned long len, unsigned long prot, unsigned long flags, unsigned long file_descriptor, unsigned long offset) {
    
    /* NOLINTNEXTLINE(performance-no-int-to-ptr) */
    return (void *)__syscall_6(SYS_MMAP, (reg64)addr, (reg64)len, (reg64)prot, (reg64)flags, (reg64)file_descriptor, (reg64)offset);
}
