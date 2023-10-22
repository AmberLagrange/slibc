#include <stdlib.h>
#include <string.h>
#include <stdlib/convert.h>

static const char NUMERALS[16] = "0123456789abcdef";

/* TODO: Implement unused */
#define UNUSED(x) (void)(x)

char *__itoa__internal(int i, char *buf, int len, int base, int is_unsigned) {

    unsigned u;
    int is_negative = 0;
    char *str = &(buf[len - 1]);
    buf[len] = '\0';

    if (i == 0) {
        *str = '0';
        return str;
    }

    if (is_unsigned) {
        u = (unsigned)i;

        while (u) {
            --str;
            *str = NUMERALS[u % base];
            u /= base;
        }
    } else {
        if (i < 0) {
            is_negative = 1;
            i = -i;
        }

        while (i) {
            --str;
            *str = NUMERALS[i % base];
            i /= base;
        }

        if (is_negative) {
            --str;
            *str = '-';
        }
    }

    return str;
}

char *__ltoa__internal(long l, char *buf, int len, int base, int is_unsigned) {

    unsigned long lu;
    int is_negative = 0;
    char *str = &(buf[len - 1]);
    buf[len] = '\0';

    if (l == 0) {
        *str = '0';
        return str;
    }

    if (is_unsigned) {

        lu = (unsigned long)l;

        while (lu) {
            --str;
            *str = NUMERALS[lu % base];
            lu /= base;
        }
    } else {
        if (l < 0) {
            is_negative = 1;
            l = -l;
        }

        while (l) {
            --str;
            *str = NUMERALS[l % base];
            l /= base;
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

    return 1234.5678;
}

int atoi(const char *str) {

    int num;
    int len;
    int i;

    num = 0;
    len = strlen(str);

    for (i = 0; i < len; ++i) {
        num *= 10;
        num += str[i] - '0';
    }

    return num;
}

long atol(const char *str) {
    UNUSED(str);
    
    return 0x1234;
}

long strtol(const char *str, char **str_end, int base) {
    UNUSED(str);
    UNUSED(str_end);
    UNUSED(base);
    
    return 0x1234;
}

unsigned long strtoul(const char *str, char **str_end, int base) {
    UNUSED(str);
    UNUSED(str_end);
    UNUSED(base);
    
    return 0x1234;
}

double strtod(const char *str, char **str_end) {
    UNUSED(str);
    UNUSED(str_end);
    
    return 1234.5678;
}
