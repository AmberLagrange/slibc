#include <stdio.h>

#define UNUSED(x) ((void)(x))

int remove(const char *pathname) {

    UNUSED(pathname);

    return 0;
}

int rename(const char *old_filename, const char *new_filename) {

    UNUSED(old_filename);
    UNUSED(new_filename);

    return 0;
}

FILE *tmpfile(void) {

    return NULL;
}

char *tmpnam(char *filename) {

    UNUSED(filename);

    return NULL;
}
