#include <stdio.h>

#define UNUSED(x) ((void)(x))

FILE *fopen(const char *filename, const char *mode) { /* NOLINT(bugprone-easily-swappable-parameters) */

    UNUSED(filename);
    UNUSED(mode);

    return NULL;
}

FILE *freopen(const char *filename, const char *mode, FILE *file) { /* NOLINT(bugprone-easily-swappable-parameters) */

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

/*
TODO: Remove readability-non-const-parameter
*/
void setbuf(FILE *file, char *buffer) { /* NOLINT(readability-non-const-parameter) */

    UNUSED(file);
    UNUSED(buffer);
}

/*
TODO: Remove readability-non-const-parameter
*/
int setvbuf(FILE *file, char *buffer, int mode, size_t size) { /* NOLINT(bugprone-easily-swappable-parameters,readability-non-const-parameter) */

    UNUSED(file);
    UNUSED(buffer);
    UNUSED(mode);
    UNUSED(size);

    return 0;
}
