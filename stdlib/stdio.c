#include "../include/stdio.h"

#include "../include/stdlib.h"
#include "../include/string.h"

int fputchar(FILE *file, char c) {
    return write(file->fd, &c, 1);
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
                ret = fputchar(file, '%');
                if (ret < 0) return ret;
                count += ret;
                break;

            case 'c':
                va_char = va_arg(args, int);
                ret = fputchar(file, va_char);
                if (ret < 0) return ret;
                count += ret;
                break;

            case 's':
                va_str = va_arg(args, char*);
                ret = write(file->fd, va_str, strlen(va_str)); /* TODO: fputs */
                if (ret < 0) return ret;
                count += ret;
                break;

            case 'd':
                va_int = va_arg(args, int);
                va_str = &number[MAX_INT_LENGTH - 1];
                *va_str = '\0';

                if (va_int < 0) {
                    va_int = -va_int;
                    ret = fputchar(file, '-');
                    if (ret < 0) return ret;
                    count += ret;
                }

                while (va_int) {
                    --va_str;
                    *va_str = '0' + (va_int % 10);
                    va_int /= 10;
                }

                ret = write(file->fd, va_str, strlen(va_str));
                if (ret < 0) return ret;
                count += ret;
                break;
            }
        } else {
            ret = fputchar(file, c);
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
