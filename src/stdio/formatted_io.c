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
                fprintf(stderr, "Format %%%c not supported yet!\n", character_read);
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
/* NOLINTNEXTLINE(bugprone-easily-swappable-parameters) */
__attribute__((always_inline)) void __process_flags(char *character, const char **fmt_ptr, int *text_justification, int *sign_prepend, int *hash_flag, int *number_padding) {

    switch(*character) {
        case '-':
            *text_justification = LEFT_JUSTIFIED;
            *character = *(++(*fmt_ptr));
            break;
            
        case '+':
            *sign_prepend = PREPEND_SIGN_ALWAYS;
            *character = *(++(*fmt_ptr));
            break;

        case ' ':
            *sign_prepend = PREPEND_SIGN_SPACE;
            *character = *(++(*fmt_ptr));
            break;

        case '#':
            *hash_flag = HASH_FLAG_ENABLED;
            *character = *(++(*fmt_ptr));
            break;

        case '0':
            *number_padding = LEFT_PAD_ZERO;
            *character = *(++(*fmt_ptr));
            break;
        default:
            break;
    }
}

__attribute__((always_inline)) void __process_width(char *character, const char **fmt_ptr, int *width, va_list args) {

    if (*character == '*') {
        *width = va_arg(args, int);
        *character = *(++(*fmt_ptr));
    } else {
        while (isdigit(*character)) {
            *width *= DEC_RADIX;
            *width += (*character - '0');
            *character = *(++(*fmt_ptr));
        }
    }
}

__attribute__((always_inline)) void __process_precision(char *character, const char **fmt_ptr, int *precision) {

    if (*character == '.') {
        *character = *(++(*fmt_ptr));
        *precision = 0;

        while (isdigit(*character)) {
            *precision *= DEC_RADIX;
            *precision += (*character - '0');
            *character = *(++(*fmt_ptr));
        }
    }
}

__attribute__((always_inline)) void __process_length_mod(char *character, const char **fmt_ptr, int *length_mod) {

    switch (*character) {
        case 'h':
            *length_mod = SHORT_LENGTH;
            *character = *(++(*fmt_ptr));
            break;

        case 'l':
        case 'L':
            *length_mod = LONG_LENGTH;
            *character = *(++(*fmt_ptr));
            break;
        default:
            break;
    }
}

__attribute__((always_inline)) void __process_integer(size_t *count, int length_mod, char *buffer, va_list args) {

    char buf[MAX_INT_LENGTH] = {0};
    char *integer_start;

    switch (length_mod) {
        case DEFAULT_LENGTH:
        case SHORT_LENGTH: {
                            
            int va_int = va_arg(args, int);

            integer_start = __itoa_internal(va_int, buf, MAX_INT_LENGTH, DEC_RADIX, 0);
            strcat(buffer, integer_start);
            *count += strlen(integer_start);
            break;
        }

        case LONG_LENGTH: {

            long va_long = va_arg(args, long);

            integer_start = __ltoa_internal(va_long, buffer, MAX_INT_LENGTH, DEC_RADIX, 0);
            strcat(buffer, integer_start);
            *count += strlen(integer_start);
            break;
        }

        default:
            break;
    }
}

__attribute__((always_inline)) void __process_unsigned(size_t *count, int length_mod, char *buffer, va_list args) {

    char buf[MAX_INT_LENGTH] =  {0};
    char *unsigned_start;

    switch (length_mod) {
        case DEFAULT_LENGTH:
        case SHORT_LENGTH: {

            unsigned va_unsigned = va_arg(args, unsigned);

            __itoa_internal((int)va_unsigned, buf, MAX_INT_LENGTH, DEC_RADIX, 1);
            unsigned_start = strcat(buffer, buf);
            *count += strlen(unsigned_start);
            break;
        }

        case LONG_LENGTH: {

            unsigned long va_long_unsigned = va_arg(args, unsigned long);
            unsigned_start = __ltoa_internal(((long)va_long_unsigned), buf, MAX_INT_LENGTH, DEC_RADIX, 1);
            strcat(buffer, unsigned_start);
            *count += strlen(unsigned_start);
            break;
        }

        default:
            break;
    }
}

