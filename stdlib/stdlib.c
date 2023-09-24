#include "../include/stdlib.h"

typedef unsigned long long int uint64_t;

// temp
int write(int fd, const char *buf, int length)
{
    int ret;

    asm("mov %1, %%rax\n\t"
        "mov %2, %%rdi\n\t"
        "mov %3, %%rsi\n\t"
        "mov %4, %%rdx\n\t"
        "syscall\n\t"
        "mov %%eax, %0"
        : "=r" (ret)
        : "r" ((uint64_t) 1),
          "r" ((uint64_t) fd),
          "r" ((uint64_t) buf),
          "r" ((uint64_t) length)
        : "%rax", "%rdi", "%rsi", "%rdx");

    return ret;
}

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
