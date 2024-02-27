#include <stdio.h>

#include <string.h>
#include <syscall/syscall.h>

#define UNUSED(x) ((void)x)

int fgetc(FILE *file) {

    int count;
    unsigned char c;

    count = read(file->fd, &c, 1);

    if (count == 0) {
        return EOF;
    }

    return (int)c;

    return 0;
}

int getc(FILE *file) __attribute__((weak, alias("fgetc")));

char *fgets(char *str, int count, FILE *file) {

    UNUSED(str);
    UNUSED(count);
    UNUSED(file);

    return NULL;
}

int fputc(int c, FILE *file) {

    unsigned char written;

    written = (unsigned char)c;

    write(file->fd, (char *)(&written), 1);

    return written;
}

int putc(int c, FILE *file) {

    return fputc(c, file);
}

int fputs(const char *str, FILE *file) {

    return write(file->fd, str, strlen(str));
}


int getchar(void) {

    return getc(stdin);
}

char *gets(char *str) {

    UNUSED(str);

    return NULL;
}

int putchar(int c) {

    return putc(c, stdout);
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

int ungetc(int ch, FILE *file) {

    UNUSED(ch);
    UNUSED(file);

    return 0;
}
