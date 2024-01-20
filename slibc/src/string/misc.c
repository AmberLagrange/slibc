#include <string.h>

#define UNUSED(x) ((void)x)

char *strerror(int errno) {

    UNUSED(errno);

    return "UNIMPLEMENTED";
}
