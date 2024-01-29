#include <stdio.h>

#define UNUSED(x) ((void)(x))

size_t fread(void *buffer, size_t size, size_t count, FILE *file) {

    UNUSED(buffer);
    UNUSED(size);
    UNUSED(count);
    UNUSED(file);

    return 0;
}

size_t fwrite(const void *buffer, size_t size, size_t count, FILE *file) {

    UNUSED(buffer);
    UNUSED(size);
    UNUSED(count);
    UNUSED(file);

    return 0;
}
