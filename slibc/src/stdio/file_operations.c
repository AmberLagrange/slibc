#include <stdio.h>

#define UNUSED(x) ((void)(x))

/* NOLINTNEXTLINE(bugprone-easily-swappable-parameters) */
int remove(const char *pathname) {

    UNUSED(pathname);

    return 0;
}

/* NOLINTNEXTLINE(bugprone-easily-swappable-parameters) */
int rename(const char *old_filename, const char *new_filename) {

    UNUSED(old_filename);
    UNUSED(new_filename);

    return 0;
}

FILE *tmpfile(void) {

    return NULL;
}

/*
TODO: Remove readability-non-const-parameter
*/
char *tmpnam(char *filename) { /* NOLINT(readability-non-const-parameter) */

    UNUSED(filename);

    return NULL;
}
