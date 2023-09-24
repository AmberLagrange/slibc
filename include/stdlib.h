#ifndef STDLIB_H
#define STDLIB_H

void __slibc_start_main(int argc, char *argv[]);

// temp
int write(int fd, const char *buf, int length);

void exit(int status) __attribute__((noreturn));
void _Exit(int status) __attribute__((noreturn));

#endif // STDLIB_H
