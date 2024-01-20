#include <string.h>

#define UNUSED(x) ((void)x)

size_t strlen(const char *str) {
    size_t i = 0;

    while (str[i]) {
        ++i;
    }

    return i;
}

int strcmp(const char *lhs, const char *rhs) {

    size_t lhs_len = strlen(lhs);
    size_t rhs_len = strlen(rhs);

    if (lhs_len < rhs_len) {
        return -1;
    }

    if (lhs_len > rhs_len) {
        return 1;
    }

    return memcmp(lhs, rhs, lhs_len);
}

int strncmp(const char *lhs, const char *rhs, size_t count) {

    size_t lhs_len = strlen(lhs);
    size_t rhs_len = strlen(rhs);

    if (lhs_len < count && rhs_len < count) {
        return strcmp(lhs, rhs);
    }

    if (lhs_len > count && rhs_len > count) {
        return memcmp(lhs, rhs, count);
    }

    if (lhs_len < rhs_len) {
        return memcmp(lhs, rhs, lhs_len);
    }

    return memcmp(lhs, rhs, rhs_len);

    return 0;
}

int strcoll(const char *lhs, const char *rhs) {

    return strcmp(lhs, rhs);
}

char *strchar(const char *str, int ch) {

    while(*str) {
        if (*str == (char)ch) {
            return (char*)str;
        }

        ++str;
    }

    return NULL;
}

char *strrchr(const char *str, int ch) {

    char *last = NULL;

    while(*str) {
        if (*str == (char)ch) {
            last = (char*)str;
        }

        ++str;
    }

    return last;
}

size_t strspn(const char *dst, const char *src) {

    UNUSED(dst);
    UNUSED(src);

    return 0;
}

size_t strcspn(const char *dst, const char *src) {

    UNUSED(dst);
    UNUSED(src);

    return 0;
}

char *strpbrk(const char *dst, const char *brk) {

    UNUSED(dst);
    UNUSED(brk);

    return (char*)dst;
}

char *strstr(const char *str, const char *substr) {

    UNUSED(str);
    UNUSED(substr);

    return (char*)str;
}

char *strtok(char *str, const char *token) {

    UNUSED(str);
    UNUSED(token);

    return str;
}
