#include <stdio.h>

/* NOLINTBEGIN(bugprone-reserved-identifier,misc-non-copyable-objects) */
static FILE _STDIN  = {0};
static FILE _STDOUT = {1};
static FILE _STDERR = {2};
/* NOLINTEND(bugprone-reserved-identifier,misc-non-copyable-objects) */

FILE *_Files[FOPEN_MAX] = { &_STDIN, &_STDOUT, &_STDERR };
