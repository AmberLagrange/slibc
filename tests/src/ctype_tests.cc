
extern "C" {
    #include "../../slibc/include/ctype.h"
}

#include <gtest/gtest.h>

#define PRINT_FLAG  (0x0001)
#define GRAPH_FLAG  (0x0002)
#define PUNCT_FLAG  (0x0004)
#define ALNUM_FLAG  (0x0008)
#define XDIGIT_FLAG (0x0010)
#define DIGIT_FLAG  (0x0020)
#define ALPHA_FLAG  (0x0040)
#define LOWER_FLAG  (0x0080)
#define UPPER_FLAG  (0x0100)
#define SPACE_FLAG  (0x0200)
#define BLANK_FLAG  (0x0400)
#define CNTRL_FLAG  (0x0800)

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

static const int upper_arr[128] = {
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

static const int flag_arr[128] = {
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

TEST(ctype, isalnum) {

    unsigned i;

    for (i = 0; i < 128; ++i) {
        ASSERT_EQ(flag_arr[i] & ALNUM_FLAG, isalnum(i) & ALNUM_FLAG);
    }

}

TEST(ctype, isalpha) {

    unsigned i;

    for (i = 0; i < 128; ++i) {
        ASSERT_EQ(flag_arr[i] & ALPHA_FLAG, isalpha(i) & ALPHA_FLAG);
    }

}

TEST(ctype, isblank) {

    unsigned i;

    for (i = 0; i < 128; ++i) {
        ASSERT_EQ(flag_arr[i] & BLANK_FLAG, isblank(i) & BLANK_FLAG);
    }

}

TEST(ctype, islower) {

    unsigned i;

    for (i = 0; i < 128; ++i) {
        ASSERT_EQ(flag_arr[i] & LOWER_FLAG, islower(i) & LOWER_FLAG);
    }

}

TEST(ctype, isupper) {

    unsigned i;

    for (i = 0; i < 128; ++i) {
        ASSERT_EQ(flag_arr[i] & UPPER_FLAG, isupper(i) & UPPER_FLAG);
    }

}

TEST(ctype, isdigit) {

    unsigned i;

    for (i = 0; i < 128; ++i) {
        ASSERT_EQ(flag_arr[i] & DIGIT_FLAG, isdigit(i) & DIGIT_FLAG);
    }

}

TEST(ctype, isxdigit) {

    unsigned i;

    for (i = 0; i < 128; ++i) {
        ASSERT_EQ(flag_arr[i] & XDIGIT_FLAG, isxdigit(i) & XDIGIT_FLAG);
    }

}

TEST(ctype, iscntrl) {

    unsigned i;

    for (i = 0; i < 128; ++i) {
        ASSERT_EQ(flag_arr[i] & CNTRL_FLAG, iscntrl(i) & CNTRL_FLAG);
    }

}

TEST(ctype, isgraph) {

    unsigned i;

    for (i = 0; i < 128; ++i) {
        ASSERT_EQ(flag_arr[i] & GRAPH_FLAG, isgraph(i) & GRAPH_FLAG);
    }

}

TEST(ctype, isspace) {

    unsigned i;

    for (i = 0; i < 128; ++i) {
        ASSERT_EQ(flag_arr[i] & SPACE_FLAG, isspace(i) & SPACE_FLAG);
    }

}

TEST(ctype, isprint) {

    unsigned i;

    for (i = 0; i < 128; ++i) {
        ASSERT_EQ(flag_arr[i] & PRINT_FLAG, isprint(i) & PRINT_FLAG);
    }

}

TEST(ctype, ispunct) {

    unsigned i;

    for (i = 0; i < 128; ++i) {
        ASSERT_EQ(flag_arr[i] & PUNCT_FLAG, ispunct(i) & PUNCT_FLAG);
    }

}


TEST(ctype, tolower) {

    unsigned i;

    for (i = 0; i < sizeof(lower_arr); ++i) {
        ASSERT_EQ(lower_arr[i], tolower(upper_arr[i]));
    }
}

TEST(ctype, toupper) {

    unsigned i;

    for (i = 0; i < sizeof(lower_arr); ++i) {
        ASSERT_EQ(upper_arr[i], toupper(lower_arr[i]));
    }
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
