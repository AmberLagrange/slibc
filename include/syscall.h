#ifndef SYSCALL_H
#define SYSCALL_H

#include "stdint.h"

#define SYS_WRITE   1
#define SYS_EXIT    60

struct __syscall_t {
    uint64_t syscall;
    uint64_t first;
    uint64_t second;
    uint64_t third;
    uint64_t forth;
    uint64_t fifth;
    uint64_t sixth;
};

int __syscall(struct __syscall_t _syscall);

#endif // SYSCALL_H
