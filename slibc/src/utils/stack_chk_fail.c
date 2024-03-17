#include <stdio.h>
#include <stdlib.h>

void __attribute__((noreturn)) __stack_chk_fail(void) { /* NOLINT(bugprone-reserved-identifier) */
    fputs("stack smashing detected", stderr);

    abort();
}
