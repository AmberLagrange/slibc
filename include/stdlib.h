#ifndef STDLIB_H
#define STDLIB_H

void __slibc_start_main(int argc, char *argv[]);

int write(int fd, const char *buf, int length);

__attribute__((noreturn)) void exit(int status);
__attribute__((noreturn)) void _Exit(int status);

#endif /* STDLIB_H */
