#include "../include/stdio.h"

#include "../include/stdlib.h"
#include "../include/string.h"

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

    char  va_char;
    char *va_str;
    int   va_int;

    char number[MAX_INT_LENGTH];

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
                va_int = va_arg(args, int);
                va_str = &number[MAX_INT_LENGTH - 1];
                *va_str = '\0';

                if (va_int < 0) {
                    va_int = -va_int;
                    ret = fputc('-', file);
                    if (ret < 0) return ret;
                    count += ret;
                }

                while (va_int) {
                    --va_str;
                    *va_str = '0' + (va_int % 10);
                    va_int /= 10;
                }

                ret = fputs(va_str, file);
                if (ret < 0) return ret;
                count += ret;
                break;
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
