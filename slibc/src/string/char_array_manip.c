#include <string.h>

#include <stdlib.h>

#define UNUSED(x) ((void)x);

void *memchr(const void *ptr, int ch, size_t count) {

    unsigned i;
    unsigned char *arr = (unsigned char*)ptr;

    for (i = 0; i < count; ++i) {
        if (arr[i] == (unsigned char)ch) {
            return (void*)arr;
        }
        arr++;
    }

    return NULL;
}

int memcmp(const void *lhs, const void *rhs, size_t count) {

    unsigned i;

    for (i = 0; i < count; ++i) {

        if (((char*)lhs)[i] < ((char*)rhs)[i]) {
            return -1;
        }

        if (((char*)lhs)[i] > ((char*)rhs)[i]) {
            return 1;
        }
    }

    return 0;
}

void *memset(void *str, int c, size_t count) {
    size_t i;

    char *addr = str;

    for (i = 0; i < count; ++i) {
        addr[i] = c;
    }

    return str;
}

void *memmove(void *dst, const void *src, size_t count) {

    char *tmp = malloc(count);
    memcpy(tmp, src, count);
    memcpy(dst, tmp, count);
    free(tmp);

    return dst;
}

void *memcpy(void *dst, const void *src, size_t count) {

    size_t i;

    for (i = 0; i < count; ++i) {
        ((char *)dst)[i] = ((char *)src)[i];
    }
    
    return dst;
}
