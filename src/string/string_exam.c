#include <string.h>

#define UNUSED(x) ((void)(x))

size_t strlen(const char *str) {
    
    size_t len = 0;

    while (str[len]) {
        ++len;
    }

    return len;
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

char *strchr(const char *str, int character) {

    while(*str) {
        if (*str == (char)character) {
            return (char*)str;
        }

        ++str;
    }

    return NULL;
}

char *strrchr(const char *str, int character) {

    char *last = NULL;

    while(*str) {
        if (*str == (char)character) {
            last = (char*)str;
        }

        ++str;
    }

    return last;
}

size_t strspn(const char *dst, const char *src) {

    size_t index = 0;
    int contains = 0;

    size_t count = 0;
    size_t src_len = strlen(src);

    while(*dst) {
        
        contains = 0;

        for (index = 0; index < src_len; ++index) {

            if (*dst == src[index]) {
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

    size_t index = 0;
    int contains = 0;

    size_t count = 0;
    size_t src_len = strlen(src);

    while(*dst) {
        
        contains = 0;

        for (index = 0; index < src_len; ++index) {

            if (*dst == src[index]) {
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

    size_t index = 0;

    char *loc = NULL;
    size_t set_len = strlen(set);

    while (*dst) {

        for (index = 0; index < set_len; ++index) {

            if (*dst == set[index]) {
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

    size_t index = 0;
    int found    = 1;

    char *loc = NULL;
    size_t substr_len = strlen(substr);

    while(*str) {

        found = 1;

        for (index = 0; index < substr_len; ++index) {

            if (str[index] != substr[index]) {

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
