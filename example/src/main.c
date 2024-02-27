#include <stdio.h>
#include <ctype.h>

int main(void) {

    int n = 123;

    printf("Hello, %s\n", "World!");
    printf("This should have padding (it doesn't): %5d\n", 5);
    printf("123456789%n\n", &n);
    printf("Wrote %d characters!\n", n);

    return 0;
}
