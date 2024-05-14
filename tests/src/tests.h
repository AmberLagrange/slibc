#include <stdio.h>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"

enum {
    PASS,
    FAIL,
    NA
};

#define PASSED   do { printf("%sPASSED%s\n",    GREEN, RESET); *(passed)   += 1; return; } while (0)
#define FAILED   do { printf("%sFAILED%s\n",      RED, RESET); *(failed)   += 1; return; } while (0)
#define DISABLED do { printf("%sDISABLED%s\n", YELLOW, RESET); *(disabled) += 1; return;   } while (0)

#define UNUSED(x) ((void)(x))

#define ASSERT_EQ(lhs, rhs)                     \
    do {                                        \
        if((lhs) != (rhs)) {                    \
            FAILED;                             \
        }                                       \
    } while(0)

#define ASSERT_NE(lhs, rhs)                     \
    do {                                        \
        if((lhs) == (rhs)) {                    \
            FAILED;                             \
        }                                       \
    } while(0)

#define ASSERT_LT(lhs, rhs)                     \
    do {                                        \
        if((lhs) >= (rhs)) {                    \
            FAILED;                             \
        }                                       \
    } while(0)

#define ASSERT_LE(lhs, rhs)                     \
    do {                                        \
        if((lhs) > (rhs)) {                     \
            FAILED;                             \
        }                                       \
    } while(0)

#define ASSERT_GT(lhs, rhs)                     \
    do {                                        \
        if((lhs) <= (rhs)) {                    \
            FAILED;                             \
        }                                       \
    } while(0)

#define ASSERT_GE(lhs, rhs)                     \
    do {                                        \
        if((lhs) < (rhs)) {                     \
            FAILED;                             \
        }                                       \
    } while(0)

void run_stdlib_tests(int *passed, int *failed, int *disabled);
void run_ctype_tests(int *passed, int *failed, int *disabled);
void run_stdio_tests(int *passed, int *failed, int *disabled);
void run_string_tests(int *passed, int *failed, int *disabled);
