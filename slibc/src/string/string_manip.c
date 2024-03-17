#include <string.h>

#define UNUSED(x) ((void)(x))

char *strcpy(char *dst, const char *src) {

    return memcpy(dst, src, strlen(src) + 1); /* Copy the NULL terminator */
}

char *strncpy(char *dst, const char *src, size_t count) {

    size_t len = strlen(src);
    char * orig_dst = memcpy(dst, src, count);

    if (count < len) {
        return orig_dst;
    }

    count -= len;
    dst += len;

    while (count > 0) {
        *dst = '\0';
        --count;
    }

    return orig_dst;
}

char *strcat(char *dst, const char *src) {

    size_t index = 0;
    unsigned dst_len = strlen(dst);
    unsigned src_len = strlen(src);

    for (; index < src_len; ++index) {
        dst[dst_len + index] = src[index];
    }

    dst[dst_len + index] = '\0';

    return dst;
}

char *strncat(char *dst, const char *src, size_t count) {

    size_t index = 0;
    unsigned dst_len = strlen(dst);
    unsigned src_len = strlen(src);
    src_len = (src_len < count) ? src_len : count;

    for (; index < src_len; ++index) {
        dst[dst_len + index] = src[index];
    }

    dst[dst_len + index] = '\0';

    return dst;
}

/*
TODO: Implement Locale
*/

size_t strxfrm(char *dst, const char *src, size_t count) {

    strncpy(dst, src, count);
    return 0;
}
