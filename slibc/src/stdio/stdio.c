#include <stdio.h>

static FILE _STDIN  = {0};
static FILE _STDOUT = {1};
static FILE _STDERR = {2};

FILE *_Files[FOPEN_MAX] = { &_STDIN, &_STDOUT, &_STDERR };
