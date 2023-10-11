#include <stdio.h>

#include <string.h>
#include <syscall/syscall.h>

int fputc(int c, FILE *file) {

    unsigned char written;

    written = (unsigned char)c;

    write(file->fd, (char *)(&written), 1);

    return written;
}

int putc(int c, FILE *file) {
    return fputc(c, file);
}

int putchar(int c) {
    return putc(c, stdout);
}

int fputs(const char *str, FILE *file) {
    return write(file->fd, str, strlen(str));
}

int puts(const char *str) {

    int ret_1;
    int ret_2;

    ret_1 = fputs(str, stdout);
    if (ret_1 < 0) return ret_1;

    ret_2 = putchar('\n');
    if (ret_2 < 0) return ret_2;

    return ret_1 + 1;

}
