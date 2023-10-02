
#include "../include/stdio.h"

int main(int argc, char *argv[]) {

    int i;

    if (argc == 1) {
        i = puts("Please supply an argument!");
        return i;
    }

    for (i = 1; i < argc; ++i) {
        printf("Argument %d: Address: %p, Value: %s\n", i, argv[i], argv[i]);
    }

    return 0;
}
