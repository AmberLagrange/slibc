#include <stdio/put_internal.h>

#include <stdlib/convert.h>

#include <signal.h>

#define UNUSED(x) ((void)(x))

int __fputi_internal(int val, int base, FILE *file, int is_unsigned) {

    int ret;

    char buf[MAX_INT_LENGTH] = {0};
    char *str = __itoa__internal(val, buf, MAX_INT_LENGTH, base, is_unsigned);

    ret = fputs(str, file);
    if (ret < 0) return ret;

    return ret;
}

int __fputl_internal(long val, int base, FILE *file, int is_unsigned) {

    int ret;


    char buf[MAX_INT_LENGTH] = {0};
    char *str = __ltoa__internal(val, buf, MAX_INT_LENGTH, base, is_unsigned);

    ret = fputs(str, file);
    if (ret < 0) return ret;

    return ret;
}

int __fputf_internal(double val, FILE *file) {

    UNUSED(val);
    UNUSED(file);

    return -1;
}

int __fputlf_internal(long double val, FILE *file) {

    UNUSED(val);
    UNUSED(file);

    return -1;
}
