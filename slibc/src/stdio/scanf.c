#include <stdio.h>

#include <ctype.h>
#include <stdarg.h>
#include <stdlib.h>
#include <syscall/syscall.h>

/*
TODO: Properly implement scanf, currently doesn't use
      fmt and only returns a digit read.
*/

#define MAX_READ 256

void scan_int(FILE *file, int *dest) {

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
                scan_int(file, va_int_ptr);
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

int fscanf(FILE *file, const char *fmt, ...) {

    va_list args;
    int ret;

    va_start(args, fmt);

    ret = __vfscanf_internal(file, fmt, args);

    va_end(args);

    return ret;
}

int scanf(const char *fmt, ...) {

    va_list args;
    int ret;

    va_start(args, fmt);

    ret = __vfscanf_internal(stdin, fmt, args);

    va_end(args);

    return ret;
}
