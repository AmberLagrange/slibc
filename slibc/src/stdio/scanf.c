#include <stdio.h>

#include <ctype.h>
#include <stdarg.h>
#include <stdlib.h>
#include <syscall/syscall.h>

/*
TODO: Properly implement scanf, currently doesn't use
      fmt and only returns a digit read.
*/

#define MAX_READ 256

int scanf(const char *fmt, ...) {

    va_list args;
    char buf[MAX_READ];
    int *va_int_ptr;
    int c;
    int count = 0;

    va_start(args, fmt);

    while ((c = getchar()) != EOF && count < MAX_READ - 1) {

        if (!isdigit(c)) {
            break;
        }

        buf[count++] = (char)c;
    }

    buf[count] = '\0';

    va_int_ptr = va_arg(args, int *);
    *va_int_ptr = atoi(buf);

    va_end(args);

    return 1;
}
