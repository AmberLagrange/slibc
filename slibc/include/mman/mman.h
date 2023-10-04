#ifndef MMAN_H
#define MMAN_H

#define	PROT_NONE       0x00
#define	PROT_READ       0x01
#define	PROT_WRITE      0x02
#define	PROT_EXEC       0x04

#define MAP_SHARED      0x00000001
#define MAP_PRIVATE     0x00000002
#define MAP_FIXED       0x00000010
#define MAP_ANON        0x00000020
#define MAP_ANONYMOUS   0x00000020
#define MAP_STACK       0x00020000

void *mmap(void *addr, unsigned long len, unsigned long prot, unsigned long flags, unsigned long fd, unsigned long offset);
int munmap(void *addr, unsigned long len);

#endif /* MMAN_H */
