#include <stdio.h>

#include <ctype.h>
#include <stdarg.h>
#include <stdlib.h>
#include <syscall/syscall.h>

#include <stdio/put_internal.h>

#define UNUSED(x) ((void)(x))

enum __max_buffer_e {       /* NOLINT(bugprone-reserved-identifier) */
    MAX_READ = 256
};

enum __prepend_sign_e {     /* NOLINT(bugprone-reserved-identifier) */
    PREPEND_SIGN_NEGATIVE,
    PREPEND_SIGN_ALWAYS,
    PREPEND_SIGN_SPACE
};

enum __justification_e {    /* NOLINT(bugprone-reserved-identifier) */
    RIGHT_JUSTIFIED,
    LEFT_JUSTIFIED
};

enum __left_pad_e {         /* NOLINT(bugprone-reserved-identifier) */
    LEFT_PAD_SPACE,
    LEFT_PAD_ZERO
};

enum __integer_length_e {   /* NOLINT(bugprone-reserved-identifier) */
    DEFAULT_LENGTH,
    SHORT_LENGTH,
    LONG_LENGTH
};

enum __precision_e {        /* NOLINT(bugprone-reserved-identifier) */
    DEFAULT_PRECISION = 6
};

/*
    TODO: Properly implement scanf, currently doesn't use
        fmt and only returns a digit read.

    TODO: Remove Abort after adding the rest of the format cases
*/

void __internal_scan_int(FILE *file, int *dest) { /* NOLINT(bugprone-reserved-identifier) */

    char buf[MAX_READ];
    char character_read = '\0';
    int count = 0;

    while ((character_read = (char)getc(file)) != EOF && count < MAX_READ - 1) {

        if (!isdigit(character_read)) {
            break;
        }

        buf[count++] = character_read;
    }

    buf[count] = '\0';
    *dest = (int)strtol(buf, NULL, DEC_RADIX);
}

/*
    internal only, not technically part of ths spec
*/

int __vfscanf_internal(FILE *file, const char *fmt, va_list args) { /* NOLINT(bugprone-reserved-identifier) */

    int *va_int_ptr = NULL;
    char character_read = '\0';

    while ((character_read = *fmt) != '\0') {
        if (character_read == '%') {

            ++fmt;

            switch ((character_read = *fmt)) {
            case 'd':
                va_int_ptr = va_arg(args, int *);
                __internal_scan_int(file, va_int_ptr);
                break;

            default:
                fprintf(stderr, "Format %%%c not supported yet!\n", character_read);
                abort();
            }
        }

        ++fmt;
    }

    return 1;
}

int __vsscanf_internal(const char *buffer, const char *fmt, va_list args) { /* NOLINT(bugprone-reserved-identifier,bugprone-easily-swappable-parameters) */

    UNUSED(buffer);
    UNUSED(fmt);
    UNUSED(args);

    return 0;
}

int scanf(const char *fmt, ...) {

    va_list args;
    int ret = 0;

    va_start(args, fmt);

    ret = __vfscanf_internal(stdin, fmt, args);

    va_end(args);

    return ret;
}

int fscanf(FILE *file, const char *fmt, ...) {

    va_list args;
    int ret = 0;

    va_start(args, fmt);

    ret = __vfscanf_internal(file, fmt, args);

    va_end(args);

    return ret;
}

int sscanf(const char *buffer, const char *fmt, ...) {

    va_list args;
    int ret = 0;

    va_start(args, fmt);

    ret = __vsscanf_internal(buffer, fmt, args);

    va_end(args);

    return ret;
}

int printf(const char *fmt, ...) {

    va_list args;
    int ret = 0;
    
    va_start(args, fmt);
    
    ret = vfprintf(stdout, fmt, args);

    va_end(args);

    return ret;
}

int fprintf(FILE *file, const char *fmt, ...) {

    va_list args;
    int ret = 0;

    va_start(args, fmt);

    ret = vfprintf(file, fmt, args);

    va_end(args);

    return ret;
}

