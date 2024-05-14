#include "tests.h"

#include <ctype.h>

enum {
    NUM_ASCII   = 128
};

enum {
    PRINT_FLAG  = 0x0001,
    GRAPH_FLAG  = 0x0002,
    PUNCT_FLAG  = 0x0004,
    ALNUM_FLAG  = 0x0008,
    XDIGIT_FLAG = 0x0010,
    DIGIT_FLAG  = 0x0020,
    ALPHA_FLAG  = 0x0040,
    LOWER_FLAG  = 0x0080,
    UPPER_FLAG  = 0x0100,
    SPACE_FLAG  = 0x0200,
    BLANK_FLAG  = 0x0400,
    CNTRL_FLAG  = 0x0800
};

static const char lower_arr[NUM_ASCII] = {
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

static const int upper_arr[NUM_ASCII] = {
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

static const int flag_arr[NUM_ASCII] = {
    0x0800, 0x0800, 0x0800, 0x0800, 0x0800, 0x0800, 0x0800, 0x0800, /* 0x00 - 0x07 */
    0x0800, 0x0e00, 0x0c00, 0x0c00, 0x0c00, 0x0c00, 0x0800, 0x0800, /* 0x08 - 0x0f */
    0x0800, 0x0800, 0x0800, 0x0800, 0x0800, 0x0800, 0x0800, 0x0800, /* 0x10 - 0x17 */
    0x0800, 0x0800, 0x0800, 0x0800, 0x0800, 0x0800, 0x0800, 0x0800, /* 0x18 - 0x1f */
    0x0601, 0x0007, 0x0007, 0x0007, 0x0007, 0x0007, 0x0007, 0x0007, /* 0x20 - 0x27 */
    0x0007, 0x0007, 0x0007, 0x0007, 0x0007, 0x0007, 0x0007, 0x0007, /* 0x28 - 0x2f */
    0x003b, 0x003b, 0x003b, 0x003b, 0x003b, 0x003b, 0x003b, 0x003b, /* 0x30 - 0x37 */
    0x003b, 0x003b, 0x0007, 0x0007, 0x0007, 0x0007, 0x0007, 0x0007, /* 0x38 - 0x3f */
    0x0007, 0x015b, 0x015b, 0x015b, 0x015b, 0x015b, 0x015b, 0x014b, /* 0x40 - 0x47 */
    0x014b, 0x014b, 0x014b, 0x014b, 0x014b, 0x014b, 0x014b, 0x014b, /* 0x48 - 0x4f */
    0x014b, 0x014b, 0x014b, 0x014b, 0x014b, 0x014b, 0x014b, 0x014b, /* 0x50 - 0x57 */
    0x014b, 0x014b, 0x014b, 0x0007, 0x0007, 0x0007, 0x0007, 0x0007, /* 0x58 - 0x5f */
    0x0007, 0x00db, 0x00db, 0x00db, 0x00db, 0x00db, 0x00db, 0x00cb, /* 0x60 - 0x67 */
    0x00cb, 0x00cb, 0x00cb, 0x00cb, 0x00cb, 0x00cb, 0x00cb, 0x00cb, /* 0x68 - 0x6f */
    0x00cb, 0x00cb, 0x00cb, 0x00cb, 0x00cb, 0x00cb, 0x00cb, 0x00cb, /* 0x70 - 0x77 */
    0x00cb, 0x00cb, 0x00cb, 0x0007, 0x0007, 0x0007, 0x0007, 0x0800  /* 0x78 - 0x7f */
};

/* NOLINTNEXTLINE(bugprone-easily-swappable-parameters, readability-non-const-parameter) */
void test_ctype_isalnum(int *passed, int *failed, int *disabled) {

    int index;

    printf("isalnum:\t\t\t");

    for (index = 0; index < NUM_ASCII; ++index) {
        ASSERT_EQ((flag_arr[index] & ALNUM_FLAG), (isalnum(index) & ALNUM_FLAG));
    }

    PASSED;
    UNUSED(disabled);
}

/* NOLINTNEXTLINE(bugprone-easily-swappable-parameters, readability-non-const-parameter) */
void test_ctype_isalpha(int *passed, int *failed, int *disabled) {

    int index;

    printf("isalpha:\t\t\t");

    for (index = 0; index < NUM_ASCII; ++index) {
        ASSERT_EQ((flag_arr[index] & ALPHA_FLAG), (isalpha(index) & ALPHA_FLAG));
    }

    PASSED;
    UNUSED(disabled);
}

/* NOLINTNEXTLINE(bugprone-easily-swappable-parameters, readability-non-const-parameter) */
void test_ctype_isblank(int *passed, int *failed, int *disabled) {

    int index;

    printf("isblank:\t\t\t");

    for (index = 0; index < NUM_ASCII; ++index) {
        ASSERT_EQ((flag_arr[index] & BLANK_FLAG), (isblank(index) & BLANK_FLAG));
    }

    PASSED;
    UNUSED(disabled);
}

/* NOLINTNEXTLINE(bugprone-easily-swappable-parameters, readability-non-const-parameter) */
void test_ctype_islower(int *passed, int *failed, int *disabled) {

    int index;

    printf("islower:\t\t\t");

    for (index = 0; index < NUM_ASCII; ++index) {
        ASSERT_EQ((flag_arr[index] & LOWER_FLAG), (islower(index) & LOWER_FLAG));
    }

    PASSED;
    UNUSED(disabled);
}

/* NOLINTNEXTLINE(bugprone-easily-swappable-parameters, readability-non-const-parameter) */
void test_ctype_isupper(int *passed, int *failed, int *disabled) {

    int index;

    printf("isupper:\t\t\t");

    for (index = 0; index < NUM_ASCII; ++index) {
        ASSERT_EQ((flag_arr[index] & UPPER_FLAG), (isupper(index) & UPPER_FLAG));
    }

    PASSED;
    UNUSED(disabled);
}

/* NOLINTNEXTLINE(bugprone-easily-swappable-parameters, readability-non-const-parameter) */
void test_ctype_isdigit(int *passed, int *failed, int *disabled) {

    int index;

    printf("isdigit:\t\t\t");

    for (index = 0; index < NUM_ASCII; ++index) {
        ASSERT_EQ((flag_arr[index] & DIGIT_FLAG), (isdigit(index) & DIGIT_FLAG));
    }

    PASSED;
    UNUSED(disabled);
}

/* NOLINTNEXTLINE(bugprone-easily-swappable-parameters, readability-non-const-parameter) */
void test_ctype_isxdigit(int *passed, int *failed, int *disabled) {

    int index;

    printf("isxdigit:\t\t\t");

    for (index = 0; index < NUM_ASCII; ++index) {
        ASSERT_EQ((flag_arr[index] & XDIGIT_FLAG), (isxdigit(index) & XDIGIT_FLAG));
    }

    PASSED;
    UNUSED(disabled);
}

/* NOLINTNEXTLINE(bugprone-easily-swappable-parameters, readability-non-const-parameter) */
void test_ctype_iscntrl(int *passed, int *failed, int *disabled) {

    int index;

    printf("iscntrl:\t\t\t");

    for (index = 0; index < NUM_ASCII; ++index) {
        ASSERT_EQ((flag_arr[index] & CNTRL_FLAG), (iscntrl(index) & CNTRL_FLAG));
    }

    PASSED;
    UNUSED(disabled);
}

/* NOLINTNEXTLINE(bugprone-easily-swappable-parameters, readability-non-const-parameter) */
void test_ctype_isgraph(int *passed, int *failed, int *disabled) {

    int index;

    printf("isgraph:\t\t\t");

    for (index = 0; index < NUM_ASCII; ++index) {
        ASSERT_EQ((flag_arr[index] & GRAPH_FLAG), (isgraph(index) & GRAPH_FLAG));
    }

    PASSED;
    UNUSED(disabled);
}

/* NOLINTNEXTLINE(bugprone-easily-swappable-parameters, readability-non-const-parameter) */
void test_ctype_isspace(int *passed, int *failed, int *disabled) {

    int index;

    printf("isspace:\t\t\t");

    for (index = 0; index < NUM_ASCII; ++index) {
        ASSERT_EQ((flag_arr[index] & SPACE_FLAG), (isspace(index) & SPACE_FLAG));
    }

    PASSED;
    UNUSED(disabled);
}

/* NOLINTNEXTLINE(bugprone-easily-swappable-parameters, readability-non-const-parameter) */
void test_ctype_isprint(int *passed, int *failed, int *disabled) {

    int index;

    printf("isprint:\t\t\t");

    for (index = 0; index < NUM_ASCII; ++index) {
        ASSERT_EQ((flag_arr[index] & PRINT_FLAG), (isprint(index) & PRINT_FLAG));
    }

    PASSED;
    UNUSED(disabled);
}

/* NOLINTNEXTLINE(bugprone-easily-swappable-parameters, readability-non-const-parameter) */
void test_ctype_ispunct(int *passed, int *failed, int *disabled) {

    int index;

    printf("ispunct:\t\t\t");

    for (index = 0; index < NUM_ASCII; ++index) {
        ASSERT_EQ((flag_arr[index] & PUNCT_FLAG), (ispunct(index) & PUNCT_FLAG));
    }

    PASSED;
    UNUSED(disabled);
}

/* NOLINTNEXTLINE(bugprone-easily-swappable-parameters, readability-non-const-parameter) */
void test_ctype_tolower(int *passed, int *failed, int *disabled) {

    int index;

    printf("tolower:\t\t\t");

    for (index = 0; index < NUM_ASCII; ++index) {
        ASSERT_EQ(lower_arr[index], tolower(upper_arr[index]));
    }

    PASSED;
    UNUSED(disabled);
}

/* NOLINTNEXTLINE(bugprone-easily-swappable-parameters, readability-non-const-parameter) */
void test_ctype_toupper(int *passed, int *failed, int *disabled) {

    int index;

    printf("toupper:\t\t\t");

    for (index = 0; index < NUM_ASCII; ++index) {
        ASSERT_EQ(upper_arr[index], toupper(lower_arr[index]));
    }

    PASSED;
    UNUSED(disabled);
}

void run_ctype_tests(int *passed, int *failed, int *disabled) {

    printf("ctype:\n");

    test_ctype_isalnum(passed, failed, disabled);
    test_ctype_isalpha(passed, failed, disabled);
    test_ctype_isblank(passed, failed, disabled);
    test_ctype_islower(passed, failed, disabled);
    test_ctype_isupper(passed, failed, disabled);
    test_ctype_isdigit(passed, failed, disabled);
    test_ctype_isxdigit(passed, failed, disabled);
    test_ctype_iscntrl(passed, failed, disabled);
    test_ctype_isgraph(passed, failed, disabled);
    test_ctype_isspace(passed, failed, disabled);
    test_ctype_isprint(passed, failed, disabled);
    test_ctype_ispunct(passed, failed, disabled);
    test_ctype_tolower(passed, failed, disabled);
    test_ctype_toupper(passed, failed, disabled);

    printf("\n");
}
