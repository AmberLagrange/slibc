#ifndef MMAN_H
#define MMAN_H

/**
 * @brief Memory protection of the memory requested from mmap.
 * 
 */
enum {
    PROT_NONE   = 0x00, /**< No access. */
    PROT_READ   = 0x01, /**< May be read from. */
    PROT_WRITE  = 0x02, /**< May be written to. */
    PROT_EXEC   = 0x04  /**< May be executed. */
};

/**
 * @brief Flags passed to mmap to specify behaviour of mmap.
 * 
 */
enum {
    MAP_SHARED      = 0x00000001,    /**< Updates are visible to other processes using the same mapping region. */
    MAP_PRIVATE     = 0x00000002,    /**< Updates are not visible to other processes. */
    MAP_FIXED       = 0x00000010,    /**< Don't use addr as a hint and instead use it exactly. */
    MAP_ANONYMOUS   = 0x00000020,    /**< Don't back the mapping with a file. */
    MAP_ANON        = MAP_ANONYMOUS, /**< Same as MAP_ANONYYMOUS. Used for backwards compatibility. */
    MAP_STACK       = 0x00020000     /**< The mapping is suitable for a process stack. */
};

/**
 * @brief                   Wrapper for the SYS_MMAP syscall. Creates a mapping in virtual address space.
 * 
 * @param addr              The starting address for the mapping. If NULL, the kernel provides a page-aligned address.
 * @param len               The length of the mapping, must be greter than 0.
 * @param prot              The protection of the memory region. RWX
 * @param flags             Flags passed to kernel to modify the behaviour of the mapping.
 * @param file_descriptor   The file descriptor of the file to map memory in. Usually -1 if MAP_ANONYMOUS is specified.
 * @param offset            An offset into the memory to start mapping from.
 * @return void*            On success, the return value is a pointer to the start of the allotted memory region.
 *                          On failure, returns a pointer to address -1 and errno is set.
 */
void *mmap(void *addr, unsigned long len, unsigned long prot, unsigned long flags, unsigned long file_descriptor, unsigned long offset);

/**
 * @brief                   Wrapper for the SYS_MUNMAP syscall. Deletes a mapping returned by mmap.
 * 
 * @param addr              The address of the start of the memory returned by mmap.
 * @param len               The length of the memory returned by mmap.
 * @return int              On success, returns 0. On failure, retuns -1 and errno is set.
 */
int munmap(void *addr, unsigned long len);

#endif /* MMAN_H */
