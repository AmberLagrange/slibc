#include "../include/stdlib.h"
#include "../include/syscall.h"
#include "../include/signal.h"

#define NULL ((void*)(0))

/* VERY TEMPORARY */
/* 8MB of memory for malloc for now */
#define MAX_MALLOC_SIZE 1024 * 1024 * 8
#define ALIGNMENT 16

typedef unsigned char byte_t;

static byte_t mem[MAX_MALLOC_SIZE]; 
static unsigned long next_memory_block = 0;

void *malloc(unsigned long size) {

    void *ptr;
    int offset;

    if (!size) {
        return NULL;
    }

    if (MAX_MALLOC_SIZE - next_memory_block < size) {
        return NULL;
    }

    ptr = mem + next_memory_block;

    next_memory_block += size;
    offset = size % ALIGNMENT;

    /* Fix alignment */
    /* Currently just align everything to ALIGNMENT */
    if (offset) {
        next_memory_block += (ALIGNMENT - offset);
    }

    return ptr;
}

void free(void *ptr) {

    /* Freeing NULL shouldn't do anything */
    if (!ptr) {
        return;
    }

    /* TODO: Actually implement free */

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
