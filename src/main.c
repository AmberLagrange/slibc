
#include "../include/stdio.h"

int main(int argc, char *argv[]) {

    int i;

    if (argc == 1) {
        printf("Please supply an argument!\n");
        return 1;
    }

    for (i = 1; i < argc; ++i) {
        printf(argv[i]);
        printf("\n");
    }

    return 0;
}
