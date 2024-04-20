#include <stdio.h>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"

#define ASSERT_EQ(lhs, rhs)                     \
    do {                                        \
        if((lhs) != (rhs)) {                    \
            printf("%sFAILED%s\n", RED, RESET); \
            return 1;                           \
        }                                       \
    } while(0)

#define ASSERT_NE(lhs, rhs)                     \
    do {                                        \
        if((lhs) == (rhs)) {                    \
            printf("%sFAILED%s\n", RED, RESET); \
            return 1;                           \
        }                                       \
    } while(0)

#define ASSERT_LT(lhs, rhs)                     \
    do {                                        \
        if((lhs) >= (rhs)) {                    \
            printf("%sFAILED%s\n", RED, RESET); \
            return 1;                           \
        }                                       \
    } while(0)

#define ASSERT_LE(lhs, rhs)                     \
    do {                                        \
        if((lhs) > (rhs)) {                     \
            printf("%sFAILED%s\n", RED, RESET); \
            return 1;                           \
        }                                       \
    } while(0)

#define ASSERT_GT(lhs, rhs)                     \
    do {                                        \
        if((lhs) <= (rhs)) {                    \
            printf("%sFAILED%s\n", RED, RESET); \
            return 1;                           \
        }                                       \
    } while(0)

#define ASSERT_GE(lhs, rhs)                     \
    do {                                        \
        if((lhs) < (rhs)) {                     \
            printf("%sFAILED%s\n", RED, RESET); \
            return 1;                           \
        }                                       \
    } while(0)

#define PASSED   do { printf("%sPASSED%s\n",    GREEN, RESET); return 0; } while (0)
#define FAILED   do { printf("%sFAILED%s\n",      RED, RESET); return 1; } while (0)
#define DISABLED do { printf("%sDISABLED%s\n", YELLOW, RESET); return 0; } while (0)

int run_stdlib_tests(void);
int run_ctype_tests(void);
int run_stdio_tests(void);
int run_string_tests(void);
