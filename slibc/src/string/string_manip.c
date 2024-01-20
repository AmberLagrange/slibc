#include <string.h>

#define UNUSED(x) ((void)x)

char *strcpy(char *dst, const char *src) {

    return memcpy(dst, src, strlen(src));
}

char *strncpy(char *dst, const char *src, size_t count) {

    return memcpy(dst, src, count);
}

char *strcat(char *dst, const char *src) {

    unsigned i;
    unsigned dst_len = strlen(dst);
    unsigned src_len = strlen(src);

    for (i = 0; i < src_len; ++i) {
        dst[dst_len + i] = src[i];
    }

    dst[dst_len + i] = '\0';

    return dst;
}

char *strncat(char *dst, const char *src, size_t count) {

    unsigned i;
    unsigned dst_len = strlen(dst);
    unsigned src_len = strlen(src);
    src_len = (src_len < count) ? src_len : count;

    for (i = 0; i < src_len; ++i) {
        dst[dst_len + i] = src[i];
    }

    dst[dst_len + i] = '\0';

    return dst;
}

size_t strxfrm(char *dst, const char *src, size_t count) {

    UNUSED(dst);
    UNUSED(src);
    UNUSED(count);

    return 0;
}
