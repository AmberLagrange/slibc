#ifndef STDLIB_H
#define STDLIB_H

#define NULL ((void*)0)

void *malloc(unsigned long size);
void free(void *ptr);

__attribute__((noreturn)) void abort(void);
__attribute__((noreturn)) void exit(int status);

#endif /* STDLIB_H */
