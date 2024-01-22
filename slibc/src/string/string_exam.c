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

/*
TODO: Implement Locale
*/

int strcoll(const char *lhs, const char *rhs) {

    return strcmp(lhs, rhs);
}

char *strchr(const char *str, int ch) {

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

    unsigned i;
    int contains;

    size_t count = 0;
    size_t src_len = strlen(src);

    while(*dst) {
        
        contains = 0;

        for (i = 0; i < src_len; ++i) {

            if (*dst == src[i]) {
                ++count;
                contains = 1;
                break;
            }
        }

        if (!contains) {
            break;
        }

        ++dst;
    }

    return count;
}

size_t strcspn(const char *dst, const char *src) {

    unsigned i;
    int contains;

    size_t count = 0;
    size_t src_len = strlen(src);

    while(*dst) {
        
        contains = 0;

        for (i = 0; i < src_len; ++i) {

            if (*dst == src[i]) {
                contains = 1;
                break;
            }
        }

        if (contains) {
            break;
        }

        ++count;
        ++dst;
    }

    return count;
}

char *strpbrk(const char *dst, const char *set) {

    unsigned i;

    char *loc = NULL;
    size_t set_len = strlen(set);

    while (*dst) {

        for (i = 0; i < set_len; ++i) {

            if (*dst == set[i]) {
                loc = (char *)(dst);
                break;
            }
        }

        if (loc) {
            break;
        }

        ++dst;
    }

    return loc;
}

char *strstr(const char *str, const char *substr) {

    unsigned i;
    int found;

    char *loc = NULL;
    size_t substr_len = strlen(substr);

    while(*str) {

        found = 1;

        for (i = 0; i < substr_len; ++i) {

            if (str[i] != substr[i]) {

                found = 0;
                break;
            }
        }

        if (found) {

            loc = (char *)(str);
            break;
        }

        ++str;
    }

    return loc;
}

/*
TODO: Implement strtok
*/

char *strtok(char *str, const char *token) {

    UNUSED(str);
    UNUSED(token);

    return str;
}
