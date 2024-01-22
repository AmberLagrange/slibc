#include <string.h>
#include <gtest/gtest.h>

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
    const char *hello = "Hello";
    const char *world = ", World!";
    const char *hello_world = "Hello, World!";

    strcat(buf, hello);
    ASSERT_EQ(strcmp(buf, hello), 0);

    strcat(buf, world);
    ASSERT_EQ(strcmp(buf, hello_world), 0); 
}

TEST(string, strxfrm) {
    FAIL();
}

TEST(string, strlen) {

    const char *hello_world = "Hello, World!";
    const char *empty       = "";

    ASSERT_EQ(strlen(hello_world), 13);
    ASSERT_EQ(strlen(empty), 0);
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

#include <stdio.h>

TEST(string, memcpy) {
    
    unsigned i;

    char src[8] = { 0xd, 0xe, 0xa, 0xd, 0xb, 0xe, 0xe, 0xf };
    char dst[8] = { 0 };

    unsigned size = sizeof(src) / sizeof(src[0]);

    for (i = 0; i < size; ++i) {
        ASSERT_EQ(dst[i], 0);
    }

    memcpy(dst, src, size);

    for (i = 0; i < size; ++i) {
        ASSERT_EQ(dst[i], src[i]);
    }
    
}
