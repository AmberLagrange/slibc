#ifndef STDIO_H
#define STDIO_H

extern const int stdin;
extern const int stdout;
extern const int stderr;

int fprintf(int fd, const char* fmt, ...);
int printf(const char *fmt, ...);

#endif // STDIO_H