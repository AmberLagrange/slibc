#include "string.h"

unsigned long strlen(const char *str) {
    unsigned long i = 0;

    while(str[i]) {
        ++i;
    }

    return i;
}
