#include "tests.h"

int main(void) {

    int ret = 0;

    ret += run_ctype_tests();
    ret += run_stdio_tests();
    ret += run_stdlib_tests();
    ret += run_string_tests();

    if (ret) {
        printf("%d %sFAILED%s test%s!\n", ret, RED, RESET, (ret > 1) ? "s" : "");
    } else {
        printf("All tests %sPASSED%s!\n", GREEN, RESET);
    }

    return ret;
}
