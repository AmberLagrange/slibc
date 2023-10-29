#include <stdio.h>
#include <ctype.h>

/* THIS IS A VERY TERRIBLE WAY TO DO THIS, I'M JUST BEING LAZY */

#define GREEN   "\x1B[32m"
#define RED     "\x1B[31m"
#define RESET   "\x1B[0m"

void print_expected(int expected) {

    int i;

    for (i = 11; i >= 0; --i) {
        printf("%s%s", (expected >> i) & 1 ? GREEN : RED, (expected >> i) & 1 ? "1" : "0");
    }

    printf("%s\n", RESET);

}

int test(int c) {

    int i;
    int val = 0;

    val |= (iscntrl(c) != 0)  << 11;
    val |= (isprint(c) != 0)  << 10;
    val |= (isspace(c) != 0)  << 9;
    val |= (isblank(c) != 0)  << 8;
    val |= (isgraph(c) != 0)  << 7;
    val |= (ispunct(c) != 0)  << 6;
    val |= (isalnum(c) != 0)  << 5;
    val |= (isalpha(c) != 0)  << 4;
    val |= (isupper(c) != 0)  << 3;
    val |= (islower(c) != 0)  << 2;
    val |= (isdigit(c) != 0)  << 1;
    val |= (isxdigit(c) != 0) << 0;

    for (i = 11; i >= 0; --i) {
        printf("%s%s", (val >> i) & 1 ? GREEN : RED, (val >> i) & 1 ? "1" : "0");
    }

    return val;
}

int test_range(int start, int stop, int expected) {

    int i;
    int val;
    int failed = 0;

    if (start == stop) {
        printf("%d:\n", start);

        val = test(start);

        if (val == expected) {
            printf("\t%sPassed!%s\n", GREEN, RESET);
        } else {
            printf("\t%sFailed!%s\tExpected: ", GREEN, RESET);
            print_expected(expected);
            failed = 1;
        }

        
    } else {
        printf("%s%d-%d:\n", RESET, start, stop);

        for (i = start; i <= stop; ++i) {

            val = test(i);

            if (val == expected) {
                printf("\t%sPassed!%s\n", GREEN, RESET);
            } else {
                printf("\t%sFailed!%s\tExpected: ", GREEN, RESET);
                print_expected(expected);
                failed = 1;
            }
        }
    }

    printf("\n");
    return failed;
}

int tests(void) {

    int failed = 0;

    if (test_range(0,   8,   0x0800)) {
        failed = 1;
    }

    if (test_range(9,   9,   0x0b00)) {
        failed = 1;
    }

    if (test_range(10,  13,  0x0a00)) {
        failed = 1;
    }

    if (test_range(14,  31,  0x0800)) {
        failed = 1;
    }

    if (test_range(32,  32,  0x0700)) {
        failed = 1;
    }

    if (test_range(33,  47,  0x04c0)) {
        failed = 1;
    }

    if (test_range(48,  57,  0x04a3)) {
        failed = 1;
    }

    if (test_range(58,  64,  0x04c0)) {
        failed = 1;
    }

    if (test_range(65,  70,  0x04b9)) {
        failed = 1;
    }

    if (test_range(71,  90,  0x04b8)) {
        failed = 1;
    }

    if (test_range(91,  96,  0x04c0)) {
        failed = 1;
    }

    if (test_range(97,  102, 0x04b5)) {
        failed = 1;
    }

    if (test_range(103, 122, 0x04b4)) {
        failed = 1;
    }

    if (test_range(123, 126, 0x04c0)) {
        failed = 1;
    }

    if (test_range(127, 127, 0x0800)) {
        failed = 1;
    }

    return failed;
}

int main(void) {

    return tests();
}
