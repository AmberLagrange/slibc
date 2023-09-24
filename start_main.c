
#include "stdlib.h"

extern int main(int argc, char *argv[]);

void __attribute((naked)) _start() { // naked attribute to ignore the stack frame
    __asm__ volatile (
        "movl (%rsp), %edi      \n\t" // move argc into edi
        "lea 8(%rsp), %rsi      \n\t" // move the address of argv rsi
        "call __slibc_start_main\n\t" // call __slibc_start_main with argc and argv
    );
}

void __slibc_start_main(int argc, char *argv[]) {

    int result;
    result = main(argc, argv);

    _Exit(result);
}
