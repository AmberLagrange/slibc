#include <string.h>

#include <stdlib.h>

/* NOLINTNEXTLINE(bugprone-easily-swappable-parameters) */
void *memchr(const void *ptr, int character, size_t count) {

    size_t index = 0;
    unsigned char *arr = NULL;

    for (; index < count; ++index) {

        if (((unsigned char *)(ptr))[index] == (unsigned char)(character)) {

            arr = ((unsigned char *)(ptr) + index);
        }
    }

    return (void *)(arr);
}

/* NOLINTNEXTLINE(bugprone-easily-swappable-parameters) */
int memcmp(const void *lhs, const void *rhs, size_t count) {

    size_t index = 0;

    for (; index < count; ++index) {

        if (((char*)lhs)[index] < ((char*)rhs)[index]) {

            return -1;
        }

        if (((char*)lhs)[index] > ((char*)rhs)[index]) {

            return 1;
        }
    }

    return 0;
}

/* NOLINTNEXTLINE(bugprone-easily-swappable-parameters) */
void *memset(void *str, int character, size_t count) {

    size_t index = 0;
    char *addr = str;

    for (; index < count; ++index) {

        addr[index] = (char)character;
    }

    return str;
}


/* NOLINTNEXTLINE(bugprone-easily-swappable-parameters) */
void *memmove(void *dst, const void *src, size_t count) {

    char *tmp = malloc(count);
    (void)memcpy(tmp, src, count);
    (void)memcpy(dst, tmp, count);
    free(tmp);

    return dst;
}

void *memcpy(void *dst, const void *src, size_t count) {

    size_t index = 0;

    for (; index < count; ++index) {

        ((unsigned char *)dst)[index] = ((unsigned char *)src)[index];
    }
    
    return dst;
}
