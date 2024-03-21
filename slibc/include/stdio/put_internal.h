#ifndef PUT_INTERNAL_H
#define PUT_INTERNAL_H

#include <stdio.h>
#include <stdlib/convert.h>

#define MAX_INT_LENGTH 256

/* NOLINTBEGIN(bugprone-reserved-identifier) */
int __fputi_internal (int         val, enum __radix_e radix, FILE *file, int is_unsigned);
int __fputl_internal (long        val, enum __radix_e radix, FILE *file, int is_unsigned);
int __fputf_internal (double      val,                       FILE *file);
int __fputlf_internal(long double val,                       FILE *file);
/* NOLINTEND(bugprone-reserved-identifier) */

#endif /* PUT_INTERNAL_H */
