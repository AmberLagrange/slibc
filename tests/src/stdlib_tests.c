#include "tests.h"

#include <stdlib.h>

int test_stdlib_strtol(void) {

    const char *number       = "1234";
    const char *negative     = "-4567";
    const char *number_hello = "   91011Hello, World!\n";
    const char *hello_world  = "Hello, World!\n";
    char *after_number;

    printf("strtol:\t");

    ASSERT_EQ(strtol(number, NULL, 10), 1234);
    ASSERT_EQ(strtol(negative, NULL, 10), -4567);
    ASSERT_EQ(strtol(number_hello, &after_number, 10), 91011);
    ASSERT_EQ(strtol(hello_world, &after_number, 10), 0);

    PASSED;
}

int run_stdlib_tests(void) {

    int ret = 0;

    printf("stdlib:\n");

    /* ret += test_stdlib_strtol(); */

    printf("\n");

    return ret;
}
