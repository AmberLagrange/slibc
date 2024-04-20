#include "tests.h"

#include <stdio.h>
#include <string.h>

int test_stdio_fputc(void) {

    char character = 'h';

    printf("fputc:\t\t\t\t");

    ASSERT_EQ(fputc(character, stderr), character);

    PASSED;
}

int test_stdio_printf_n_specifier(void) {

    unsigned count;
    const char *hello_world = "Hello, World!\n";
    const char *empty = "";

    printf("stdio_printf_n_specifier:\t");

    fprintf(stderr, "%s%n", hello_world, &count);
    ASSERT_EQ(count, strlen(hello_world));

    printf("%s%n", empty, &count);
    ASSERT_EQ(count, strlen(empty));

    PASSED;
}

int run_stdio_tests(void) {

    int ret = 0;

    printf("stdio:\n");

    ret += test_stdio_fputc();
    ret += test_stdio_printf_n_specifier();

    printf("\n");

    return ret;
}
