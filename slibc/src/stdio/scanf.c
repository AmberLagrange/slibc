#include <stdio.h>

#include <stdlib.h>

int scanf(const char *fmt, ...) {
    (void)fmt;
    abort();
}
