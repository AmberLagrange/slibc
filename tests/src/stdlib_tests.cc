#include <stdlib.h>
#include <gtest/gtest.h>

#include <gtest/gtest-spi.h>

TEST(stdlib, strtol) {

    const char *number       = "1234";
    const char *negative     = "-4567";
    const char *number_hello = "   91011Hello, World!\n";
    const char *hello_world  = "Hello, World!\n";
    char *after_number;

    ASSERT_EQ(strtol(number, NULL, 10), 1234);
    ASSERT_EQ(strtol(negative, NULL, 10), -4567);
    ASSERT_EQ(strtol(number_hello, &after_number, 10), 91011);
    ASSERT_EQ(strcmp(hello_world, after_number), 0);
}