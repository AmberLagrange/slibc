#include <string.h>
#include <gtest/gtest.h>

/*
String Manipulation Tests
*/

TEST(string, strcpy) {

    char buf[16];
    const char *hello_world = "Hello, World!";
    const char *empty       = "";

    memset(buf, 0xff, sizeof(buf) / sizeof(buf[0]));

    strcpy(buf, hello_world);
    ASSERT_EQ(strcmp(buf, hello_world), 0);

    strcpy(buf, empty);
    ASSERT_EQ(buf[0], '\0');
}

#include <iostream>

TEST(string, strncpy) {

    char buf[16];
    const char *hello_world = "Hello, World!";
    const char *empty       = "";

    size_t len = strlen(hello_world);

    memset(buf, 0xff, sizeof(buf) / sizeof(buf[0]));

    strncpy(buf, hello_world, len + 1);
    ASSERT_EQ(strcmp(buf, hello_world), 0);
    ASSERT_EQ(buf[len + 2], (char)0xff);

    strncpy(buf, empty, 1);
    ASSERT_EQ(buf[0], '\0');
    ASSERT_NE(buf[1], '\0');

    strncpy(buf, empty, 2);
    ASSERT_EQ(buf[0], '\0');
    ASSERT_EQ(buf[1], '\0');
}

TEST(string, strcat) {
    
    char buf[16] = "";
    const char *hello       = "Hello,";
    const char *world       = " World!";
    const char *hello_world = "Hello, World!";

    strcat(buf, hello);
    ASSERT_EQ(strcmp(buf, hello), 0);

    strcat(buf, world);
    ASSERT_EQ(strcmp(buf, hello_world), 0); 
}

TEST(string, strxfrm) {

    FAIL();
}

/*
String Examination Tests
*/

TEST(string, strlen) {

    const char *hello_world = "Hello, World!";
    const char *empty       = "";

    ASSERT_EQ(strlen(hello_world), 13);
    ASSERT_EQ(strlen(empty), 0);
}

TEST(string, strcmp) {

    const char *hello         = "Hello,";
    const char *world         = " World";
    const char *hello_world   = "Hello, World!";
    const char *hello_world_2 = "Hello, World!";
    const char *empty         = "";

    ASSERT_LT(strcmp(empty, hello), 0);
    ASSERT_GT(strcmp(world, empty), 0);

    ASSERT_LT(strcmp(world, hello), 0);
    ASSERT_GT(strcmp(hello, world), 0);

    ASSERT_EQ(strcmp(hello_world, hello_world_2), 0);
}

TEST(string, strncmp) {

    const char *hello         = "Hello,";
    const char *world         = " World";
    const char *hello_world   = "Hello, World!";
    const char *hello_world_2 = "Hello, World! 2";
    const char *space         = "  ";

    size_t len_1 = strlen(hello);
    size_t len_2 = strlen(hello_world);

    ASSERT_LT(strncmp(space, hello, 1), 0);
    ASSERT_EQ(strncmp(space, world, 1), 0);

    ASSERT_LT(strncmp(space, hello, 2), 0);
    ASSERT_LT(strncmp(space, world, 2), 0);

    ASSERT_LT(strncmp(world, hello, len_1), 0);
    ASSERT_GT(strncmp(hello, world, len_1), 0);

    ASSERT_EQ(strncmp(hello_world, hello_world_2, len_2), 0);
}

TEST(string, strcoll) {
    
    const char *hello         = "Hello,";
    const char *world         = " World";
    const char *hello_world   = "Hello, World!";
    const char *hello_world_2 = "Hello, World!";
    const char *empty         = "";

    ASSERT_LT(strcoll(empty, hello), 0);
    ASSERT_GT(strcoll(world, empty), 0);

    ASSERT_LT(strcoll(world, hello), 0);
    ASSERT_GT(strcoll(hello, world), 0);

    ASSERT_EQ(strcoll(hello_world, hello_world_2), 0);
}

TEST(string, strchr) {

    const char *hello_world = "Hello, World!";

    ASSERT_EQ(strchr(hello_world, 'H'), (char *)(hello_world));
    ASSERT_EQ(strchr(hello_world, 'l'), (char *)(hello_world + 2));
    ASSERT_EQ(strchr(hello_world, '.'), (char *)(NULL));
}

TEST(string, strrchr) {

    const char *hello_world = "Hello, World!";

    ASSERT_EQ(strrchr(hello_world, 'H'), (char *)(hello_world));
    ASSERT_EQ(strrchr(hello_world, 'l'), (char *)(hello_world + 10));
    ASSERT_EQ(strrchr(hello_world, '.'), (char *)(NULL));
}

