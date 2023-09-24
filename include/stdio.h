#ifndef STDIO_H
#define STDIO_H

#include "stdarg.h"

typedef struct __FILE_IO {
    // TODO: actually implement this properly
    int fd;
} FILE;

#define FOPEN_MAX 16

extern FILE *_Files[FOPEN_MAX];

#define stdin  _Files[0]
#define stdout _Files[1]
#define stderr _Files[2]

int vfprintf(FILE *file, const char* fmt, va_list args);
int fprintf(FILE *file, const char* fmt, ...);
int printf(const char *fmt, ...);

#endif // STDIO_H