#ifndef PUT_INTERNAL_H
#define PUT_INTERNAL_H

#include <stdio.h>

#define MAX_INT_LENGTH 256

/*
int __fputl_internal(int l, int base, FILE *file);
*/
int __fputlu_internal(long l, int base, FILE *file);
int __fputi_internal(int i, int base, FILE *file);
int __fputu_internal(unsigned u, int base, FILE *file);

#endif /* PUT_INTERNAL_H */
