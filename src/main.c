
#include "../include/stdlib.h"
#include "../include/string.h"

int main(int argc, char *argv[]) {

    if (argc == 1) {
        write(0, "Please supply an argument!\n", 27);
        return 1;
    }

    write(0, argv[1], strlen(argv[1]));
    write(0, "\n", 1);

    return 0;
}
