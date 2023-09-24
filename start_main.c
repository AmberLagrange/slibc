
#include "stdlib.h"

extern int main(int argc, char *argv[]);

void _start() {

    __asm__ volatile (
        "call __slibc_start_main"
    );

}

void __slibc_start_main(int argc, char *argv[]) {

    int result;
    result = main(argc, argv);

    _Exit(result);
}
