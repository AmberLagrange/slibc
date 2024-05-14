#include "tests.h"

#include <stdlib.h>

/* NOLINTNEXTLINE(bugprone-easily-swappable-parameters, readability-non-const-parameter) */
void test_stdlib_strtol(int *passed, int *failed, int *disabled) {

    const char *number       = "1234";
    const char *negative     = "-4567";
    const char *number_hello = "   91011Hello, World!\n";
    const char *hello_world  = "Hello, World!\n";
    char *after_number;

    printf("strtol:\t\t\t\t");

    ASSERT_EQ(strtol(number, NULL, 10), 1234);
    ASSERT_EQ(strtol(negative, NULL, 10), -4567);
    ASSERT_EQ(strtol(number_hello, &after_number, 10), 91011);
    ASSERT_EQ(strtol(hello_world, &after_number, 10), 0);

    PASSED;
    UNUSED(disabled);
}

/* NOLINTNEXTLINE(bugprone-easily-swappable-parameters, readability-non-const-parameter) */
void run_stdlib_tests(int *passed, int *failed, int *disabled) {

    printf("stdlib:\n");

    test_stdlib_strtol(passed, failed, disabled);

    printf("\n");
}
