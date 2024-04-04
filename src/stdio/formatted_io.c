#include "stdio/put_internal.h"
#include <stdio.h>

#include <ctype.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

#include <stdlib/convert.h>

#define UNUSED(x) ((void)(x))

enum {
    MAX_READ    = 256,
    MAX_WRITE   = 256
};

enum {
    RIGHT_JUSTIFIED,
    LEFT_JUSTIFIED
};

enum {
    PREPEND_SIGN_NEGATIVE,
    PREPEND_SIGN_ALWAYS,
    PREPEND_SIGN_SPACE
};

enum {
    HASH_FLAG_DISABLED = 0,
    HASH_FLAG_ENABLED  = 1
};

enum {
    LEFT_PAD_SPACE,
    LEFT_PAD_ZERO
};

enum {
    DEFAULT_LENGTH,
    SHORT_LENGTH,
    LONG_LENGTH
};

enum {
    DEFAULT_PRECISION = 6
};

/*
    TODO: Properly implement scanf, currently doesn't use
        fmt and only returns a digit read.

    TODO: Remove Abort after adding the rest of the format cases
*/

/* NOLINTBEGIN(bugprone-reserved-identifier) */
void __internal_scan_int(FILE *file, int *dest) {

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

int __vfscanf_internal(FILE *file, const char *fmt, va_list args) {

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
                (void)fprintf(stderr, "Format %%%c not supported yet!\n", character_read);
                abort();
            }
        }

        ++fmt;
    }

    return 1;
}

/* NOLINTNEXTLINE(bugprone-easily-swappable-parameters) */
int __vsscanf_internal(const char *buffer, const char *fmt, va_list args) {

    UNUSED(buffer);
    UNUSED(fmt);
    UNUSED(args);

    return 0;
}
/* NOLINTEND(bugprone-reserved-identifier) */

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

/* NOLINTBEGIN(bugprone-reserved-identifier) */
#define __PROCESS_FLAGS(character, fmt, text_justification, sign_prepend, hash_flag, number_padding)        \
do {                                                                                                        \
    switch(character) {                                                                                     \
        case '-':                                                                                           \
            (text_justification) = LEFT_JUSTIFIED;                                                          \
            (character)          = *(fmt)++;                                                                \
            break;                                                                                          \
                                                                                                            \
        case '+':                                                                                           \
            (sign_prepend) = PREPEND_SIGN_ALWAYS;                                                           \
            (character)    = *(fmt)++;                                                                      \
            break;                                                                                          \
                                                                                                            \
        case ' ':                                                                                           \
            (sign_prepend) = PREPEND_SIGN_SPACE;                                                            \
            (character)    = *(fmt)++;                                                                      \
            break;                                                                                          \
                                                                                                            \
        case '#':                                                                                           \
            (hash_flag) = HASH_FLAG_ENABLED;                                                                \
            (character) = *(fmt)++;                                                                         \
            break;                                                                                          \
                                                                                                            \
        case '0':                                                                                           \
            (number_padding) = LEFT_PAD_ZERO;                                                               \
            (character)      = *(fmt)++;                                                                    \
            break;                                                                                          \
        default:                                                                                            \
            break;                                                                                          \
    }                                                                                                       \
} while (0)

#define __PROCESS_WIDTH(character, fmt, width, args)                                                        \
do {                                                                                                        \
    if ((character) == '*') {                                                                               \
        (width)     = va_arg(args, int);                                                                    \
        (character) = *(fmt)++;                                                                             \
    } else {                                                                                                \
        while (isdigit(character)) {                                                                        \
            (width)    *= DEC_RADIX;                                                                        \
            (width)    += ((character) - '0');                                                              \
            (character) = *(fmt)++;                                                                         \
        }                                                                                                   \
    }                                                                                                       \
} while (0)

#define __PROCESS_PRECISION(character, fmt, precision)                                                      \
do {                                                                                                        \
    if ((character) == '.') {                                                                               \
        (character) = *(fmt)++;                                                                             \
        (precision) = 0;                                                                                    \
                                                                                                            \
        while (isdigit(character)) {                                                                        \
            (precision) *= DEC_RADIX;                                                                       \
            (precision) += ((character) - '0');                                                             \
            (character) = *(fmt)++;                                                                         \
        }                                                                                                   \
    }                                                                                                       \
} while (0)

#define __PROCESS_LENGTH_MOD(character, fmt, length_mod)                                                    \
do {                                                                                                        \
    switch (character) {                                                                                    \
        case 'h':                                                                                           \
            (length_mod) = SHORT_LENGTH;                                                                    \
            (character)  = *(fmt)++;                                                                        \
            break;                                                                                          \
                                                                                                            \
        case 'l':                                                                                           \
        case 'L':                                                                                           \
            (length_mod) = LONG_LENGTH;                                                                     \
            (character)  = *(fmt)++;                                                                        \
            break;                                                                                          \
        default:                                                                                            \
            break;                                                                                          \
    }                                                                                                       \
} while (0)

