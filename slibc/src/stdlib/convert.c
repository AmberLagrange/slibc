#include <stdlib.h>
#include <string.h>
#include <stdlib/convert.h>

static const char NUMERALS[16] = "0123456789abcdef";

/* TODO: Implement unused */
#define UNUSED(x) ((void)(x))

char *__itoa__internal(int int_val, char *buf, size_t len, enum __radix_e radix, int is_unsigned) { /* NOLINT (bugprone-easily-swappable-parameters)*/

    unsigned unsigned_val = 0;
    int is_negative = 0;
    char *str = &(buf[len - 1]);
    buf[len] = '\0';

    if (int_val == 0) {
        *str = '0';
        return str;
    }

    if (is_unsigned) {
        unsigned_val = (unsigned)int_val;

        while (unsigned_val) {
            --str;
            *str = NUMERALS[unsigned_val % radix];
            unsigned_val /= radix;
        }
    } else {
        if (int_val < 0) {
            is_negative = 1;
            int_val = -int_val;
        }

        while (int_val) {
            --str;
            *str = NUMERALS[int_val % radix];
            int_val /= (int)radix;
        }

        if (is_negative) {
            --str;
            *str = '-';
        }
    }

    return str;
}

char *__ltoa__internal(long long_val, char *buf, size_t len, enum __radix_e radix, int is_unsigned) { /* NOLINT (bugprone-easily-swappable-parameters)*/

    unsigned long long_unsigned_val = 0;
    int is_negative = 0;
    char *str = &(buf[len - 1]);
    buf[len] = '\0';

    if (long_val == 0) {
        *str = '0';
        return str;
    }

    if (is_unsigned) {

        long_unsigned_val = (unsigned long)long_val;

        while (long_unsigned_val) {
            --str;
            *str = NUMERALS[long_unsigned_val % radix];
            long_unsigned_val /= radix;
        }
    } else {
        if (long_val < 0) {
            is_negative = 1;
            long_val = -long_val;
        }

        while (long_val) {
            --str;
            *str = NUMERALS[long_val % radix];
            long_val /= radix;
        }

        if (is_negative) {
            --str;
            *str = '-';
        }
    }

    return str;
}

double atof(const char *str) {
    UNUSED(str);

    return 0;
}

int atoi(const char *str) {

    int num = 0;
    size_t len = strlen(str);
    size_t index = 0;

    for (; index < len; ++index) {
        num *= DEC_RADIX;
        num += str[index] - '0';
    }

    return num;
}

long atol(const char *str) {
    UNUSED(str);
    
    return 0;
}

/*
TODO: Properly implement strtol
*/

long strtol(const char *str, char **str_end, int radix) {
    UNUSED(str_end);
    UNUSED(radix);
    
    return atoi(str); /* NOLINT */
}

unsigned long strtoul(const char *str, char **str_end, int radix) {
    UNUSED(str);
    UNUSED(str_end);
    UNUSED(radix);
    
    return 0;
}

double strtod(const char *str, char **str_end) {
    UNUSED(str);
    UNUSED(str_end);
    
    return 0;
}
