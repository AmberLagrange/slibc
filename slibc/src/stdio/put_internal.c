#include <stdio/put_internal.h>

#include <stdio/itoa.h>

/*
int __fputl_internal(int l, int base, FILE *file) {

    int ret;

    char buf[MAX_INT_LENGTH] = {0};
    char *str = __ltoa__internal(l, buf, MAX_INT_LENGTH, base, 0);

    ret = fputs(str, file);
    if (ret < 0) return ret;

    return ret;
}*/

int __fputlu_internal(long l, int base, FILE *file) {

    int ret;


    char buf[MAX_INT_LENGTH] = {0};
    char *str = __ltoa__internal(l, buf, MAX_INT_LENGTH, base, 1);

    ret = fputs(str, file);
    if (ret < 0) return ret;

    return ret;
}

int __fputi_internal(int i, int base, FILE *file) {

    int ret;

    char buf[MAX_INT_LENGTH] = {0};
    char *str = __itoa__internal(i, buf, MAX_INT_LENGTH, base, 0);

    ret = fputs(str, file);
    if (ret < 0) return ret;

    return ret;
}

int __fputu_internal(unsigned u, int base, FILE *file) {

    int ret;

    char buf[MAX_INT_LENGTH] = {0};
    char *str = __itoa__internal(u, buf, MAX_INT_LENGTH, base, 1);

    ret = fputs(str, file);
    if (ret < 0) return ret;

    return ret;
}
