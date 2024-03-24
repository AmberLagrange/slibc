#ifndef CONVERT_H
#define CONVERT_H

#ifndef SIZE_T
#define SIZE_T

    typedef unsigned long size_t;

#endif

/* NOLINTBEGIN(bugprone-reserved-identifier) */
enum {
    OCT_RADIX = 8,
    DEC_RADIX = 10,
    HEX_RADIX = 16
};

/**
 * @brief               Internal use only. Convert an integer into a string.
 * 
 * @param int_val       The value of the integer to convert.
 * @param buf           The address to the buffer to write the integer to.
 * @param len           The length of the buffer.
 * @param radix         The base to write the integer in.
 * @param is_unsigned   If the integer is unsigned.
 * @return char*        Returns the address of the buffer written to.
 */
char *__itoa__internal(int int_val, char *buf, size_t len, int radix, int is_unsigned);

/**
 * @brief               Internal use only. Convert a long integer into a string.
 * 
 * @param int_val       The value of the long integer to convert.
 * @param buf           The address to the buffer to write the long integer to.
 * @param len           The length of the buffer.
 * @param radix         The base to write the long integer in.
 * @param is_unsigned   If the long integer is unsigned.
 * @return char*        Returns the address of the buffer written to.
 */
char *__ltoa__internal(long long_val, char *buf, size_t len, int radix, int is_unsigned);
/* NOLINTEND(bugprone-reserved-identifier) */

#endif /* CONVERT_H */
