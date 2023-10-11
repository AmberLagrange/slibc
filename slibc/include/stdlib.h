#ifndef STDLIB_H
#define STDLIB_H

#define NULL ((void*)0)

double  atof(const char *str);
int     atoi(const char *str);
long    atol(const char *str);

long          strtol(const char *str, char **str_end, int base);
unsigned long strtoul(const char *str, char **str_end, int base);
double        strtod(const char *str, char **str_end);

void *malloc(unsigned long size);
void free(void *ptr);

__attribute__((noreturn)) void abort(void);
__attribute__((noreturn)) void exit(int status);

#endif /* STDLIB_H */
