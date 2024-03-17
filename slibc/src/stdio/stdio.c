#include <stdio.h>

static FILE _STDIN  = {0}; /* NOLINT(bugprone-reserved-identifier,cppcoreguidelines-avoid-non-const-global-variables,misc-non-copyable-objects) */
static FILE _STDOUT = {1}; /* NOLINT(bugprone-reserved-identifier,cppcoreguidelines-avoid-non-const-global-variables,misc-non-copyable-objects) */
static FILE _STDERR = {2}; /* NOLINT(bugprone-reserved-identifier,cppcoreguidelines-avoid-non-const-global-variables,misc-non-copyable-objects) */

FILE *_Files[FOPEN_MAX] = { &_STDIN, &_STDOUT, &_STDERR }; /* NOLINT(bugprone-reserved-identifier,cppcoreguidelines-avoid-non-const-global-variables) */
