
#include "../include/stdio.h"
#include "../include/stdlib.h"

int main(int argc, char *argv[]) {

    int i;
    int *ptr;
    char *ptr_2;

    if (argc == 1) {
        i = puts("Please supply an argument!");
        return i;
    }

    for (i = 1; i < argc; ++i) {
        printf("Argument %d: Address: %p, Value: %s\n", i, argv[i], argv[i]);
    }

    ptr = malloc(sizeof(int));
    ptr_2 = malloc(sizeof(char));

    printf("%p\n", ptr);
    printf("%p\n", ptr_2);
    free(ptr);
    free(ptr_2);

    return 0;
}
