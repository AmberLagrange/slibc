#include <stdio.h>

#include <stdio/put_internal.h>

/* TODO: Remove Abort after adding the rest of the format cases*/
#include <stdlib.h>

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

                if (!va_long_unsigned) { /* NULL Pointer */

                    count += fputs("(nil)", file);
                    break;

                }

                count += fputs("0x", file);
                count += __fputlu_internal(va_long_unsigned, 16, file);
                break;

            case 'l':
                fputs("Format l not supported.\n", stderr);
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
