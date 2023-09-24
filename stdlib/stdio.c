#include "../include/stdio.h"

#include "../include/stdlib.h"
#include "../include/string.h"

int vfprintf(FILE *file, const char *fmt, va_list args) {

    char *str = va_arg(args, char*);

    if (fmt && *fmt == '\n') { // Just to not access varargs without any of them
        return write(file->fd, "\n", 1);
    }

    return write(file->fd, str, strlen(str));
}

int fprintf(FILE *file, const char *fmt, ...) {

    int ret;
    va_list args;

    va_start(args, fmt);

    ret = vfprintf(file, fmt, args);

    va_end(args);

    return ret;
}

int printf(const char *fmt, ...) {

    int ret;
    va_list args;
    
    va_start(args, fmt);
    
    ret = vfprintf(stdout, fmt, args);

    va_end(args);

    return ret;
}

static FILE _STDIN  = {0};
static FILE _STDOUT = {1};
static FILE _STDERR = {2};

FILE *_Files[FOPEN_MAX] = { &_STDIN, &_STDOUT, &_STDERR };
