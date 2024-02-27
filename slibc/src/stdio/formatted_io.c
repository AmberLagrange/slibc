#include <stdio.h>

#include <ctype.h>
#include <stdarg.h>
#include <stdlib.h>
#include <syscall/syscall.h>

#include <stdio/put_internal.h>

#define MAX_READ 256

#define PREPEND_SIGN_NEGATIVE 0
#define PREPEND_SIGN_ALWAYS   1
#define PREPEND_SIGN_SPACE    2

#define RIGHT_JUSTIFIED 0
#define LEFT_JUSTIFIED  1

#define LEFT_PAD_SPACE  0
#define LEFT_PAD_ZERO   1

#define DEFAULT_LENGTH  0
#define SHORT_LENGTH    1
#define LONG_LENGTH     2

#define UNUSED(x) ((void)(x))

/*
    TODO: Properly implement scanf, currently doesn't use
        fmt and only returns a digit read.

    TODO: Remove Abort after adding the rest of the format cases
*/

void __internal_scan_int(FILE *file, int *dest) {

    char buf[MAX_READ];
    char c;
    int count = 0;

    while ((c = getc(file)) != EOF && count < MAX_READ - 1) {

        if (!isdigit(c)) {
            break;
        }

        buf[count++] = (char)c;
    }

    buf[count] = '\0';
    *dest = atoi(buf);
}

/*
    internal only, not technically part of ths spec
*/

int __vfscanf_internal(FILE *file, const char *fmt, va_list args) {

    int *va_int_ptr;
    char c;

    while ((c = *fmt) != '\0') {
        if (c == '%') {

            ++fmt;

            switch ((c = *fmt)) {
            case 'd':
                va_int_ptr = va_arg(args, int *);
                __internal_scan_int(file, va_int_ptr);
                break;

            default:
                fprintf(stderr, "Format %%%c not supported yet!\n", c);
                abort();
            }
        }

        ++fmt;
    }

    return 1;
}

int __vsscanf_internal(const char *buffer, const char *fmt, va_list args) {

    UNUSED(buffer);
    UNUSED(fmt);
    UNUSED(args);

    return 0;
}

int scanf(const char *fmt, ...) {

    va_list args;
    int ret;

    va_start(args, fmt);

    ret = __vfscanf_internal(stdin, fmt, args);

    va_end(args);

    return ret;
}

int fscanf(FILE *file, const char *fmt, ...) {

    va_list args;
    int ret;

    va_start(args, fmt);

    ret = __vfscanf_internal(file, fmt, args);

    va_end(args);

    return ret;
}

