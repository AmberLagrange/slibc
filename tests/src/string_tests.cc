#include <string.h>
#include <gtest/gtest.h>

TEST(string, strlen) {

    const char *hello_world = "Hello, World!";
    const char *empty = "";

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
