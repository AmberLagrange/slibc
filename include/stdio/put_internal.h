#ifndef PUT_INTERNAL_H
#define PUT_INTERNAL_H

#include <stdio.h>
#include <stdlib/convert.h>

#define MAX_INT_LENGTH 256

/* NOLINTBEGIN(bugprone-reserved-identifier) */
/**
 * @brief               Internal use only. Helper function for writing
 *                      an integer to a file.
 * 
 * @param val           The value of the integer to write.
 * @param radix         The base to write the integer in.
 * @param file          The file to write the integer to.
 * @param is_unsigned   If the integer is unsigned.
 * @return int          Returns the number of bytes written to the file. Returns a negative on error.
 */
int __fputi_internal (int val, enum __radix_e radix, FILE *file, int is_unsigned);

/**
 * @brief               Internal use only. Helper function for writing
 *                      a long integer to a file.
 * 
 * @param val           The value of the long integer to write.
 * @param radix         The base to write the long integer in.
 * @param file          The file to write the long integer to.
 * @param is_unsigned   If the long integer is unsigned.
 * @return int          Returns the number of bytes written to the file. Returns a negative on error.
 */
int __fputl_internal (long val, enum __radix_e radix, FILE *file, int is_unsigned);

/**
 * @brief               Internal use only. Helper function for writing
 *                      a double to a file.
 * 
 * @param val           The value of the double to write.
 * @param file          The file to write the double to.
 * @return int          Returns the number of bytes written to the file. Returns a negative on error.
 */
int __fputf_internal (double val, FILE *file);

/**
 * @brief               Internal use only. Helper function for writing
 *                      a long double to a file.
 * 
 * @param val           The value of the long double to write.
 * @param file          The file to write the long double to.
 * @return int          Returns the number of bytes written to the file. Returns a negative on error.
 */
int __fputlf_internal(long double val, FILE *file);
/* NOLINTEND(bugprone-reserved-identifier) */

#endif /* PUT_INTERNAL_H */
