#include <stdio.h>

#define UNUSED(x) ((void)(x))

int remove(const char *pathname) { /* NOLINT(bugprone-easily-swappable-parameters) */

    UNUSED(pathname);

    return 0;
}

int rename(const char *old_filename, const char *new_filename) { /* NOLINT(bugprone-easily-swappable-parameters) */

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
