#include "../include/stdio.h"

#include "../include/stdlib.h"
#include "../include/string.h"

int printf(const char *fmt, ...) {
    return write(0, fmt, strlen(fmt));
}