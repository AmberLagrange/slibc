#include <stdio.h>
#include <ctype.h>

#include <gtest/gtest.h>

static const char lower_arr[128] = {
    0,   1,   2,   3,   4,   5,   6,   7,
    8,   9,   10,  11,  12,  13,  14,  15,
    16,  17,  18,  19,  20,  21,  22,  23,
    24,  25,  26,  27,  28,  29,  30,  31,
    32,  33,  34,  35,  36,  37,  38,  39,
    40,  41,  42,  43,  44,  45,  46,  47,
    48,  49,  50,  51,  52,  53,  54,  55,
    56,  57,  58,  59,  60,  61,  62,  63,
    64, 'a', 'b',  'c', 'd', 'e', 'f', 'g',
    'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o',
    'p', 'q', 'r', 's', 't', 'u', 'v', 'w',
    'x', 'y', 'z', 91,  92,  93,  94,  95,
    96,  'a', 'b', 'c', 'd', 'e', 'f', 'g',
    'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o',
    'p', 'q', 'r', 's', 't', 'u', 'v', 'w',
    'x', 'y', 'z', 123, 124, 125, 126, 127
};

static const char upper_arr[128] = {
    0,   1,   2,   3,   4,   5,   6,   7,
    8,   9,   10,  11,  12,  13,  14,  15,
    16,  17,  18,  19,  20,  21,  22,  23,
    24,  25,  26,  27,  28,  29,  30,  31,
    32,  33,  34,  35,  36,  37,  38,  39,
    40,  41,  42,  43,  44,  45,  46,  47,
    48,  49,  50,  51,  52,  53,  54,  55,
    56,  57,  58,  59,  60,  61,  62,  63,
    64, 'A', 'B',  'C', 'D', 'E', 'F', 'G',
    'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O',
    'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W',
    'X', 'Y', 'Z', 91,  92,  93,  94,  95,
    96,  'A', 'B', 'C', 'D', 'E', 'F', 'G',
    'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O',
    'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W',
    'X', 'Y', 'Z', 123, 124, 125, 126, 127
};

/* THIS IS A VERY TERRIBLE WAY TO DO THIS, I'M JUST BEING LAZY */

#define GREEN   "\x1B[32m"
#define RED     "\x1B[31m"
#define RESET   "\x1B[0m"

void print_expected_convert(int expected) {

    int i;

    for (i = 11; i >= 0; --i) {
        printf("%s%s", (expected >> i) & 1 ? GREEN : RED, (expected >> i) & 1 ? "1" : "0");
    }

    printf("%s\n", RESET);

}

int test_convert_char(int c) {

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

int test_convert_range(int start, int stop, int expected) {

    int i;
    int val;
    int has_failed = 0;

    if (start == stop) {
        printf("%d:\n", start);

        val = test_convert_char(start);

        if (val == expected) {
            printf("\t%sPassed!%s\n", GREEN, RESET);
        } else {
            printf("\t%shas_failed!%s\tExpected: ", GREEN, RESET);
            print_expected_convert(expected);
            has_failed = 1;
        }

        
    } else {
        printf("%s%d-%d:\n", RESET, start, stop);

        for (i = start; i <= stop; ++i) {

            val = test_convert_char(i);

            if (val == expected) {
                printf("\t%sPassed!%s\n", GREEN, RESET);
            } else {
                printf("\t%shas_failed!%s\tExpected: ", GREEN, RESET);
                print_expected_convert(expected);
                has_failed = 1;
            }
        }
    }

    printf("\n");
    return has_failed;
}

int test_convert_all_chars(void) {

    int has_failed = 0;

    if (test_convert_range(0,   8,   0x0800)) {
        has_failed = 1;
    }

    if (test_convert_range(9,   9,   0x0b00)) {
        has_failed = 1;
    }

    if (test_convert_range(10,  13,  0x0a00)) {
        has_failed = 1;
    }

    if (test_convert_range(14,  31,  0x0800)) {
        has_failed = 1;
    }

    if (test_convert_range(32,  32,  0x0700)) {
        has_failed = 1;
    }

    if (test_convert_range(33,  47,  0x04c0)) {
        has_failed = 1;
    }

    if (test_convert_range(48,  57,  0x04a3)) {
        has_failed = 1;
    }

    if (test_convert_range(58,  64,  0x04c0)) {
        has_failed = 1;
    }

    if (test_convert_range(65,  70,  0x04b9)) {
        has_failed = 1;
    }

    if (test_convert_range(71,  90,  0x04b8)) {
        has_failed = 1;
    }

    if (test_convert_range(91,  96,  0x04c0)) {
        has_failed = 1;
    }

    if (test_convert_range(97,  102, 0x04b5)) {
        has_failed = 1;
    }

    if (test_convert_range(103, 122, 0x04b4)) {
        has_failed = 1;
    }

    if (test_convert_range(123, 126, 0x04c0)) {
        has_failed = 1;
    }

    if (test_convert_range(127, 127, 0x0800)) {
        has_failed = 1;
    }

    return has_failed;
}

int test_upper_lower(void) {
    
    unsigned i;

    for (i = 0; i < sizeof(lower_arr); ++i) {
        if (lower_arr[i] != tolower(upper_arr[i])) {
            printf("has_failed tolower: Expected %d, got %d\n", lower_arr[i], tolower(upper_arr[i]));
            return 1;
        }

        if (upper_arr[i] != toupper(lower_arr[i])) {
            printf("has_failed toupper: Expected %d, got %d\n", upper_arr[i], toupper(lower_arr[i]));
            return 1;
        }
    }

    return 0;
}

int test_upper_lower() {
    unsigned i;

    for (i = 0; i < sizeof(lower_arr); ++i) {
        if (lower_arr[i] != tolower(upper_arr[i])) {
            printf("Failed tolower: Expected %d, got %d\n", lower_arr[i], tolower(upper_arr[i]));
            return 1;
        }

        if (upper_arr[i] != toupper(lower_arr[i])) {
            printf("Failed toupper: Expected %d, got %d\n", upper_arr[i], toupper(lower_arr[i]));
            return 1;
        }
    }

    return 0;
}

int main(void) {

    return test_convert_all_chars();
}
