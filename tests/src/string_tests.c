#include "tests.h"

#include <string.h>

enum {
    BUFFER_SIZE = 16,
    FILL_DATA   = 0xff,
    D           = 0xd,
    E           = 0xe,
    A           = 0xa,
    B           = 0xb,
    F           = 0xf
};

/*
String Manipulation Tests
*/

int test_string_strcpy(void) {

    char buf[BUFFER_SIZE];
    const char *hello_world = "Hello, World!";
    const char *empty       = "";

    printf("strcpy:\t\t\t\t");

    memset(buf, FILL_DATA, sizeof(buf) / sizeof(buf[0]));

    strcpy(buf, hello_world);
    ASSERT_EQ(strcmp(buf, hello_world), 0);

    strcpy(buf, empty);
    ASSERT_EQ(buf[0], '\0');

    PASSED;
}

int test_string_strncpy(void) {

    char buf[BUFFER_SIZE];
    const char *hello_world = "Hello, World!";
    const char *empty       = "";

    size_t len = strlen(hello_world);

    printf("strncpy:\t\t\t");

    memset(buf, FILL_DATA, sizeof(buf) / sizeof(buf[0]));

    strncpy(buf, hello_world, len + 1);
    ASSERT_EQ(strcmp(buf, hello_world), 0);
    ASSERT_EQ(buf[len + 2], (char)0xff);

    strncpy(buf, empty, 1);
    ASSERT_EQ(buf[0], '\0');
    ASSERT_NE(buf[1], '\0');

    strncpy(buf, empty, 2);
    ASSERT_EQ(buf[0], '\0');
    ASSERT_EQ(buf[1], '\0');

    PASSED;
}

int test_string_strcat(void) {
    
    char buf[BUFFER_SIZE] = "";
    const char *hello       = "Hello,";
    const char *world       = " World!";
    const char *hello_world = "Hello, World!";

    printf("strcat:\t\t\t\t");

    strcat(buf, hello);
    ASSERT_EQ(strcmp(buf, hello), 0);

    strcat(buf, world);
    ASSERT_EQ(strcmp(buf, hello_world), 0);

    PASSED;
}

int test_string_strxfrm(void) {

    printf("strxfrm:\t\t\t");

    DISABLED;
}

/*
String Examination Tests
*/

int test_string_strlen(void) {

    const char *hello_world = "Hello, World!";
    const char *empty       = "";

    printf("strlen:\t\t\t\t");

    ASSERT_EQ(strlen(hello_world), 13);
    ASSERT_EQ(strlen(empty), 0);

    PASSED;
}

int test_string_strcmp(void) {

    const char *hello         = "Hello,";
    const char *world         = " World";
    const char *hello_world   = "Hello, World!";
    const char *hello_world_2 = "Hello, World!";
    const char *empty         = "";
    
    printf("strcmp:\t\t\t\t");

    ASSERT_LT(strcmp(empty, hello), 0);
    ASSERT_GT(strcmp(world, empty), 0);

    ASSERT_LT(strcmp(world, hello), 0);
    ASSERT_GT(strcmp(hello, world), 0);

    ASSERT_EQ(strcmp(hello_world, hello_world_2), 0);

    PASSED;
}

int test_string_strncmp(void) {

    const char *hello         = "Hello,";
    const char *world         = " World";
    const char *hello_world   = "Hello, World!";
    const char *hello_world_2 = "Hello, World! 2";
    const char *space         = "  ";

    size_t len_1 = strlen(hello);
    size_t len_2 = strlen(hello_world);

    printf("strncmp:\t\t\t");

    ASSERT_LT(strncmp(space, hello, 1), 0);
    ASSERT_EQ(strncmp(space, world, 1), 0);

    ASSERT_LT(strncmp(space, hello, 2), 0);
    ASSERT_LT(strncmp(space, world, 2), 0);

    ASSERT_LT(strncmp(world, hello, len_1), 0);
    ASSERT_GT(strncmp(hello, world, len_1), 0);

    ASSERT_EQ(strncmp(hello_world, hello_world_2, len_2), 0);

    PASSED;
}

