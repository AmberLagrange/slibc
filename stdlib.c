#include "stdlib.h"

void __attribute__((noreturn)) _Exit(int status) {
    __asm__ volatile(
        "movq $60, %%rax    \n\t" // syscall number for exit
        "movq %0,  %%rdi    \n\t" // status code
        "syscall            \n\t" // invoke syscall
        :
        : "g" (status)
        : "rax", "rdi"
    );

    __builtin_unreachable();
}

void __attribute__((noreturn)) exit(int status) {
    _Exit(status);
}
