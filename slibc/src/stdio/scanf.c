#include <stdio.h>

#include <stdarg.h>
#include <stdlib.h>
#include <syscall/syscall.h>

/*
TODO: Properly implement scanf, currently doesn't use
      fmt and only returns a digit read.
*/

int scanf(const char *fmt, ...) {

    va_list args;
    char buf[256];
    int *va_int_ptr;
    int count;

    va_start(args, fmt);

    count = read(stdin->fd, buf, 256);
    buf[count - 1] = '\0'; /* count includes newline, so remove the trailing newline and replace it with NULL */

    va_int_ptr = va_arg(args, int *);
    *va_int_ptr = atoi(buf);

    va_end(args);

    return 0;
}
