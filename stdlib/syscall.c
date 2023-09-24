#include "../include/syscall.h"

__attribute__((always_inline)) int __syscall_0(reg64 syscall) {
    
    int ret;
    __asm__ volatile ("movq %1, %%rax\n\t"
        "syscall\n\t"
        "mov %%eax, %0"
        : "=r" (ret)
        : "r"  (syscall)
        : "%rax");

    return ret;
}

__attribute__((always_inline)) int __syscall_1(reg64 syscall, reg64 rdi) {
    
    int ret;
    __asm__ volatile ("movq %1, %%rax\n\t"
        "movq %2, %%rdi\n\t"
        "syscall\n\t"
        "mov %%eax, %0"
        : "=r" (ret)
        : "r"  (syscall),
          "r"  (rdi)
        : "%rax", "%rdi");

    return ret;
}

__attribute__((always_inline)) int __syscall_2(reg64 syscall, reg64 rdi, reg64 rsi) {
    
    int ret;
    __asm__ volatile ("movq %1, %%rax\n\t"
        "movq %2, %%rdi\n\t"
        "movq %3, %%rsi\n\t"
        "syscall\n\t"
        "mov %%eax, %0"
        : "=r" (ret)
        : "r"  (syscall),
          "r"  (rdi),
          "r"  (rsi)
        : "%rax", "%rdi", "%rsi");

    return ret;
}

__attribute__((always_inline)) int __syscall_3(reg64 syscall, reg64 rdi, reg64 rsi, reg64 rdx) {
    
    int ret;
    __asm__ volatile ("movq %1, %%rax\n\t"
        "movq %2, %%rdi\n\t"
        "movq %3, %%rsi\n\t"
        "movq %4, %%rdx\n\t"
        "syscall\n\t"
        "mov %%eax, %0"
        : "=r" (ret)
        : "r"  (syscall),
          "r"  (rdi),
          "r"  (rsi),
          "r"  (rdx)
        : "%rax", "%rdi", "%rsi", "%rdx");

    return ret;
}

__attribute__((always_inline)) int __syscall_4(reg64 syscall, reg64 rdi, reg64 rsi, reg64 rdx, reg64 r10) {
    
    int ret;
    __asm__ volatile ("movq %1, %%rax\n\t"
        "movq %2, %%rdi\n\t"
        "movq %3, %%rsi\n\t"
        "movq %4, %%rdx\n\t"
        "movq %5, %%r10\n\t"
        "syscall\n\t"
        "mov %%eax, %0"
        : "=r" (ret)
        : "r"  (syscall),
          "r"  (rdi),
          "r"  (rsi),
          "r"  (rdx),
          "r"  (r10)
        : "%rax", "%rdi", "%rsi", "%rdx", "r10");

    return ret;
}

__attribute__((always_inline)) int __syscall_5(reg64 syscall, reg64 rdi, reg64 rsi, reg64 rdx, reg64 r10, reg64 r8) {
    
    int ret;
    __asm__ volatile ("movq %1, %%rax\n\t"
        "movq %2, %%rdi\n\t"
        "movq %3, %%rsi\n\t"
        "movq %4, %%rdx\n\t"
        "movq %5, %%r10\n\t"
        "movq %6, %%r8 \n\t"
        "syscall\n\t"
        "mov %%eax, %0"
        : "=r" (ret)
        : "r"  (syscall),
          "r"  (rdi),
          "r"  (rsi),
          "r"  (rdx),
          "r"  (r10),
          "r"  (r8)
        : "%rax", "%rdi", "%rsi", "%rdx", "r10", "r8");

    return ret;
}

__attribute__((always_inline)) int __syscall_6(reg64 syscall, reg64 rdi, reg64 rsi, reg64 rdx, reg64 r10, reg64 r8, reg64 r9) {
    
    int ret;
    __asm__ volatile ("movq %1, %%rax\n\t"
        "movq %2, %%rdi\n\t"
        "movq %3, %%rsi\n\t"
        "movq %4, %%rdx\n\t"
        "movq %5, %%r10\n\t"
        "movq %6, %%r8 \n\t"
        "movq %7, %%r9 \n\t"
        "syscall\n\t"
        "mov %%eax, %0"
        : "=r" (ret)
        : "r"  (syscall),
          "r"  (rdi),
          "r"  (rsi),
          "r"  (rdx),
          "r"  (r10),
          "r"  (r8),
          "r"  (r9)
        : "%rax", "%rdi", "%rsi", "%rdx", "r10", "r8", "r9");

    return ret;
}
