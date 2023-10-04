
#include <stdio.h>
#include <stdlib.h>

int main(void) {

    int i;
    i = (int)(sizeof(unsigned long));

    printf("sizeof(unsigned long): %d\n", i);

    return 0;
}