int sscanf(const char *buffer, const char *fmt, ...) {

    va_list args;
    int ret;

    va_start(args, fmt);

    ret = __vsscanf_internal(buffer, fmt, args);

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

int fprintf(FILE *file, const char *fmt, ...) {

    va_list args;
    int ret;

    va_start(args, fmt);

    ret = vfprintf(file, fmt, args);

    va_end(args);

    return ret;
}

int sprintf(char *buffer, const char* fmt, ...) {

    va_list args;
    int ret;
    
    va_start(args, fmt);
    
    ret = vsprintf(buffer, fmt, args);

    va_end(args);

    return ret;
}

int vprintf(const char *fmt, va_list args) {

    return vfprintf(stdout, fmt, args);
}

int vfprintf(FILE *file, const char *fmt, va_list args) {

    int ret;
    char c;

    int count;

    char            va_char;
    char           *va_str;
    short           va_short;
    unsigned short  va_short_unsigned;
    int             va_int;
    unsigned        va_unsigned;
    long            va_long;
    unsigned long   va_long_unsigned;
    double          va_double;
    long double     va_long_double;
    int            *va_int_ptr;

    int text_justification  = RIGHT_JUSTIFIED;
    int sign_prepend        = PREPEND_SIGN_NEGATIVE;
    int hash_flag           = 0;
    int number_padding      = LEFT_PAD_SPACE;
    int length_mod          = DEFAULT_LENGTH;

    int width = 0;
    int precision = 6;

    ret = 0;
    count = 0;

    c = *fmt;

    while (c != '\0') {

        if (c == '%') {

            c = *++fmt;

            /* process flags */

            switch(c) {
                case '-':
                    text_justification = LEFT_JUSTIFIED;
                    c = *++fmt;
                    break;
                    
                case '+':
                    sign_prepend = PREPEND_SIGN_ALWAYS;
                    c = *++fmt;
                    break;

                case ' ':
                    sign_prepend = PREPEND_SIGN_SPACE;
                    c = *++fmt;
                    break;

                case '#':
                    hash_flag = 1;
                    c = *++fmt;
                    break;

                case '0':
                    number_padding = LEFT_PAD_ZERO;
                    c = *++fmt;
                    break;
            }

            /* process width */

            if (c == '*') {
                width = va_arg(args, int);
                c = *++fmt;
            } else {
                while (isdigit(c)) {
                    width *= 10;
                    width += (c - '0');
                    c = *++fmt;
                }
            }

            /* process precision */

            if (c == '.') {
                c = *++fmt;
                precision = 0;

                while (isdigit(c)) {
                    precision *= 10;
                    precision += (c - '0');
                    c = *++fmt;
                }
            }

            /* process length */

            switch (c) {
                case 'h':
                    length_mod = SHORT_LENGTH;
                    c = *++fmt;
                    break;

                case 'l':
                    length_mod = LONG_LENGTH;
                    c = *++fmt;
                    break;

                case 'L':
                    length_mod = LONG_LENGTH;
                    c = *++fmt;
                    break;
            }

            /* process specifier */

            switch (c) {
                case 'd':
                case 'i':
                    switch (length_mod) {
                        case DEFAULT_LENGTH:
                        case SHORT_LENGTH:
                            va_int = va_arg(args, int);

                            ret = __fputi_internal(va_int, 10, file, 0);
                            if (ret < 0) return ret;
                            count += ret;

                            break;

                        case LONG_LENGTH:
                            va_long = va_arg(args, long);

                            ret = __fputl_internal(va_long, 10, file, 0);
                            if (ret < 0) return ret;
                            count += ret;

                            break;
                    }

                    break;

                case 'u':
                        switch (length_mod) {
                        case DEFAULT_LENGTH:
                        case SHORT_LENGTH:
                            va_unsigned = va_arg(args, unsigned);

                            ret = __fputi_internal(va_unsigned, 10, file, 1);
                            if (ret < 0) return ret;
                            count += ret;

                            break;

                        case LONG_LENGTH:
                            va_long_unsigned = va_arg(args, unsigned long);

                            ret= __fputl_internal(va_long_unsigned, 10, file, 1);
                            if (ret < 0) return ret;
                            count += ret;

                            break;
                    }

                    break;

                case 'o':
                        switch (length_mod) {
                        case DEFAULT_LENGTH:
                        case SHORT_LENGTH:
                            va_unsigned = va_arg(args, unsigned);

                            if (va_unsigned && hash_flag) {
                                ret = fputc('0', file);
                                if (ret < 0) return ret;
                                count += 1;
                            }

                            ret = __fputi_internal(va_unsigned, 8, file, 1);
                            if (ret < 0) return ret;
                            count += ret;

                            break;

                        case LONG_LENGTH:
                            va_long_unsigned = va_arg(args, unsigned long);

                            if (va_unsigned && hash_flag) {
                                ret = fputc('0', file);
                                if (ret < 0) return ret;
                                count += 1;
                            }

                            ret = __fputl_internal(va_long_unsigned, 8, file, 1);
                            if (ret < 0) return ret;
                            count += ret;

                            break;
                    }

                    break;
                
                /*
                TODO: Capitals
                */
                case 'x':
                case 'X':
                    switch (length_mod) {
                        case DEFAULT_LENGTH:
                        case SHORT_LENGTH:
                            va_unsigned = va_arg(args, unsigned);

                            if (va_unsigned && hash_flag) {
                                ret = fputs("0x", file);
                                if (ret < 0) return ret;
                                count += ret;
                            }

                            ret = __fputi_internal(va_int, 16, file, 1);
                            if (ret < 0) return ret;
                            count += ret;

                            break;

                        case LONG_LENGTH:
                            va_long_unsigned = va_arg(args, unsigned long);

                            if (va_unsigned && hash_flag) {
                                ret = fputs("0x", file);
                                if (ret < 0) return ret;
                                count += ret;
                            }

                            ret = __fputl_internal(va_long_unsigned, 16, file, 1);
                            if (ret < 0) return ret;
                            count += ret;

                            break;
                    }

                    break;

                case 'f':
                    switch (length_mod) {
                        case DEFAULT_LENGTH:
                            va_double = va_arg(args, double);

                            ret = __fputf_internal(va_double, file);
                            if (ret < 0) return ret;
                            count += ret;

                            break;

                        case LONG_LENGTH:
                            va_long_double = va_arg(args, long double);

                            ret = __fputlf_internal(va_long_double, file);
                            if (ret < 0) return ret;
                            count += ret;

                            break;
                    }
                    break;

                case 'e':
                    abort();
                    break;

                case 'E':
                    abort();
                    break;

                case 'g':
                    abort();
                    break;

                case 'G':
                    abort();
                    break;

                case 'c':
                    va_char = va_arg(args, int);

                    ret = fputc(va_char, file);
                    if (ret < 0) return ret;
                    count += 1;

                    break;
                
                case 's':
                    va_str = va_arg(args, char*);

                    ret = fputs(va_str, file);
                    if (ret < 0) return ret;
                    count += ret;

                    break;

                case 'p':
                    va_long_unsigned = (unsigned long)va_arg(args, void*);

                    if (!va_long_unsigned) {
                        ret = fputs("(nil)", file);
                        if (ret < 0) return ret;
                        count += ret;

                        break;
                    }

                    ret = fputs("0x", file);
                    if (ret < 0) return ret;
                    count += ret;

                    ret = __fputl_internal(va_long_unsigned, 16, file, 1);
                    if (ret < 0) return ret;
                    count += ret;

                    break;
                
                case 'n':
                    va_int_ptr = va_arg(args, int*);
                    *va_int_ptr = count;

                    break;

                case '%':
                    ret = putc(c, file);
                    if (ret < 0) return ret;
                    count += 1;

                    break;
            }
        } else {
            ret = putc(c, file);
            if (ret < 0) return ret;
            
            count += 1;
        }

        c = *++fmt;
    }

    UNUSED(va_short);
    UNUSED(va_short_unsigned);

    UNUSED(text_justification);
    UNUSED(sign_prepend);
    UNUSED(number_padding);
    UNUSED(width);
    UNUSED(precision);

    return count;
}

int vsprintf(char *buffer, const char *fmt, va_list args) {

    UNUSED(buffer);
    UNUSED(fmt);
    UNUSED(args);

    return 0;
}
