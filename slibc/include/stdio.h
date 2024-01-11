#ifndef STDIO_H
#define STDIO_H

#include <stdarg.h>

#define EOF (-1)

/*
    TODO: actually implement this properly
*/
typedef struct __FILE_IO {
    int fd;
} FILE;

#define FOPEN_MAX 16

extern FILE *_Files[FOPEN_MAX];

#define stdin  _Files[0]
#define stdout _Files[1]
#define stderr _Files[2]

int fputc(int c, FILE *file);
int putc(int c, FILE *file);
int putchar(int c);

int fputs(const char *str, FILE *file);
int puts(const char *str);

int vfprintf(FILE *file, const char* fmt, va_list args);
int fprintf(FILE *file, const char* fmt, ...);
int printf(const char *fmt, ...);

int getc(FILE *file);
int getchar(void);

int fscanf(FILE *file, const char *fmt, ...);
int scanf(const char *fmt, ...);

#endif /* STDIO_H */
