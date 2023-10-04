
#include "../include/stdio.h"
#include "../include/stdlib.h"

#include <sys/mman.h>

int main(int argc, char *argv[]) {

    int *ptr = mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    *ptr = 42;
    printf("%d\n", *ptr);
    munmap(ptr, sizeof(int));

    return 0;
}
