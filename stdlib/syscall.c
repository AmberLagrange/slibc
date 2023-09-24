#include "../include/syscall.h"

// TODO:
// DON'T BE DUMB AND MOVE EVERY VALUE INTO THE REGISTERS, EVEN IF THEY AREN'T DEFINED
// MAYBE MAKE DIFFERENT SYSCALL FUNCTIONS THAT TAKE A DIFFERENT NUMBER OF ARGUMENTS
// THIS WORKS FOR NOW SO I WILL LEAVE IT BE UNTIL I WANT TO BE MORE EFFICIENT

inline __attribute((always_inline)) int __syscall(struct __syscall_t syscall) {
    int ret;

    asm("movq %1, %%rax\n\t"
        "movq %2, %%rdi\n\t"
        "movq %3, %%rsi\n\t"
        "movq %4, %%rdx\n\t"
        "movq %5, %%r10\n\t"
        "movq %6, %%r8 \n\t"
        "movq %6, %%r9 \n\t"
        "syscall\n\t"
        "mov %%eax, %0" // move the return value into ret
        : "=r" (ret)
        : "r" ((uint64_t) syscall.syscall),
          "r" ((uint64_t) syscall.first),
          "r" ((uint64_t) syscall.second),
          "r" ((uint64_t) syscall.third),
          "r" ((uint64_t) syscall.forth),
          "r" ((uint64_t) syscall.fifth),
          "r" ((uint64_t) syscall.sixth)
        : "%rax", "%rdi", "%rsi", "%rdx", "r10", "r8", "r9");

    return ret;
}
