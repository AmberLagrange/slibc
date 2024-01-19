#ifndef CTYPE_H
#define CTYPE_H

#ifdef __cplusplus
#define __THROW throw()
extern "C" {
#else
#define __THROW
#endif

int isalnum(int c)   __THROW;
int isalpha(int c)   __THROW;
int isblank(int c)   __THROW;
int islower(int c)   __THROW;
int isupper(int c)   __THROW;
int isdigit(int c)   __THROW;
int isxdigit(int c)  __THROW;
int iscntrl(int c)   __THROW;
int isgraph(int c)   __THROW;
int isspace(int c)   __THROW;
int isprint(int c)   __THROW;
int ispunct(int c)   __THROW;

int toupper(int c) __THROW;
int tolower(int c) __THROW;

#undef __THROW

#ifdef __cplusplus
}
#endif

#endif /* CTYPE */
