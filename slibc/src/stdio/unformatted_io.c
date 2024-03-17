#include <stdio.h>

#include <string.h>
#include <syscall/syscall.h>

#define UNUSED(x) ((void)(x))

int fgetc(FILE *file) {

    unsigned char character = 0;
    int count = read(file->fd, &character, 1);

    if (count == 0) {
        return EOF;
    }

    return (int)character;

    return 0;
}

int getc(FILE *file) __attribute__((weak, alias("fgetc")));

/*
TODO: Remove readability-non-const-parameter
*/
char *fgets(char *str, int count, FILE *file) { /* NOLINT(readability-non-const-parameter) */

    UNUSED(str);
    UNUSED(count);
    UNUSED(file);

    return NULL;
}

int fputc(int character, FILE *file) {

    unsigned char written = (unsigned char)character;

    write(file->fd, (char *)(&written), 1);

    return written;
}

int putc(int character, FILE *file) {

    return fputc(character, file);
}

int fputs(const char *str, FILE *file) {

    return write(file->fd, str, (int)strlen(str));
}

int getchar(void) {

    return getc(stdin);
}

/*
TODO: Remove readability-non-const-parameter
*/
char *gets(char *str) { /* NOLINT(readability-non-const-parameter) */

    UNUSED(str);

    return NULL;
}

int putchar(int character) {

    return putc(character, stdout);
}

int puts(const char *str) {

    int ret_1 = 0;
    int ret_2 = 0;

    ret_1 = fputs(str, stdout);
    if (ret_1 < 0) {
        return ret_1;
    }

    ret_2 = putchar('\n');
    if (ret_2 < 0) {
        return ret_2;
    }

    return ret_1 + 1;

}

int ungetc(int character, FILE *file) {

    UNUSED(character);
    UNUSED(file);

    return 0;
}
