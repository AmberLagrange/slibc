#ifndef SYSCALL_H
#define SYSCALL_H

#include "stdint.h"

#define SYS_WRITE   1
#define SYS_EXIT    60

int __syscall_0(uint64_t syscall);
int __syscall_1(uint64_t syscall, uint64_t rdi);
int __syscall_2(uint64_t syscall, uint64_t rdi, uint64_t rsi);
int __syscall_3(uint64_t syscall, uint64_t rdi, uint64_t rsi, uint64_t rdx);
int __syscall_4(uint64_t syscall, uint64_t rdi, uint64_t rsi, uint64_t rdx, uint64_t r10);
int __syscall_5(uint64_t syscall, uint64_t rdi, uint64_t rsi, uint64_t rdx, uint64_t r10, uint64_t r8);
int __syscall_6(uint64_t syscall, uint64_t rdi, uint64_t rsi, uint64_t rdx, uint64_t r10, uint64_t r8, uint64_t r9);

#endif // SYSCALL_H
