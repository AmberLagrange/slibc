#include <stdio.h>

#define UNUSED(x) ((void)(x))

FILE *fopen(const char *filename, const char *mode) {

    UNUSED(filename);
    UNUSED(mode);

    return NULL;
}

FILE *freopen(const char *filename, const char *mode, FILE *file) {

    UNUSED(filename);
    UNUSED(mode);
    UNUSED(file);


    return NULL;
}

int fclose(FILE *file) {

    UNUSED(file);

    return 0;
}

int fflush(FILE *file) {

    UNUSED(file);

    return 0;
}

void setbuf(FILE *file, char *buffer) {

    UNUSED(file);
    UNUSED(buffer);
}

int setvbuf(FILE *file, char *buffer, int mode, size_t size) {

    UNUSED(file);
    UNUSED(buffer);
    UNUSED(mode);
    UNUSED(size);

    return 0;
}
