#ifndef STRING_H
#define STRING_H

#ifndef SIZE_T
#define SIZE_T

    typedef unsigned long size_t;

#endif

#define NULL ((void*)0)

#ifdef __cplusplus
extern "C" {
#endif

/* String Manip */

char  *strcpy (char *dst, const char *src);
char  *strncpy(char *dst, const char *src, size_t count);
char  *strcat (char *dst, const char *src);
char  *strncat(char *dst, const char *src, size_t count);
size_t strxfrm(char *dst, const char *src, size_t count);

/* String Exam */

size_t strlen (const char *str);
int    strcmp (const char *lhs, const char *rhs);
int    strncmp(const char *lhs, const char *rhs, size_t count);
int    strcoll(const char *lhs, const char *rhs);
char  *strchr (const char *str, int character);
char  *strrchr(const char *str, int character);
size_t strspn (const char *dst, const char *src);
size_t strcspn(const char *dst, const char *src);
char  *strpbrk(const char *dst, const char *set);
char  *strstr (const char *str, const char *substr);
char  *strtok (      char *str, const char *token);

/* Char Array Manip */

void *memchr (const void *ptr, int character,   size_t count);
int   memcmp (const void *lhs, const void *rhs, size_t count);
void *memset (void *str,       int character,   size_t count);
void *memmove(void *dst,       const void *src, size_t count);
void *memcpy (void *dst,       const void *src, size_t count);

/* Misc */

char *strerror(int errno);

#ifdef __cplusplus
}
#endif

#endif /* STRING_H */
