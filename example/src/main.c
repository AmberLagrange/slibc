#include <stdio.h>
#include <stdlib.h>

int main(void) {

    int in;

    while (scanf("%d", &in) && in != 0) {
        printf("%d\n", in);
    }

    return 0;
}
