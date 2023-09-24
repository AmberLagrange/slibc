#ifndef SYSCALL_H
#define SYSCALL_H

#define SYS_WRITE   1
#define SYS_EXIT    60

typedef unsigned long int reg64;

int __syscall_0(reg64 syscall);
int __syscall_1(reg64 syscall, reg64 rdi);
int __syscall_2(reg64 syscall, reg64 rdi, reg64 rsi);
int __syscall_3(reg64 syscall, reg64 rdi, reg64 rsi, reg64 rdx);
int __syscall_4(reg64 syscall, reg64 rdi, reg64 rsi, reg64 rdx, reg64 r10);
int __syscall_5(reg64 syscall, reg64 rdi, reg64 rsi, reg64 rdx, reg64 r10, reg64 r8);
int __syscall_6(reg64 syscall, reg64 rdi, reg64 rsi, reg64 rdx, reg64 r10, reg64 r8, reg64 r9);

#endif /* SYSCALL_H */
