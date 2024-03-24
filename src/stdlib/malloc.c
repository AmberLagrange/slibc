#include <stdlib.h>

#include <mman/mman.h>
#include <string.h>

/* NOLINTNEXTLINE(bugprone-reserved-identifier) */
enum {
    MAX_ALIGNMENT = 16
};

void *malloc(unsigned long size) {

    unsigned char *ptr = NULL;
    unsigned long new_size = 0;

    if (!size) {
        return NULL;
    }

    /* SCARY */
    new_size = size + MAX_ALIGNMENT;

    ptr = mmap(NULL, new_size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

    if ((long)ptr < 0) {
        return (void *)(-1); /* NOLINT(performance-no-int-to-ptr) */
    }

    *ptr = new_size;

    return ptr + MAX_ALIGNMENT;
}

void *realloc(void *ptr, unsigned long size) {

    unsigned long old_size = *((unsigned char *)ptr - MAX_ALIGNMENT);
    void *new_ptr = malloc(size);

    if (!new_ptr) {
        return NULL;
    }

    if (size < old_size) {
        memcpy(new_ptr, ptr, size);
    } else {
        memcpy(new_ptr, ptr, old_size);
    }

    free(ptr);

    return new_ptr;
}

void free(void *ptr) {

    size_t size = 0;

    /* Freeing NULL shouldn't do anything */
    if (!ptr) {
        return;
    }

    size = *((unsigned char *)ptr - MAX_ALIGNMENT); /* Get the size stored before the pointer */
    munmap(ptr, size);
}
