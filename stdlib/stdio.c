#include "../include/stdio.h"

#include "../include/stdlib.h"
#include "../include/string.h"

const int stdin  = 0;
const int stdout = 1;
const int stderr = 2;

int fprintf(int fd, const char *fmt, ...) {
    return write(fd, fmt, strlen(fmt));
}

int printf(const char *fmt, ...) {
    return fprintf(stdout, fmt);
}