/* NOLINTNEXTLINE(bugprone-easily-swappable-parameters) */
__attribute__((always_inline)) void __process_octal_and_hex(size_t *count, int length_mod, int hash_flag, const char *prefix, int radix, char *buffer, va_list args) {

    char buf[MAX_INT_LENGTH] =  {0};
    char *integer_start;

    switch (length_mod) {
        case DEFAULT_LENGTH:
        case SHORT_LENGTH: {

            unsigned va_unsigned = va_arg(args, unsigned);

            if (va_unsigned && hash_flag) {
                strcat(buffer, prefix);
                *count += strlen(prefix);
            }

            integer_start = __itoa_internal((int)va_unsigned, buf, MAX_INT_LENGTH, radix, 1);
            strcat(buffer, integer_start);
            *count += strlen(integer_start);
            break;
        }

        case LONG_LENGTH: {

            unsigned long va_long_unsigned = va_arg(args, unsigned long);

            if (va_long_unsigned && hash_flag) {

                strcat(buffer, prefix);
                *count += strlen(prefix);
            }

            integer_start = __ltoa_internal((long)va_long_unsigned, buf, MAX_INT_LENGTH, radix, 1);
            strcat(buffer, integer_start);
            *count += strlen(integer_start);
            break;
        }

        default:
            break;
    }
}

/* NOLINTNEXTLINE(readability-non-const-parameter) */
__attribute__((always_inline)) void __process_float(size_t *count, int length_mod, char *buffer, va_list args) {

    UNUSED(count);
    UNUSED(length_mod);
    UNUSED(buffer);
    UNUSED(args);
}

__attribute__((always_inline)) void __process_char(size_t *count, char *buffer, va_list args) {

    char buf[2];
    char va_char = va_arg(args, int);
    buf[0] = va_char;
    buf[1] = '\0';
    strcat(buffer, buf);

    *count += 1;
}

__attribute__((always_inline)) void __process_str(size_t *count, char *buffer, va_list args) {

    char *va_str = va_arg(args, char*);
    strcat(buffer, va_str);

    *count += strlen(va_str);
}

__attribute__((always_inline)) void __process_pointer(size_t *count, char *buffer, va_list args) {

    char buf[MAX_INT_LENGTH] =  {0};
    char *pointer_start;

    unsigned long va_long_unsigned = (unsigned long)va_arg(args, void*);

    if (!va_long_unsigned) {

        strcat(buffer, "(nil)");
        *count += strlen("(nil)");
        return;
    }

    strcat(buffer, "0x");
    *count += strlen("0x");

    pointer_start = __ltoa_internal((long)va_long_unsigned, buf, MAX_INT_LENGTH, HEX_RADIX, 1);
    strcat(buffer, pointer_start);
    *count += strlen(pointer_start);
}

__attribute__((always_inline)) void __process_count(size_t count, va_list args) {

    int *va_int_ptr = va_arg(args, int*);
    *va_int_ptr = (int)count;
}

__attribute__((always_inline)) void __process_character(char character, size_t *count, char *buffer) {

    char buf[2];
    buf[0] = character;
    buf[1] = '\0';
    strcat(buffer, buf);
    *count += 1;
}
/* NOLINTEND(bugprone-reserved-identifier) */

int vfprintf(FILE *file, const char *fmt, va_list args) {

    char buffer[MAX_WRITE] = {0};
    int count = vsprintf(buffer, fmt, args);
    fputs(buffer, file);

    return count;
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

            __process_flags(&character, &fmt, &text_justification, &sign_prepend, &hash_flag, &number_padding);
            __process_width(&character, &fmt, &width, args);
            __process_precision(&character, &fmt, &precision);
            __process_length_mod(&character, &fmt, &length_mod);

            switch (character) {
                case 'd':
                case 'i':
                    __process_integer(&count, length_mod, buffer, args);
                    break;

                case 'u':
                    __process_unsigned(&count, length_mod, buffer, args);
                    break;

                case 'o':
                    __process_octal_and_hex(&count, length_mod, hash_flag, "0", OCT_RADIX, buffer, args);
                    break;
                
                /*
                TODO: Capitals
                */
                case 'x':
                case 'X':
                    __process_octal_and_hex(&count, length_mod, hash_flag, "0x", HEX_RADIX, buffer, args);
                    break;

                case 'f':
                    __process_float(&count, length_mod, buffer, args);
                    break;

                case 'e':
                case 'E':
                case 'g':
                case 'G':
                    abort();
                    break;

                case 'c':
                    __process_char(&count, buffer, args);
                    break;
                
                case 's':
                    __process_str(&count, buffer, args);
                    break;

                case 'p':
                    __process_pointer(&count, buffer, args);
                    break;
                
                case 'n':
                    __process_count(count, args);
                    break;

                case '%':
                    __process_character('%', &count, buffer);
                    break;
                default:
                    break;
            }
        } else {
            __process_character(character, &count, buffer);
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
