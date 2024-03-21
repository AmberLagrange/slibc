#ifndef CONVERT_H
#define CONVERT_H

#ifndef SIZE_T
#define SIZE_T

    typedef unsigned long size_t;

#endif

/* NOLINTBEGIN(bugprone-reserved-identifier) */
enum __radix_e {
    OCT_RADIX = 8,
    DEC_RADIX = 10,
    HEX_RADIX = 16
};

char *__itoa__internal(int  int_val,  char *buf, size_t len, enum __radix_e radix, int is_unsigned);
char *__ltoa__internal(long long_val, char *buf, size_t len, enum __radix_e radix, int is_unsigned);
/* NOLINTEND(bugprone-reserved-identifier) */

#endif /* CONVERT_H */
