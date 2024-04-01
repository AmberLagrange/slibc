#include <stdio/put_internal.h>

#include <stdio.h>
#include <stdlib/convert.h>

#define UNUSED(x) ((void)(x))

int __fputi_internal(int val, int radix, FILE *file, int is_unsigned) {

    int ret = 0;

    char buf[MAX_INT_LENGTH] = {0};
    char *str = __itoa_internal(val, buf, MAX_INT_LENGTH, radix, is_unsigned);

    ret = fputs(str, file);
    if (ret < 0) {
        return ret;
    }

    return ret;
}

int __fputl_internal(long val, int radix, FILE *file, int is_unsigned) {

    int ret = 0;

    char buf[MAX_INT_LENGTH] = {0};
    char *str = __ltoa_internal(val, buf, MAX_INT_LENGTH, radix, is_unsigned);

    ret = fputs(str, file);
    if (ret < 0) {
        return ret;
    }

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
