#ifndef CTYPE_H
#define CTYPE_H

#ifdef __cplusplus
#define __THROW throw()
extern "C" {
#else
#define __THROW
#endif

int isalnum(int character)   __THROW;
int isalpha(int character)   __THROW;
int isblank(int character)   __THROW;
int islower(int character)   __THROW;
int isupper(int character)   __THROW;
int isdigit(int character)   __THROW;
int isxdigit(int character)  __THROW;
int iscntrl(int character)   __THROW;
int isgraph(int character)   __THROW;
int isspace(int character)   __THROW;
int isprint(int character)   __THROW;
int ispunct(int character)   __THROW;

int toupper(int character) __THROW;
int tolower(int character) __THROW;

#undef __THROW

#ifdef __cplusplus
}
#endif

#endif /* CTYPE */
