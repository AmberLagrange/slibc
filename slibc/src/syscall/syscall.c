#include <syscall/syscall.h>

unsigned long __syscall_0(reg64 syscall) {
    
    unsigned long ret; /* NOLINT(cppcoreguidelines-init-variables)*/         
    __asm__ volatile ( /* NOLINT(hicpp-no-assembler)*/
        "movq %1, %%rax\n\t"
        "syscall\n\t"
        "mov %%rax, %0"
        : "=r" (ret)
        : "r"  (syscall)
        : "%rax");

    return ret;
}

unsigned long __syscall_1(reg64 syscall, reg64 reg_rdi) { /* NOLINT(bugprone-easily-swappable-parameters) */
    
    unsigned long ret; /* NOLINT(cppcoreguidelines-init-variables)*/         
    __asm__ volatile ( /* NOLINT(hicpp-no-assembler)*/
        "movq %1, %%rax\n\t"
        "movq %2, %%rdi\n\t"
        "syscall\n\t"
        "mov %%rax, %0"
        : "=r" (ret)
        : "r"  (syscall),
          "r"  (reg_rdi)
        : "%rax", "%rdi");

    return ret;
}

unsigned long __syscall_2(reg64 syscall, reg64 reg_rdi, reg64 reg_rsi) { /* NOLINT(bugprone-easily-swappable-parameters) */
    
    unsigned long ret; /* NOLINT(cppcoreguidelines-init-variables)*/         
    __asm__ volatile ( /* NOLINT(hicpp-no-assembler)*/
        "movq %1, %%rax\n\t"
        "movq %2, %%rdi\n\t"
        "movq %3, %%rsi\n\t"
        "syscall\n\t"
        "mov %%rax, %0"
        : "=r" (ret)
        : "r"  (syscall),
          "r"  (reg_rdi),
          "r"  (reg_rsi)
        : "%rax", "%rdi", "%rsi");

    return ret;
}

unsigned long __syscall_3(reg64 syscall, reg64 reg_rdi, reg64 reg_rsi, reg64 reg_rdx) { /* NOLINT(bugprone-easily-swappable-parameters) */
    
    unsigned long ret; /* NOLINT(cppcoreguidelines-init-variables)*/         
    __asm__ volatile ( /* NOLINT(hicpp-no-assembler)*/
        "movq %1, %%rax\n\t"
        "movq %2, %%rdi\n\t"
        "movq %3, %%rsi\n\t"
        "movq %4, %%rdx\n\t"
        "syscall\n\t"
        "mov %%rax, %0"
        : "=r" (ret)
        : "r"  (syscall),
          "r"  (reg_rdi),
          "r"  (reg_rsi),
          "r"  (reg_rdx)
        : "%rax", "%rdi", "%rsi", "%rdx");

    return ret;
}

unsigned long __syscall_4(reg64 syscall, reg64 reg_rdi, reg64 reg_rsi, reg64 reg_rdx, reg64 reg_r10) { /* NOLINT(bugprone-easily-swappable-parameters) */
    
    unsigned long ret; /* NOLINT(cppcoreguidelines-init-variables)*/         
    __asm__ volatile ( /* NOLINT(hicpp-no-assembler)*/
        "movq %1, %%rax\n\t"
        "movq %2, %%rdi\n\t"
        "movq %3, %%rsi\n\t"
        "movq %4, %%rdx\n\t"
        "movq %5, %%r10\n\t"
        "syscall\n\t"
        "mov %%rax, %0"
        : "=r" (ret)
        : "r"  (syscall),
          "r"  (reg_rdi),
          "r"  (reg_rsi),
          "r"  (reg_rdx),
          "r"  (reg_r10)
        : "%rax", "%rdi", "%rsi", "%rdx", "r10");

    return ret;
}

unsigned long __syscall_5(reg64 syscall, reg64 reg_rdi, reg64 reg_rsi, reg64 reg_rdx, reg64 reg_r10, reg64 reg_r8) { /* NOLINT(bugprone-easily-swappable-parameters) */
    
    unsigned long ret; /* NOLINT(cppcoreguidelines-init-variables)*/         
    __asm__ volatile ( /* NOLINT(hicpp-no-assembler)*/
        "movq %1, %%rax\n\t"
        "movq %2, %%rdi\n\t"
        "movq %3, %%rsi\n\t"
        "movq %4, %%rdx\n\t"
        "movq %5, %%r10\n\t"
        "movq %6, %%r8 \n\t"
        "syscall\n\t"
        "mov %%rax, %0"
        : "=r" (ret)
        : "r"  (syscall),
          "r"  (reg_rdi),
          "r"  (reg_rsi),
          "r"  (reg_rdx),
          "r"  (reg_r10),
          "r"  (reg_r8)
        : "%rax", "%rdi", "%rsi", "%rdx", "r10", "r8");

    return ret;
}

unsigned long __syscall_6(reg64 syscall, reg64 reg_rdi, reg64 reg_rsi, reg64 reg_rdx, reg64 reg_r10, reg64 reg_r8, reg64 reg_r9) { /* NOLINT(bugprone-easily-swappable-parameters) */
    
    unsigned long ret; /* NOLINT(cppcoreguidelines-init-variables)*/         
    __asm__ volatile ( /* NOLINT(hicpp-no-assembler)*/
        "movq %1, %%rax\n\t"
        "movq %2, %%rdi\n\t"
        "movq %3, %%rsi\n\t"
        "movq %4, %%rdx\n\t"
        "movq %5, %%r10\n\t"
        "movq %6, %%r8 \n\t"
        "movq %7, %%r9 \n\t"
        "syscall\n\t"
        "mov %%rax, %0"
        : "=r" (ret)
        : "r"  (syscall),
          "r"  (reg_rdi),
          "r"  (reg_rsi),
          "r"  (reg_rdx),
          "r"  (reg_r10),
          "r"  (reg_r8),
          "r"  (reg_r9)
        : "%rax", "%rdi", "%rsi", "%rdx", "r10", "r8", "r9");

    return ret;
}
