#include "tests.h"

int main(void) {

    int passed   = 0;
    int failed   = 0;
    int disabled = 0;

    run_ctype_tests(&passed, &failed, &disabled);
    run_stdio_tests(&passed, &failed, &disabled);
    run_stdlib_tests(&passed, &failed, &disabled);
    run_string_tests(&passed, &failed, &disabled);

    if (failed) {
        printf("%d %sFAILED%s test%s!\n", failed, RED, RESET, (failed > 1) ? "s" : "");
    } else if (!disabled) {
        printf("All tests %sPASSED%s!\n", GREEN, RESET);
    } else {
        printf("%d tests %sPASSED%s! %d tests %sDISABLED%s!\n", passed, GREEN, RESET, disabled, YELLOW, RESET);
    }

    return failed;
}
