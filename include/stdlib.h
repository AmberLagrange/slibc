#ifndef STDLIB_H
#define STDLIB_H

#define NULL ((void*)0)

/**
 * @brief           Parses a double from a given string.
 * 
 * @param str       The string to parse the double from.
 * @return double   The double that was parsed.
 */
double atof(const char *str);

/**
 * @brief           Parses an integer from a given string.
 * 
 * @param str       The string to parse the integer from.
 * @return int      The integer that was parsed.
 */
int atoi(const char *str);

/**
 * @brief           Parses a long integer from a given string.
 * 
 * @param str       The string to parse the long integer from.
 * @return long     The long integer that was parsed.
 */
long atol(const char *str);

/**
 * @brief           Parses a long integer from a given string in a chosen base.
 * 
 * @param str       The string to parse the long integer from.
 * @param str_end   The first character after the number parsed from str.
 * @param radix     The base to parse the character in.
 * @return long     The long integer that was parsed.
 */
long strtol(const char *str, char **str_end, int radix);

/**
 * @brief           Parses an unsigned long integer from a given string in a chosen base.
 * 
 * @param str       The string to parse the unsigned long integer from.
 * @param str_end   The first character after the number parsed from str.
 * @param radix     The base to parse the character in.
 * @return long     The unsigned long integer that was parsed.
 */
unsigned long strtoul(const char *str, char **str_end, int radix);

/**
 * @brief           Parses a double from a given string in a chosen base.
 * 
 * @param str       The string to parse the double from.
 * @param str_end   The first character after the number parsed from str.
 * @param radix     The base to parse the character in.
 * @return long     The double that was parsed.
 */
double strtod(const char *str, char **str_end);

/**
 * @brief           Creates memory region of a given size and returns it to the caller.
 * 
 * @param size      The size of the requested memory.
 * @return void*    The address of the memory that was created.
 */
void *malloc (unsigned long size);

/**
 * @brief           Creates a new memory region of a given size and copies the data over to this new region.
                    This also frees the old memory.
 * 
 * @param ptr       The pointer of the original memory region.
 * @param size      The requested size of the new memory region.
 * @return void*    The address of the new memory region.
 */
void *realloc(void *ptr, unsigned long size);

/**
 * @brief           Returns memory that was created used malloc.
 * 
 * @param ptr       The address of the memory to be returned.
 */
void free (void *ptr);

/**
 * @brief           Abort the running process. Internally, calls raise(SIG_ABORT) 
 * 
 */
__attribute__((noreturn)) void abort(void);

/**
 * @brief           Exits the running process by calling the SYS_EXIT syscall and returning the status to the parent process.
 * 
 */
__attribute__((noreturn)) void exit(int status);

#endif /* STDLIB_H */
