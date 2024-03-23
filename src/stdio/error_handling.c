#include <stdio.h>

#define UNUSED(x) ((void)(x))

void clearerr(FILE *file) {

    UNUSED(file);
}

int foef(FILE *file) {

    UNUSED(file);

    return 0;
}

int ferror(FILE *file) {

    UNUSED(file);

    return 0;
}

void perror(const char *str) {

    UNUSED(str);
}
