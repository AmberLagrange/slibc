
#include "../include/stdio.h"
#include "../include/stdlib.h"

int main(int argc, char *argv[]) {

    int *ptr = malloc(sizeof(int));
    *ptr = 42;

    printf("Address: %p, Value: %d\n", ptr, *ptr);

    free(ptr);


    return 0;
}