int test_string_strcoll(void) {
    
    const char *hello         = "Hello,";
    const char *world         = " World";
    const char *hello_world   = "Hello, World!";
    const char *hello_world_2 = "Hello, World!";
    const char *empty         = "";

    printf("strcoll:\t\t\t");

    ASSERT_LT(strcoll(empty, hello), 0);
    ASSERT_GT(strcoll(world, empty), 0);

    ASSERT_LT(strcoll(world, hello), 0);
    ASSERT_GT(strcoll(hello, world), 0);

    ASSERT_EQ(strcoll(hello_world, hello_world_2), 0);

    PASSED;
}

int test_string_strchr(void) {

    const char *hello_world = "Hello, World!";

    printf("strchr:\t\t\t\t");

    ASSERT_EQ(strchr(hello_world, 'H'), (char *)(hello_world));
    ASSERT_EQ(strchr(hello_world, 'l'), (char *)(hello_world + 2));
    ASSERT_EQ(strchr(hello_world, '.'), (char *)(NULL));

    PASSED;
}

int test_string_strrchr(void) {

    const char *hello_world = "Hello, World!";

    printf("strrchr:\t\t\t");

    ASSERT_EQ(strrchr(hello_world, 'H'), (char *)(hello_world));
    ASSERT_EQ(strrchr(hello_world, 'l'), (char *)(hello_world + 10));
    ASSERT_EQ(strrchr(hello_world, '.'), (char *)(NULL));

    PASSED;
}

int test_string_strspn(void) {
    
    const char *str             = "lowercase and numbers 12345";
    const char *lower_and_space = "abcdefghijklmnopqrstuvwxyz ";
    const char *lower_no_space  = "abcdefghijklmnopqrstuvwxyz";
    const char *missing         = "!";

    size_t len = strlen(str);

    printf("strspn:\t\t\t\t");

    ASSERT_EQ(strspn(str, lower_and_space), 22);
    ASSERT_EQ(strspn(str, lower_no_space), 9);
    ASSERT_EQ(strspn(str, missing), 0);
    ASSERT_EQ(strspn(str, str), len);

    PASSED;
}

int test_string_strcspn(void) {
    
    const char *str     = "Hello, World!";
    const char *lower   = "abcdefghijklmnopqrstuvwxyz";
    const char *space   = " ";
    const char *missing = ".";

    size_t len = strlen(str);

    printf("strcspn:\t\t\t");

    ASSERT_EQ(strcspn(str, lower), 1);
    ASSERT_EQ(strcspn(str, space), 6);
    ASSERT_EQ(strcspn(str, missing), len);
    ASSERT_EQ(strcspn(str, str), 0);

    PASSED;
}

int test_string_strpbrk(void) {

    const char *str     = "Hello, World!";
    const char *world_1 = ", World!";
    const char *world_2 = " World!";
    const char *brk_1   = ", ";
    const char *brk_2   = " ";
    const char *missing = ".";

    printf("strpbrk:\t\t\t");

    ASSERT_EQ(strcmp(strpbrk(str, brk_1), world_1), 0);
    ASSERT_EQ(strcmp(strpbrk(str, brk_2), world_2), 0);
    ASSERT_EQ(strpbrk(str, missing), (char *)(NULL));

    PASSED;
}

int test_string_strstr(void) {

    const char *str       = "One Two One Three";
    const char *one       = "One";
    const char *one_two   = "One Two";
    const char *one_three = "One Three";
    const char *missing   = "Four";

    printf("strstr:\t\t\t\t");

    ASSERT_EQ(strcmp(strstr(str, one), str), 0);
    ASSERT_EQ(strcmp(strstr(str, one_two), str), 0);
    ASSERT_EQ(strcmp(strstr(str, one_three), one_three), 0);
    ASSERT_EQ(strstr(str, missing), (char *)(NULL));

    PASSED;
}

int test_string_strtok(void) {
    
    printf("strtok:\t\t\t\t");

    DISABLED;
}

/*
Char Array Manipulation Tests
*/

