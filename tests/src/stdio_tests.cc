#include <stdio.h>
#include <gtest/gtest.h>

TEST(stdio, fputc) {

    char character = 'h';

    ASSERT_EQ(fputc(character, stderr), character);
}

TEST(stdio, printf_n_specifier) {

    int count;
    const char *hello_world = "Hello, World!\n";
    const char *empty = "";

    printf("%s%n", hello_world, &count);
    ASSERT_EQ(count, strlen(hello_world));

    printf("%s%n", empty, &count);
    ASSERT_EQ(count, strlen(empty));
}
