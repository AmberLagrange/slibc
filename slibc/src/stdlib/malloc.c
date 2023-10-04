#include <stdlib.h>

#include <mman/mman.h>

#define MAX_ALIGNMENT 16

void *malloc(unsigned long size) {

    unsigned char *ptr;
    unsigned long new_size;

    if (!size) {
        return NULL;
    }

    new_size = size + MAX_ALIGNMENT;

    ptr = mmap(0, new_size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    *ptr = new_size;

    return ptr + MAX_ALIGNMENT;
}

void free(void *ptr) {

    unsigned long size;

    /* Freeing NULL shouldn't do anything */
    if (!ptr) {
        return;
    }

    size = *((unsigned char *)ptr - MAX_ALIGNMENT); /* Get the size stored before the pointer */
    munmap(ptr, size);

    return;
}
