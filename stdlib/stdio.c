#include "../include/stdio.h"

#include "../include/stdlib.h"
#include "../include/string.h"

int fprintf(FILE *file, const char *fmt, ...) {
    return write(file->fd, fmt, strlen(fmt));
}

int printf(const char *fmt, ...) {
    return fprintf(stdout, fmt);
}

static FILE _STDIN  = {0};
static FILE _STDOUT = {1};
static FILE _STDERR = {2};

FILE *_Files[FOPEN_MAX] = { &_STDIN, &_STDOUT, &_STDERR };
