#include "../include/stdlib.h"
#include "../include/syscall.h"
#include "../include/signal.h"

#include "../include/mman.h"

void *malloc(unsigned long size) {

    unsigned long *ptr;
    unsigned long new_size;

    if (!size) {
        return NULL;
    }

    new_size = size + sizeof(size);

    ptr = mmap(0, new_size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    *ptr = new_size;

    return ptr + sizeof(size);
}

void free(void *ptr) {

    unsigned long size;

    /* Freeing NULL shouldn't do anything */
    if (!ptr) {
        return;
    }

    size = *((unsigned long *)ptr - sizeof(size)); /* Get the size stored before the pointer */
    munmap(ptr, size);

    return;
}

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
