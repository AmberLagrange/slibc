#ifndef MMAN_H
#define MMAN_H

#define	PROT_NONE       0x00
#define	PROT_READ       0x01
#define	PROT_WRITE      0x02
#define	PROT_EXEC       0x04

#define	MAP_SHARED      0x0001
#define	MAP_PRIVATE     0x0002
#define	MAP_FIXED       0x0010
#define	__MAP_NOREPLACE 0x0800
#define	MAP_ANON        0x1000
#define	__MAP_NOFAULT   0x2000
#define	MAP_STACK       0x4000
#define	MAP_CONCEAL     0x8000

void *mmap(void *addr, unsigned long len, unsigned long prot, unsigned long flags, unsigned long fd, unsigned long offset);
int munmap(void *addr, unsigned long len);

#endif /* MMAN_H */
