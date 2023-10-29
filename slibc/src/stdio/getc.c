#include <stdio.h>

#include <syscall/syscall.h>

int getc(FILE *file) {

    int count;
    unsigned char c;

    count = read(file->fd, &c, 1);

    if (count == 0) {
        return EOF;
    }

    return (int)c;
}

int getchar(void) {
    return getc(stdin);
}
