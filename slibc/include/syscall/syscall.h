#ifndef SYSCALL_H
#define SYSCALL_H

enum __syscalls_e {
    SYS_READ    = 0,
    SYS_WRITE   = 1,
    SYS_MMAP    = 9,
    SYS_MUNMAP  = 11,
    SYS_GET_PID = 39,
    SYS_EXIT    = 60,
    SYS_KILL    = 62
};

#define SYS_READ    0
#define SYS_WRITE   1
#define SYS_MMAP    9
#define SYS_MUNMAP  11
#define SYS_GET_PID 39
#define SYS_EXIT    60
#define SYS_KILL    62

typedef unsigned long int reg64;

unsigned long __syscall_0(reg64 syscall);
unsigned long __syscall_1(reg64 syscall, reg64 rdi);
unsigned long __syscall_2(reg64 syscall, reg64 rdi, reg64 rsi);
unsigned long __syscall_3(reg64 syscall, reg64 rdi, reg64 rsi, reg64 rdx);
unsigned long __syscall_4(reg64 syscall, reg64 rdi, reg64 rsi, reg64 rdx, reg64 r10);
unsigned long __syscall_5(reg64 syscall, reg64 rdi, reg64 rsi, reg64 rdx, reg64 r10, reg64 r8);
unsigned long __syscall_6(reg64 syscall, reg64 rdi, reg64 rsi, reg64 rdx, reg64 r10, reg64 r8, reg64 r9);

int read (int file_descriptor, void       *buf, unsigned long count);
int write(int file_descriptor, const char *buf, int           length);

#endif /* SYSCALL_H */
