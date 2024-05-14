#include "tests.h"

#include <stdio.h>
#include <string.h>

/* NOLINTNEXTLINE(bugprone-easily-swappable-parameters, readability-non-const-parameter) */
void test_stdio_fputc(int *passed, int *failed, int *disabled) {

    char character = 'h';

    printf("fputc:\t\t\t\t");

    ASSERT_EQ(fputc(character, stderr), character);

    PASSED;
    UNUSED(disabled);
}

/* NOLINTNEXTLINE(bugprone-easily-swappable-parameters, readability-non-const-parameter) */
void test_stdio_printf_n_specifier(int *passed, int *failed, int *disabled) {

    unsigned count;
    const char *hello_world = "Hello, World!\n";
    const char *empty = "";

    printf("stdio_printf_n_specifier:\t");

    fprintf(stderr, "%s%n", hello_world, &count);
    ASSERT_EQ(count, strlen(hello_world));

    printf("%s%n", empty, &count);
    ASSERT_EQ(count, strlen(empty));

    PASSED;
    UNUSED(disabled);
}

void run_stdio_tests(int *passed, int *failed, int *disabled) {

    printf("stdio:\n");

    test_stdio_fputc(passed, failed, disabled);
    test_stdio_printf_n_specifier(passed, failed, disabled);

    printf("\n");
}