int test_string_memchr(void) {

    char buf[BUFFER_SIZE] = {
        '0', '1', '2', '3',
        '4', '5', '6', '7',
        '8', '9', 'a', 'b',
        'c', 'd', 'e', 'f'
    };

    unsigned size = sizeof(buf) / sizeof(buf[0]);

    printf("memchr:\t\t\t\t");

    ASSERT_EQ(memchr(buf, '0', size    ), (char *)(buf + 0));
    ASSERT_EQ(memchr(buf, '8', size    ), (char *)(buf + 8));
    ASSERT_EQ(memchr(buf, 'f', size    ), (char *)(buf + 15));
    ASSERT_EQ(memchr(buf, 'f', size - 1), (char *)(NULL));
    ASSERT_EQ(memchr(buf, ' ', size    ), (char *)(NULL));

    PASSED;
}

int test_string_memcmp(void) {

    char buf_1[4] = { 0, 1, 2, 3 };
    char buf_2[4] = { 0, 1, 2, 3 };
    char buf_3[4] = { 0, 0, 0, 0 };

    size_t size = sizeof(buf_1) / sizeof(buf_1[0]);

    printf("memcmp:\t\t\t\t");

    ASSERT_EQ(memcmp(buf_1, buf_2, size), 0);
    ASSERT_GT(memcmp(buf_1, buf_3, size), 0);
    ASSERT_LT(memcmp(buf_3, buf_2, size), 0);

    ASSERT_EQ(memcmp(buf_1, buf_3, 1), 0);

    PASSED;
}

int test_string_memset(void) {

    unsigned index;

    char buf[BUFFER_SIZE] = { 0 };
    unsigned size = sizeof(buf) / sizeof(buf[0]);

    printf("memset:\t\t\t\t");

    for (index = 0; index < size; ++index) {
        ASSERT_EQ(buf[index], 0);
    }

    memset(buf, 1, size);

    for (index = 0; index < size; ++index) {
        ASSERT_EQ(buf[index], 1);
    }

    PASSED;
}

int test_string_memmove(void) {

    char buf_1[4] = { 0, 1, 2, 3 };
    char buf_2[4] = { 1, 2, 3, 3 };

    size_t size = sizeof(buf_1) / sizeof(buf_1[0]);

    printf("memmove:\t\t\t");

    ASSERT_NE(memcmp(buf_1, buf_2, size), 0);
    memmove(buf_1, buf_1 + 1, size - 1);
    ASSERT_EQ(memcmp(buf_1, buf_2, size), 0);

    PASSED;
}

int test_string_memcpy(void) {

    char buf_1[BUFFER_SIZE / 2] = { 0 };
    char buf_2[BUFFER_SIZE / 2] = { D, E, A, D, B, E, E, F };

    size_t size = sizeof(buf_1) / sizeof(buf_1[0]);

    printf("memcpy:\t\t\t\t");

    ASSERT_NE(memcmp(buf_1, buf_2, size), 0);
    memcpy(buf_1, buf_2, size);
    ASSERT_EQ(memcmp(buf_1, buf_2, size), 0);
    
    PASSED;
}

/* Misc Tests */

int test_string_strerror(void) {

    printf("strerror:\t\t\t");

    DISABLED;
}

int run_string_tests(void) {

    int ret = 0;

    printf("string:\n");

    ret += test_string_strcpy();
    ret += test_string_strncpy();
    ret += test_string_strcat();
    ret += test_string_strxfrm();
    ret += test_string_strlen();
    ret += test_string_strcmp();
    ret += test_string_strncmp();
    ret += test_string_strcoll();
    ret += test_string_strchr();
    ret += test_string_strrchr();
    ret += test_string_strspn();
    ret += test_string_strcspn();
    ret += test_string_strpbrk();
    ret += test_string_strstr();
    ret += test_string_strtok();
    ret += test_string_memchr();
    ret += test_string_memcmp();
    ret += test_string_memset();
    ret += test_string_memmove();
    ret += test_string_memcpy();
    ret += test_string_strerror();

    printf("\n");

    return ret;
}
