#include "../include/stdio.h"

#include "../include/stdlib.h"
#include "../include/string.h"

static const char NUMERALS[16] = "0123456789abcdef";

static char * __itoa__internal(int i, char *buf, int len, int base, int is_unsigned) {

    unsigned u;
    int is_negative = 0;
    char *str = &(buf[len - 1]);
    buf[len] = '\0';

    if (i == 0) {
        *str = '0';
        return str;
    }

    if (is_unsigned) {
        u = (unsigned)i;

        while (u) {
            --str;
            *str = NUMERALS[u % base];
            u /= base;
        }
    } else {
        if (i < 0) {
            is_negative = 1;
            i = -i;
        }

        while (i) {
            --str;
            *str = NUMERALS[i % base];
            i /= base;
        }

        if (is_negative) {
            --str;
            *str = '-';
        }
    }

    return str;
}

static char * __ltoa__internal(long l, char *buf, int len, int base, int is_unsigned) {

    unsigned long lu;
    int is_negative = 0;
    char *str = &(buf[len - 1]);
    buf[len] = '\0';

    if (l == 0) {
        *str = '0';
        return str;
    }

    if (is_unsigned) {
        lu = (unsigned long)l;

        while (lu) {
            --str;
            *str = NUMERALS[lu % base];
            lu /= base;
        }
    } else {
        if (l < 0) {
            is_negative = 1;
            l = -l;
        }

        while (l) {
            --str;
            *str = NUMERALS[l % base];
            l /= base;
        }

        if (is_negative) {
            --str;
            *str = '-';
        }
    }

    return str;
}

/*
static int __fputl_internal(unsigned long lu, int base, FILE *file) {

    int ret;
    int count = 0;

    char buf[MAX_INT_LENGTH];
    char *str;
    
    buf[0] = '\0';
    str = &(buf[MAX_INT_LENGTH - 1]);

    if (lu < 0) {
        lu = -lu;
        ret = fputc('-', file);
        if (ret < 0) return ret;
        count += ret;
    }

    while (lu) {
        --str;
        *str = NUMERALS[lu % base];
        lu /= base;
    }

    ret = fputs(str, file);
    if (ret < 0) return ret;
    count += ret;

    return count;
} */

static int __fputlu_internal(long l, int base, FILE *file) {

    int ret;
    int count = 0;

    char buf[MAX_INT_LENGTH];
    char *str = __ltoa__internal(l, buf, MAX_INT_LENGTH, base, 1);

    ret = fputs(str, file);
    if (ret < 0) return ret;
    count += ret;

    return count;
}

static int __fputi_internal(int i, int base, FILE *file) {

    int ret;
    int count = 0;

    char buf[MAX_INT_LENGTH];
    char *str = __itoa__internal(i, buf, MAX_INT_LENGTH, base, 0);

    ret = fputs(str, file);
    if (ret < 0) return ret;
    count += ret;

    return count;
}

static int __fputu_internal(unsigned u, int base, FILE *file) {

    int ret;
    int count = 0;

    char buf[MAX_INT_LENGTH];
    char *str = __itoa__internal(u, buf, MAX_INT_LENGTH, base, 1);

    ret = fputs(str, file);
    if (ret < 0) return ret;
    count += ret;

    return count;
}

int fputc(int c, FILE *file) {

    unsigned char written;

    written = (unsigned char)c;

    write(file->fd, (char *)(&written), 1);

    return written;
}

int putc(int c, FILE *file) {
    return fputc(c, file);
}

int putchar(int c) {
    return putc(c, stdout);
}

int fputs(const char *str, FILE *file) {
    return write(file->fd, str, strlen(str));
}

int puts(const char *str) {

    int ret_1;
    int ret_2;

    ret_1 = fputs(str, stdout);
    if (ret_1 < 0) return ret_1;

    ret_2 = putchar('\n');
    if (ret_2 < 0) return ret_2;

    return ret_1 + 1;

}

int vfprintf(FILE *file, const char *fmt, va_list args) {

    int ret;
    char c;

    int count;

    char            va_char;
    char           *va_str;
    int             va_int;
    /*long            va_long;*/
    unsigned        va_unsigned;
    unsigned long   va_long_unsigned;

    ret = 0;
    count = 0;

    while ((c = *fmt) != '\0') {

        if (c == '%') {

            ++fmt;

            switch ((c = *fmt)) {
            case '%':
                ret = fputc('%', file);
                if (ret < 0) return ret;
                count += ret;
                break;

            case 'c':
                va_char = va_arg(args, int);
                ret = fputc(va_char, file);
                if (ret < 0) return ret;
                count += ret;
                break;

            case 's':
                va_str = va_arg(args, char*);
                ret = fputs(va_str, file);
                if (ret < 0) return ret;
                count += ret;
                break;

            case 'd':
            case 'i':
                va_int = va_arg(args, int);
                count += __fputi_internal(va_int, 10, file);
                break;
            case 'u':
                va_unsigned = va_arg(args, unsigned);
                count += __fputu_internal(va_unsigned, 10, file);
                break;
            case 'p':
                va_long_unsigned = (unsigned long)(va_arg(args, void*));
                count += fputs("0x", file);
                count += __fputlu_internal(va_long_unsigned, 16, file);
                break;
            case 'l':
                fputs("\nl format not yet supported\n", stderr);
                abort();
            }
        } else {
            ret = fputc(c, file);
            if (ret < 0) return ret;
            count += ret;
        }

        ++fmt;
    }

    return count;
}

int fprintf(FILE *file, const char *fmt, ...) {

    int ret;
    va_list args;

    va_start(args, fmt);

    ret = vfprintf(file, fmt, args);

    va_end(args);

    return ret;
}

int printf(const char *fmt, ...) {

    int ret;
    va_list args;
    
    va_start(args, fmt);
    
    ret = vfprintf(stdout, fmt, args);

    va_end(args);

    return ret;
}

static FILE _STDIN  = {0};
static FILE _STDOUT = {1};
static FILE _STDERR = {2};

FILE *_Files[FOPEN_MAX] = { &_STDIN, &_STDOUT, &_STDERR };
