#include "string.h"

unsigned long strlen(const char *str) {
    unsigned long i = 0;

    while (str[i]) {
        ++i;
    }

    return i;
}

void *memset(void *str, int c, unsigned long n) {
    unsigned long i;

    char *addr = str;

    for (i = 0; i < n; ++i) {
        addr[i] = c;
    }

    return str;
}
