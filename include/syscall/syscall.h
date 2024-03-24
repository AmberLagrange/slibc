#ifndef SYSCALL_H
#define SYSCALL_H

typedef unsigned long int reg64;

/* NOLINTBEGIN(bugprone-reserved-identifier) */
enum {
    SYS_READ    = 0,
    SYS_WRITE   = 1,
    SYS_MMAP    = 9,
    SYS_MUNMAP  = 11,
    SYS_GET_PID = 39,
    SYS_EXIT    = 60,
    SYS_KILL    = 62
};

unsigned long __syscall_0(reg64 syscall);
unsigned long __syscall_1(reg64 syscall, reg64 reg_rdi);
unsigned long __syscall_2(reg64 syscall, reg64 reg_rdi, reg64 reg_rsi);
unsigned long __syscall_3(reg64 syscall, reg64 reg_rdi, reg64 reg_rsi, reg64 reg_rdx);
unsigned long __syscall_4(reg64 syscall, reg64 reg_rdi, reg64 reg_rsi, reg64 reg_rdx, reg64 reg_r10);
unsigned long __syscall_5(reg64 syscall, reg64 reg_rdi, reg64 reg_rsi, reg64 reg_rdx, reg64 reg_r10, reg64 reg_r8);
unsigned long __syscall_6(reg64 syscall, reg64 reg_rdi, reg64 reg_rsi, reg64 reg_rdx, reg64 reg_r10, reg64 reg_r8, reg64 reg_r9);
/* NOLINTEND(bugprone-reserved-identifier) */

int read (int file_descriptor, void       *buf, unsigned long count);
int write(int file_descriptor, const char *buf, int           length);

#endif /* SYSCALL_H */
