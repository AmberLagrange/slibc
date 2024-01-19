
/*

    TODO: stdio.h cannot be tested
    as gtest relies on proper implementation
    of FILE

*/

extern "C" {
    #include "../../slibc/include/stdio.h"
}

#include <gtest/gtest.h>

TEST(stdio, empty) {
    ASSERT_EQ(printf(""), 0);
}


TEST(stdio, literal) {
    ASSERT_EQ(printf("Hello World!\n"), 13);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
