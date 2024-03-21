#include <stdio.h>
#include <stdlib.h>

/* NOLINTNEXTLINE(bugprone-reserved-identifier) */
void __attribute__((noreturn)) __stack_chk_fail(void) {
    fputs("stack smashing detected", stderr);

    abort();
}
