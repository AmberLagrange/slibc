
#include "../include/stdio.h"
#include "../include/stdlib.h"

#include "../include/mman.h"

int main(int argc, char *argv[]) {

    int *ptr = malloc(sizeof(int));
    *ptr = 42;
    printf("%d\n", *ptr);
    free(ptr);

    return 0;
}