#define __PROCESS_INTEGER(count, length_mod, buffer, args)                                                  \
do {                                                                                                        \
    char buf[MAX_INT_LENGTH] = {0};                                                                         \
    char *integer_start;                                                                                    \
                                                                                                            \
    switch (length_mod) {                                                                                   \
        case DEFAULT_LENGTH:                                                                                \
        case SHORT_LENGTH: {                                                                                \
                                                                                                            \
            int va_int = va_arg(args, int);                                                                 \
                                                                                                            \
            integer_start = __itoa_internal(va_int, buf, MAX_INT_LENGTH, DEC_RADIX, 0);                     \
            (void)strcat(buffer, integer_start);                                                            \
            (count) += strlen(integer_start);                                                               \
            break;                                                                                          \
        }                                                                                                   \
                                                                                                            \
        case LONG_LENGTH: {                                                                                 \
                                                                                                            \
            long va_long = va_arg(args, long);                                                              \
                                                                                                            \
            integer_start = __ltoa_internal(va_long, buffer, MAX_INT_LENGTH, DEC_RADIX, 0);                 \
            (void)strcat(buffer, integer_start);                                                            \
            (count) += strlen(integer_start);                                                               \
            break;                                                                                          \
        }                                                                                                   \
                                                                                                            \
        default:                                                                                            \
            break;                                                                                          \
    }                                                                                                       \
} while (0)

#define __PROCESS_UNSIGNED(count, length_mod, buffer, args)                                                 \
do {                                                                                                        \
    char buf[MAX_INT_LENGTH] =  {0};                                                                        \
    char *unsigned_start;                                                                                   \
                                                                                                            \
    switch (length_mod) {                                                                                   \
        case DEFAULT_LENGTH:                                                                                \
        case SHORT_LENGTH: {                                                                                \
                                                                                                            \
            unsigned va_unsigned = va_arg(args, unsigned);                                                  \
                                                                                                            \
            unsigned_start = __itoa_internal((int)va_unsigned, buf, MAX_INT_LENGTH, DEC_RADIX, 1);          \
            (void)strcat(buffer, buf);                                                                      \
            (count) += strlen(unsigned_start);                                                              \
            break;                                                                                          \
        }                                                                                                   \
                                                                                                            \
        case LONG_LENGTH: {                                                                                 \
                                                                                                            \
            unsigned long va_long_unsigned = va_arg(args, unsigned long);                                   \
            unsigned_start = __ltoa_internal(((long)va_long_unsigned), buf, MAX_INT_LENGTH, DEC_RADIX, 1);  \
            (void)strcat(buffer, unsigned_start);                                                           \
            (count) += strlen(unsigned_start);                                                              \
            break;                                                                                          \
        }                                                                                                   \
                                                                                                            \
        default:                                                                                            \
            break;                                                                                          \
    }                                                                                                       \
} while (0)

#define __PROCESS_OCTAL_AND_HEX(count, length_mod, hash_flag, prefix, radix, buffer, args)                  \
do {                                                                                                        \
    char buf[MAX_INT_LENGTH] =  {0};                                                                        \
    char *integer_start;                                                                                    \
                                                                                                            \
    switch (length_mod) {                                                                                   \
        case DEFAULT_LENGTH:                                                                                \
        case SHORT_LENGTH: {                                                                                \
                                                                                                            \
            unsigned va_unsigned = va_arg(args, unsigned);                                                  \
                                                                                                            \
            if (va_unsigned && (hash_flag)) {                                                               \
                (void)strcat(buffer, prefix);                                                               \
                (count) += strlen(prefix);                                                                  \
            }                                                                                               \
                                                                                                            \
            integer_start = __itoa_internal((int)va_unsigned, buf, MAX_INT_LENGTH, radix, 1);               \
            (void)strcat(buffer, integer_start);                                                            \
            (count) += strlen(integer_start);                                                               \
            break;                                                                                          \
        }                                                                                                   \
                                                                                                            \
        case LONG_LENGTH: {                                                                                 \
                                                                                                            \
            unsigned long va_long_unsigned = va_arg(args, unsigned long);                                   \
                                                                                                            \
            if (va_long_unsigned && (hash_flag)) {                                                          \
                                                                                                            \
                (void)strcat(buffer, prefix);                                                               \
                (count) += strlen(prefix);                                                                  \
            }                                                                                               \
                                                                                                            \
            integer_start = __ltoa_internal((long)va_long_unsigned, buf, MAX_INT_LENGTH, radix, 1);         \
            (void)strcat(buffer, integer_start);                                                            \
            (count) += strlen(integer_start);                                                               \
            break;                                                                                          \
        }                                                                                                   \
                                                                                                            \
        default:                                                                                            \
            break;                                                                                          \
    }                                                                                                       \
} while (0)


#define __PROCESS_FLOAT(count, length_mod, buffer, args)                                                    \
do {                                                                                                        \
    UNUSED(count);                                                                                          \
    UNUSED(length_mod);                                                                                     \
    UNUSED(buffer);                                                                                         \
    UNUSED(args);                                                                                           \
} while (0)

