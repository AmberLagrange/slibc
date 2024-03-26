#include <stdio.h>

/**
 * @example 
 */
int main(void) {

    int num_read = 0;

    printf("Hello, %s\n", "World!");
    printf("This should have padding (it doesn't): %5d\n", 0);
    printf("123456789%n\n", &num_read);
    printf("Wrote %d characters!\n", num_read);

    return 0;
}
