
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    int *ptr = malloc(sizeof(int));
    *ptr = 42;
    printf("Address: %p, Value: %d\n", ptr, *ptr);
    free(ptr);

    return 0;
}
