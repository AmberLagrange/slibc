#include <stdio.h>

#include <stdlib.h>

enum RADIX_T {
    DEC_RADIX = 10
};

/**
 * @example 
 */
int main(void) {

    int num_read = 0;

    char *num = "     1234";
    printf("strtol: %ld\n", strtol(num, NULL, DEC_RADIX));

    printf("Hello, %s\n", "World!");
    printf("This should have padding (it doesn't): %5d\n", 0);
    printf("123456789%n\n", &num_read);
    printf("Wrote %d characters!\n", num_read);

    return 0;
}
