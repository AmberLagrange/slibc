
#include <stdio.h>
#include <stdlib.h>

int main(void) {

    int *ptr_1;
    int *ptr_2;

    ptr_1 = malloc(sizeof(int));
    ptr_2 = malloc(sizeof(int));

    printf("ptr_1: %p\n", (void*)ptr_1);
    printf("ptr_2: %p\n", (void*)ptr_2);

    free(ptr_2);
    free(ptr_1);

    return 0;
}
