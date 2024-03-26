#ifndef SYSCALL_H
#define SYSCALL_H

typedef unsigned long int reg64;

/* NOLINTBEGIN(bugprone-reserved-identifier) */

/**
 * @brief Literals for various x86_64 linux syscalls
 * 
 */
enum {
    SYS_READ    = 0,    /**< Syscall for reading a file.        */
    SYS_WRITE   = 1,    /**< Syscall for writing to a file.     */
    SYS_MMAP    = 9,    /**< Syscall for creating a memory map. */
    SYS_MUNMAP  = 11,   /**< Syscall for deleting a memory map. */
    SYS_GET_PID = 39,   /**< Syscall to get the process's ID.   */
    SYS_EXIT    = 60,   /**< Syscall to exit a process.         */
    SYS_KILL    = 62    /**< Syscall to kill a process.         */
};

/**
 * @brief                   Make a syscall with no parameters.
 * 
 * @param syscall           The syscall to invoke.
 * @return unsigned long    The return value of the syscall.
 */
unsigned long __syscall_0(reg64 syscall);

/**
 * @brief                   Make a syscall with one parameter.
 * 
 * @param syscall           The syscall to invoke.
 * @param reg_rdi           The value to pass to the rdi register (first paramter).
 * @return unsigned long    The return value of the syscall.
 */
unsigned long __syscall_1(reg64 syscall, reg64 reg_rdi);

/**
 * @brief                   Make a syscall with two parameters.
 * 
 * @param syscall           The syscall to invoke.
 * @param reg_rdi           The value to pass to the rdi register (first parameter).
 * @param reg_rsi           The value to pass to the rsi register (second parameter).
 * @return unsigned long    The return value of the syscall.
 */
unsigned long __syscall_2(reg64 syscall, reg64 reg_rdi, reg64 reg_rsi);

/**
 * @brief                   Make a syscall with three parameters.
 * 
 * @param syscall           The syscall to invoke.
 * @param reg_rdi           The value to pass to the rdi register (first parameter).
 * @param reg_rsi           The value to pass to the rsi register (second parameter).
 * @param reg_rdx           The value to pass to the rdx register (third parameter).
 * @return unsigned long    The return value of the syscall.
 */
unsigned long __syscall_3(reg64 syscall, reg64 reg_rdi, reg64 reg_rsi, reg64 reg_rdx);

/**
 * @brief                   Make a syscall with four parameters.
 * 
 * @param syscall           The syscall to invoke.
 * @param reg_rdi           The value to pass to the rdi register (first parameter).
 * @param reg_rsi           The value to pass to the rsi register (second parameter).
 * @param reg_rdx           The value to pass to the rdx register (third parameter).
 * @param reg_r10           The value to pass to the r10 register (fourth paramter).
 * @return unsigned long    The return value of the syscall.return unsigned 
 */
unsigned long __syscall_4(reg64 syscall, reg64 reg_rdi, reg64 reg_rsi, reg64 reg_rdx, reg64 reg_r10);

/**
 * @brief                   Make a syscall with five parameters.
 * 
 * @param syscall           The syscall to invoke.
 * @param reg_rdi           The value to pass to the rdi register (first parameter).
 * @param reg_rsi           The value to pass to the rsi register (second parameter).
 * @param reg_rdx           The value to pass to the rdx register (third parameter).
 * @param reg_r10           The value to pass to the r10 register (fourth paramter).
 * @param reg_r8            The value to pass to the r8  register (fifth parameter).
 * @return unsigned long    The return value of the syscall. 
 */
unsigned long __syscall_5(reg64 syscall, reg64 reg_rdi, reg64 reg_rsi, reg64 reg_rdx, reg64 reg_r10, reg64 reg_r8);

/**
 * @brief                   Make a syscall with five parameters.
 * 
 * @param syscall           The syscall to invoke.
 * @param reg_rdi           The value to pass to the rdi register (first parameter).
 * @param reg_rsi           The value to pass to the rsi register (second parameter).
 * @param reg_rdx           The value to pass to the rdx register (third parameter).
 * @param reg_r10           The value to pass to the r10 register (fourth paramter).
 * @param reg_r8            The value to pass to the r8  register (fifth parameter).
 * @param reg_r9            The value to pass to the r9  register (sixth parameter).
 * @return unsigned long    The return value of the syscall.
 */
unsigned long __syscall_6(reg64 syscall, reg64 reg_rdi, reg64 reg_rsi, reg64 reg_rdx, reg64 reg_r10, reg64 reg_r8, reg64 reg_r9);
/* NOLINTEND(bugprone-reserved-identifier) */

/**
 * @brief                   Wrapper for the read syscall. Reads count number of bytes from the file at the given file descriptor into buf.
 * 
 * @param file_descriptor   The file descriptor to read from.
 * @param buf               The buffer to read the data into.
 * @param count             The number of bytes to read.
 * @return int              On success, returns the number of bytes read from the file. On failure, returns -1 and errno is set.
 */
int read(int file_descriptor, void *buf, unsigned long count);

/**
 * @brief                   Wrapper for the write syscall. Writes count number of bytes from buf into the file at the given file descriptor.
 * 
 * @param file_descriptor   The file descriptor to write to.
 * @param buf               The buffer to write the data from.
 * @param count             The number of bytes to write.
 * @return int              On success, returns the number of bytes written. On failure, returns -1 and errno is set.
 */
int write(int file_descriptor, const char *buf, int count);

#endif /* SYSCALL_H */