TEST(string, strspn) {
    
    const char *str             = "lowercase and numbers 12345";
    const char *lower_and_space = "abcdefghijklmnopqrstuvwxyz ";
    const char *lower_no_space  = "abcdefghijklmnopqrstuvwxyz";
    const char *missing         = "!";

    size_t len = strlen(str);

    ASSERT_EQ(strspn(str, lower_and_space), 22);
    ASSERT_EQ(strspn(str, lower_no_space), 9);
    ASSERT_EQ(strspn(str, missing), 0);
    ASSERT_EQ(strspn(str, str), len);
}

TEST(string, strcspn) {
    
    const char *str     = "Hello, World!";
    const char *lower   = "abcdefghijklmnopqrstuvwxyz";
    const char *space   = " ";
    const char *missing = ".";

    size_t len = strlen(str);

    ASSERT_EQ(strcspn(str, lower), 1);
    ASSERT_EQ(strcspn(str, space), 6);
    ASSERT_EQ(strcspn(str, missing), len);
    ASSERT_EQ(strcspn(str, str), 0);
}

TEST(string, strpbrk) {

    const char *str     = "Hello, World!";
    const char *world_1 = ", World!";
    const char *world_2 = " World!";
    const char *brk_1   = ", ";
    const char *brk_2   = " ";
    const char *missing = ".";

    ASSERT_EQ(strcmp(strpbrk(str, brk_1), world_1), 0);
    ASSERT_EQ(strcmp(strpbrk(str, brk_2), world_2), 0);
    ASSERT_EQ(strpbrk(str, missing), (char *)(NULL));
}

TEST(string, strstr) {

    const char *str       = "One Two One Three";
    const char *one       = "One";
    const char *one_two   = "One Two";
    const char *one_three = "One Three";
    const char *missing   = "Four";

    ASSERT_EQ(strcmp(strstr(str, one), str), 0);
    ASSERT_EQ(strcmp(strstr(str, one_two), str), 0);
    ASSERT_EQ(strcmp(strstr(str, one_three), one_three), 0);
    ASSERT_EQ(strstr(str, missing), (char *)(NULL));
}

TEST(string, strtok) {
    
    FAIL();
}

/*
Char Array Manipulation Tests
*/

TEST(string, memchr) {

    char buf[16] = {
        '0', '1', '2', '3',
        '4', '5', '6', '7',
        '8', '9', 'a', 'b',
        'c', 'd', 'e', 'f'
    };

    unsigned size = sizeof(buf) / sizeof(buf[0]);

    ASSERT_EQ(memchr(buf, '0', size    ), (char *)(buf + 0));
    ASSERT_EQ(memchr(buf, '8', size    ), (char *)(buf + 8));
    ASSERT_EQ(memchr(buf, 'f', size    ), (char *)(buf + 15));
    ASSERT_EQ(memchr(buf, 'f', size - 1), (char *)(NULL));
    ASSERT_EQ(memchr(buf, ' ', size    ), (char *)(NULL));
}

TEST(string, memcmp) {

    char buf_1[4] = { 0, 1, 2, 3 };
    char buf_2[4] = { 0, 1, 2, 3 };
    char buf_3[4] = { 0, 0, 0, 0 };

    size_t size = sizeof(buf_1) / sizeof(buf_1[0]);

    ASSERT_EQ(memcmp(buf_1, buf_2, size), 0);
    ASSERT_GT(memcmp(buf_1, buf_3, size), 0);
    ASSERT_LT(memcmp(buf_3, buf_2, size), 0);

    ASSERT_EQ(memcmp(buf_1, buf_3, 1), 0);
}

TEST(string, memset) {

    unsigned i;

    char buf[16] = { 0 };
    unsigned size = sizeof(buf) / sizeof(buf[0]);

    for (i = 0; i < size; ++i) {
        ASSERT_EQ(buf[i], 0);
    }

    memset(buf, 1, size);

    for (i = 0; i < size; ++i) {
        ASSERT_EQ(buf[i], 1);
    }

}

TEST(string, memmove) {

    char buf_1[4] = { 0, 1, 2, 3 };
    char buf_2[4] = { 1, 2, 3, 3 };

    size_t size = sizeof(buf_1) / sizeof(buf_1[0]);

    ASSERT_NE(memcmp(buf_1, buf_2, size), 0);
    memmove(buf_1, buf_1 + 1, size - 1);
    ASSERT_EQ(memcmp(buf_1, buf_2, size), 0);
}

TEST(string, memcpy) {

    char buf_1[8] = { 0 };
    char buf_2[8] = { 0xd, 0xe, 0xa, 0xd, 0xb, 0xe, 0xe, 0xf };

    size_t size = sizeof(buf_1) / sizeof(buf_1[0]);

    ASSERT_NE(memcmp(buf_1, buf_2, size), 0);
    memcpy(buf_1, buf_2, size);
    ASSERT_EQ(memcmp(buf_1, buf_2, size), 0);
    
}

/* Misc Tests */

TEST(string, strerror) {

    FAIL();
}
