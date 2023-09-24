#include "../include/stdlib.h"

typedef unsigned long long int uint64_t;

#define SYS_WRITE   1
#define SYS_EXIT    60

// temp
int write(int fd, const char *buf, int length)
{
    int ret;

    asm("movq %1, %%rax\n\t"                // syscall
        "movq %2, %%rdi\n\t"                // fd parameter
        "movq %3, %%rsi\n\t"                // buf parameter
        "movq %4, %%rdx\n\t"                // length parameter
        "syscall\n\t"                       // invoke the syscall
        "mov %%eax, %0"                     // move the return value into ret
        : "=r" (ret)
        : "r" ((uint64_t) SYS_WRITE),
          "r" ((uint64_t) fd),
          "r" ((uint64_t) buf),
          "r" ((uint64_t) length)
        : "%rax", "%rdi", "%rsi", "%rdx");

    return ret;
}

void __attribute__((noreturn)) _Exit(int status) {

    __asm__ volatile(
        "movq %0, %%rax \n\t" // syscall
        "movq %1, %%rdi \n\t" // status code parameter
        "syscall        \n\t" // invoke the syscall
        :
        : "r" ((uint64_t) SYS_EXIT),
          "r" ((uint64_t) status)
        : "rax", "rdi"
    );

    __builtin_unreachable();
}

void __attribute__((noreturn)) exit(int status) {
    _Exit(status);
}
