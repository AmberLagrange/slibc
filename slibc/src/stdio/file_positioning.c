#include <stdio.h>

#define UNUSED(x) ((void)(x))

long ftell(FILE *file) {

    UNUSED(file);

    return 0L;
}

int fgetpos(FILE *file, fpos_t *pos) {

    UNUSED(file);
    UNUSED(pos);

    return 0;
}

int fseek(FILE *file, long offset, int origin) { /* NOLINT(bugprone-easily-swappable-parameters) */

    UNUSED(file);
    UNUSED(offset);
    UNUSED(origin);

    return 0;
}

int fsetpos(FILE *file, const fpos_t *pos) {

    UNUSED(file);
    UNUSED(pos);
    
    return 0;
}

void rewind(FILE *file) {

    UNUSED(file);
}
