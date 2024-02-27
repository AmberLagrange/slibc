#include <stdio.h>

#include <stdio/put_internal.h>

#include <ctype.h>
#include <stdarg.h>
#include <stdlib.h>
#include <syscall/syscall.h>

#define MAX_READ 256

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
    int             va_int;
    /*long            va_long;*/
    unsigned        va_unsigned;
    unsigned long   va_long_unsigned;

    ret = 0;
    count = 0;

    while ((c = *fmt) != '\0') {

        if (c == '%') {

            process_format:
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

                if (!va_long_unsigned) { /* NULL Pointer */

                    count += fputs("(nil)", file);
                    break;

                }

                count += fputs("0x", file);
                count += __fputlu_internal(va_long_unsigned, 16, file);
                break;

            case 'x':
                va_int = va_arg(args, int);
                count += __fputi_internal(va_int, 16, file);
                break;

            /*
            REALLY HACKY PLEASE DON'T ACTUALLY LEAVE THIS HERE
            THIS IS JUST FOR GTEST FOR NOW
            */
            case '2':
                goto process_format;

            default:
                fputs("Unimplemented format '", stderr);
                fputc(c, stderr);
                fputs("'. Will hopefully implement it later!\n", stderr);
                abort();
            }
        } else {
            ret = fputc(c, file);
            if (ret < 0) return ret;
            count += 1;
        }

        ++fmt;
    }

    return count;
}

int vsprintf(char *buffer, const char *fmt, va_list args) {

    UNUSED(buffer);
    UNUSED(fmt);
    UNUSED(args);

    return 0;
}
