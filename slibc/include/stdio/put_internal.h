#ifndef PUT_INTERNAL_H
#define PUT_INTERNAL_H

#include <stdio.h>

#define MAX_INT_LENGTH 256

int __fputi_internal (int         val, int base, FILE *file, int is_unsigned);
int __fputl_internal (long        val, int base, FILE *file, int is_unsigned);
int __fputf_internal (double      val,           FILE *file);
int __fputlf_internal(long double val,           FILE *file);

#endif /* PUT_INTERNAL_H */
