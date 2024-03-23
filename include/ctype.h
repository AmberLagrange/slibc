#ifndef CTYPE_H
#define CTYPE_H

#ifdef __cplusplus
#define __THROW throw()
extern "C" {
#else
#define __THROW
#endif

/**
 * @brief               Checks if a given character is alphanumeric.
 * 
 * @param character     The character to check.
 * @return int          Returns 1 if alphanumeric, and 0 otherwise.
 */
int isalnum(int character) __THROW;

/**
 * @brief               Checks if a given character is a letter.
 * 
 * @param character     The character to check.
 * @return int          Returns 1 if alphanumeric, and 0 otherwise.
 */
int isalpha(int character) __THROW;

/**
 * @brief               Checks if a given character is a blank character used to separate words within a line.
 * 
 * @param character     The character to check.
 * @return int          Returns 1 if alphanumeric, and 0 otherwise.
 */
int isblank(int character) __THROW;

/**
 * @brief               Checks if a given character is a lowercase letter.
 * 
 * @param character     The character to check.
 * @return int          Returns 1 if alphanumeric, and 0 otherwise.
 */
int islower(int character) __THROW;

/**
 * @brief               Checks if a given character is an uppercase letter.
 * 
 * @param character     The character to check.
 * @return int          Returns 1 if alphanumeric, and 0 otherwise.
 */
int isupper(int character) __THROW;

/**
 * @brief               Checks if a given character is a digit.
 * 
 * @param character     The character to check.
 * @return int          Returns 1 if alphanumeric, and 0 otherwise.
 */
int isdigit(int character) __THROW;

/**
 * @brief               Checks if a given character is a hexidecimal digit.
 * 
 * @param character     The character to check.
 * @return int          Returns 1 if alphanumeric, and 0 otherwise.
 */
int isxdigit(int character) __THROW;

/**
 * @brief               Checks if a given character is a control character.
 * 
 * @param character     The character to check.
 * @return int          Returns 1 if alphanumeric, and 0 otherwise.
 */
int iscntrl(int character) __THROW;

/**
 * @brief               Checks if a given character is a graphical character.
 * 
 * @param character     The character to check.
 * @return int          Returns 1 if alphanumeric, and 0 otherwise.
 */
int isgraph(int character) __THROW;

/**
 * @brief               Checks if a given character is whitespace character.
 * 
 * @param character     The character to check.
 * @return int          Returns 1 if alphanumeric, and 0 otherwise.
 */
int isspace(int character) __THROW;

/**
 * @brief               Checks if a given character is a printable.
 * 
 * @param character     The character to check.
 * @return int          Returns 1 if alphanumeric, and 0 otherwise.
 */
int isprint(int character) __THROW;

/**
 * @brief               Checks if a given character is a punctuation character.
 * 
 * @param character     The character to check.
 * @return int          Returns 1 if alphanumeric, and 0 otherwise.
 */
int ispunct(int character) __THROW;

/**
 * @brief               Converts a lowercase letter into its uppercase form.
 * 
 * @param character     The character to convert.
 * @return int          The uppercase letter, or the original character if it is not a lowercase character.
 */
int toupper(int character) __THROW;

/**
 * @brief               Converts an uppercase letter into its lowercase form.
 * 
 * @param character     The character to convert.
 * @return int          The lowercase letter, or the original character if it is not an uppercase character.
 */
int tolower(int character) __THROW;

#undef __THROW

#ifdef __cplusplus
}
#endif

#endif /* CTYPE */
