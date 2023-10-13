#include <stdio.h>
#include <stdlib.h>

int main(void) {

    int *ptr_1;
    int *ptr_2;

    ptr_1 = malloc(sizeof(int) * 1);
    *ptr_1 = 42;
    printf("Before realloc: pointer: %p, value: %d\n", (void *)ptr_1, *ptr_1);
    ptr_2 = realloc(ptr_1, 2);
    ptr_2[0] = 0x42;
    ptr_2[1] = 0x1337;
    printf("After realloc: pointer: %p, values: 0x%x, 0x%x\n", (void *)ptr_2, ptr_2[0], ptr_2[1]);
    free(ptr_2);
    printf("This might segfault: 0x%x\n", *ptr_1);
    printf("This might also segfault: %d\n", ptr_2[0]);

    return 0;
}
