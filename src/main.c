
#include "../include/stdlib.h"

void foo(int syscall, ...) {
    
}

int main(int argc, char *argv[]) {

    if (argc == 1) {
        write(0, "Please supply an argument!\n", 27);
        return 1;
    }

    int i;
    for (i = 0;; ++i) {
        if (!argv[1][i]) {
            break;
        }
    }

    write(0, argv[1], i);
    write(0, "\n", 1);

    return 0;
}