int sprintf(char *buffer, const char* fmt, ...) {

    va_list args;
    int ret = 0;
    
    va_start(args, fmt);
    
    ret = vsprintf(buffer, fmt, args);

    va_end(args);

    return ret;
}

int vprintf(const char *fmt, va_list args) {

    return vfprintf(stdout, fmt, args);
}

/*
TODO: Maybe make it less complex? printf is a big function so not sure if possible
*/
int vfprintf(FILE *file, const char *fmt, va_list args) { /* NOLINT(readability-function-cognitive-complexity) */

    int ret = 0;
    char character = 0;

    int count = 0;

    char            va_char           = '\0';
    char           *va_str            = NULL;
    short           va_short          = 0;
    unsigned short  va_short_unsigned = 0;
    int             va_int            = 0;
    unsigned        va_unsigned       = 0;
    long            va_long           = 0;
    unsigned long   va_long_unsigned  = 0;
    double          va_double         = 0.0F;
    long double     va_long_double    = 0.0;
    int            *va_int_ptr        = NULL;

    int text_justification  = RIGHT_JUSTIFIED;
    int sign_prepend        = PREPEND_SIGN_NEGATIVE;
    int hash_flag           = 0;
    int number_padding      = LEFT_PAD_SPACE;
    int length_mod          = DEFAULT_LENGTH;
    int precision           = DEFAULT_PRECISION;
    int width               = 0;

    character = *fmt;

    while (character != '\0') {

        if (character == '%') {

            character = *++fmt;

            /* process flags */

            switch(character) {
                case '-':
                    text_justification = LEFT_JUSTIFIED;
                    character = *++fmt;
                    break;
                    
                case '+':
                    sign_prepend = PREPEND_SIGN_ALWAYS;
                    character = *++fmt;
                    break;

                case ' ':
                    sign_prepend = PREPEND_SIGN_SPACE;
                    character = *++fmt;
                    break;

                case '#':
                    hash_flag = 1;
                    character = *++fmt;
                    break;

                case '0':
                    number_padding = LEFT_PAD_ZERO;
                    character = *++fmt;
                    break;
            }

            /* process width */

            if (character == '*') {
                width = va_arg(args, int);
                character = *++fmt;
            } else {
                while (isdigit(character)) {
                    width *= DEC_RADIX;
                    width += (character - '0');
                    character = *++fmt;
                }
            }

            /* process precision */

            if (character == '.') {
                character = *++fmt;
                precision = 0;

                while (isdigit(character)) {
                    precision *= DEC_RADIX;
                    precision += (character - '0');
                    character = *++fmt;
                }
            }

            /* process length */

            switch (character) {
                case 'h':
                    length_mod = SHORT_LENGTH;
                    character = *++fmt;
                    break;

                case 'l':
                case 'L':
                    length_mod = LONG_LENGTH;
                    character = *++fmt;
                    break;
            }

            /* process specifier */

            switch (character) {
                case 'd':
                case 'i':
                    switch (length_mod) {
                        case DEFAULT_LENGTH:
                        case SHORT_LENGTH:
                            va_int = va_arg(args, int);

                            ret = __fputi_internal(va_int, DEC_RADIX, file, 0);
                            if (ret < 0) {
                                return ret;
                            }

                            count += ret;
                            break;

                        case LONG_LENGTH:
                            va_long = va_arg(args, long);

                            ret = __fputl_internal(va_long, DEC_RADIX, file, 0);
                            if (ret < 0) {
                                return ret;
                            }

                            count += ret;
                            break;
                    }

                    break;

                case 'u':
                        switch (length_mod) {
                        case DEFAULT_LENGTH:
                        case SHORT_LENGTH:
                            va_unsigned = va_arg(args, unsigned);

                            ret = __fputi_internal((int)va_unsigned, DEC_RADIX, file, 1);
                            if (ret < 0) {
                                return ret;
                            }

                            count += ret;
                            break;

                        case LONG_LENGTH:
                            va_long_unsigned = va_arg(args, unsigned long);

                            ret= __fputl_internal((long)va_long_unsigned, DEC_RADIX, file, 1);
                            if (ret < 0) {
                                return ret;
                            }

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
                                if (ret < 0) {
                                    return ret;
                                }

                                count += 1;
                            }

                            ret = __fputi_internal((int)va_unsigned, OCT_RADIX, file, 1);
                            if (ret < 0) {
                                return ret;
                            }

                            count += ret;
                            break;

                        case LONG_LENGTH:
                            va_long_unsigned = va_arg(args, unsigned long);

                            if (va_long_unsigned && hash_flag) {

                                ret = fputc('0', file);
                                if (ret < 0) {
                                    return ret;
                                }

                                count += 1;
                            }

                            ret = __fputl_internal((long)va_long_unsigned, OCT_RADIX, file, 1);
                            if (ret < 0) {
                                return ret;
                            }

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
                                if (ret < 0) {
                                    return ret;
                                }

                                count += ret;
                            }

                            ret = __fputi_internal((int)va_unsigned, HEX_RADIX, file, 1);
                            if (ret < 0) {
                                return ret;
                            }

                            count += ret;
                            break;

                        case LONG_LENGTH:
                            va_long_unsigned = va_arg(args, unsigned long);

                            if (va_long_unsigned && hash_flag) {

                                ret = fputs("0x", file);
                                if (ret < 0) {
                                    return ret;
                                }

                                count += ret;
                            }

                            ret = __fputl_internal((long)va_long_unsigned, HEX_RADIX, file, 1);
                            if (ret < 0) {
                                return ret;
                            }

                            count += ret;
                            break;
                    }

                    break;

                case 'f':
                    switch (length_mod) {
                        case DEFAULT_LENGTH:
                            va_double = va_arg(args, double);

                            ret = __fputf_internal(va_double, file);
                            if (ret < 0) {
                                return ret;
                            }

                            count += ret;
                            break;

                        case LONG_LENGTH:
                            va_long_double = va_arg(args, long double);

                            ret = __fputlf_internal(va_long_double, file);
                            if (ret < 0) {
                                return ret;
                            }

                            count += ret;
                            break;

                        default:
                            abort();
                    }
                    break;

                case 'e':
                case 'E':
                case 'g':
                case 'G':
                    abort();
                    break;

                case 'c':
                    va_char = va_arg(args, int);

                    ret = fputc(va_char, file);
                    if (ret < 0) {
                        return ret;
                    }

                    count += 1;

                    break;
                
                case 's':
                    va_str = va_arg(args, char*);

                    ret = fputs(va_str, file);
                    if (ret < 0) {
                        return ret;
                    }

                    count += ret;

                    break;

                case 'p':
                    va_long_unsigned = (unsigned long)va_arg(args, void*);

                    if (!va_long_unsigned) {

                        ret = fputs("(nil)", file);
                        if (ret < 0) {
                            return ret;
                        }

                        count += ret;

                        break;
                    }

                    ret = fputs("0x", file);
                    if (ret < 0) {
                        return ret;
                    }

                    count += ret;

                    ret = __fputl_internal((long)va_long_unsigned, HEX_RADIX, file, 1);
                    if (ret < 0) {
                        return ret;
                    }

                    count += ret;

                    break;
                
                case 'n':
                    va_int_ptr = va_arg(args, int*);
                    *va_int_ptr = count;

                    break;

                case '%':
                    ret = putc(character, file);
                    if (ret < 0) {
                        return ret;
                    }

                    count += 1;

                    break;
            }
        } else {

            ret = putc(character, file);
            if (ret < 0) {
                return ret;
            }

            
            count += 1;
        }

        character = *++fmt;
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

/*
TODO: Remove readability-non-const-parameter
*/
int vsprintf(char *buffer, const char *fmt, va_list args) { /* NOLINT(readability-non-const-parameter) */

    UNUSED(buffer);
    UNUSED(fmt);
    UNUSED(args);

    return 0;
}