#define __PROCESS_CHAR(count, buffer, args)                                                                 \
do {                                                                                                        \
    char buf[2];                                                                                            \
    char va_char = va_arg(args, int);                                                                       \
    buf[0] = va_char;                                                                                       \
    buf[1] = '\0';                                                                                          \
    (void)strcat(buffer, buf);                                                                              \
    (count) += 1;                                                                                           \
} while (0)

#define __PROCESS_STR(count, buffer, args)                                                                  \
do {                                                                                                        \
    char *va_str = va_arg(args, char*);                                                                     \
    (void)strcat(buffer, va_str);                                                                           \
    (count) += strlen(va_str);                                                                              \
} while (0)

#define __PROCESS_POINTER(count, buffer, args)                                                              \
do {                                                                                                        \
    char buf[MAX_INT_LENGTH] =  {0};                                                                        \
    char *pointer_start;                                                                                    \
                                                                                                            \
    unsigned long va_long_unsigned = (unsigned long)va_arg(args, void*);                                    \
                                                                                                            \
    if (!va_long_unsigned) {                                                                                \
                                                                                                            \
        (void)strcat(buffer, "(nil)");                                                                      \
        (count) += strlen("(nil)");                                                                         \
        break;                                                                                              \
    }                                                                                                       \
                                                                                                            \
    (void)strcat(buffer, "0x");                                                                             \
    (count) += strlen("0x");                                                                                \
                                                                                                            \
    pointer_start = __ltoa_internal((long)va_long_unsigned, buf, MAX_INT_LENGTH, HEX_RADIX, 1);             \
    (void)strcat(buffer, pointer_start);                                                                    \
    (count) += strlen(pointer_start);                                                                       \
} while (0)

#define __PROCESS_COUNT(count, args)                                                                        \
do {                                                                                                        \
    int *va_int_ptr = va_arg(args, int*);                                                                   \
    *va_int_ptr = (int)(count);                                                                             \
} while (0)

#define __PROCESS_CHARACTER(character, count, buffer)                                                       \
do {                                                                                                        \
    char buf[2];                                                                                            \
    buf[0] = character;                                                                                     \
    buf[1] = '\0';                                                                                          \
    (void)strcat(buffer, buf);                                                                              \
    (count) += 1;                                                                                           \
} while (0)
/* NOLINTEND(bugprone-reserved-identifier) */

int vfprintf(FILE *file, const char *fmt, va_list args) {

    char buffer[MAX_WRITE] = {0};
    int count_vsprintf = vsprintf(buffer, fmt, args);
    int count_fputs    = fputs(buffer, file);

    /* TODO: Check counts are the same */
    UNUSED(count_fputs);

    return count_vsprintf;
}

int vsprintf(char *buffer, const char *fmt, va_list args) {

    int    width = 0;
    size_t count = 0;

    int text_justification  = RIGHT_JUSTIFIED;
    int sign_prepend        = PREPEND_SIGN_NEGATIVE;
    int hash_flag           = HASH_FLAG_DISABLED;
    int number_padding      = LEFT_PAD_SPACE;

    int precision           = DEFAULT_PRECISION;
    int length_mod          = DEFAULT_LENGTH;

    char character = *fmt;

    while (character != '\0') {

        if (character == '%') {

            character = *++fmt;

            __PROCESS_FLAGS(character, fmt, text_justification, sign_prepend, hash_flag, number_padding);
            __PROCESS_WIDTH(character, fmt, width, args);
            __PROCESS_PRECISION(character, fmt, precision);
            __PROCESS_LENGTH_MOD(character, fmt, length_mod);

            switch (character) {
                case 'd':
                case 'i':
                    __PROCESS_INTEGER(count, length_mod, buffer, args);
                    break;

                case 'u':
                    __PROCESS_UNSIGNED(count, length_mod, buffer, args);
                    break;

                case 'o':
                    __PROCESS_OCTAL_AND_HEX(count, length_mod, hash_flag, "0", OCT_RADIX, buffer, args);
                    break;
                
                /*
                TODO: Capitals
                */
                case 'x':
                case 'X':
                    __PROCESS_OCTAL_AND_HEX(count, length_mod, hash_flag, "0x", HEX_RADIX, buffer, args);
                    break;

                case 'f':
                    __PROCESS_FLOAT(count, length_mod, buffer, args);
                    break;

                case 'e':
                case 'E':
                case 'g':
                case 'G':
                    abort();
                    break;

                case 'c':
                    __PROCESS_CHAR(count, buffer, args);
                    break;
                
                case 's':
                    __PROCESS_STR(count, buffer, args);
                    break;

                case 'p':
                    __PROCESS_POINTER(count, buffer, args);
                    break;
                
                case 'n':
                    __PROCESS_COUNT(count, args);
                    break;

                case '%':
                    __PROCESS_CHARACTER('%', count, buffer);
                    break;
                default:
                    break;
            }
        } else {
            __PROCESS_CHARACTER(character, count, buffer);
        }

        character = *++fmt;
    }

    UNUSED(text_justification);
    UNUSED(sign_prepend);
    UNUSED(number_padding);
    UNUSED(width);
    UNUSED(precision);

    return (int)count;
}
