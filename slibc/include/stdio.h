#ifndef STDIO_H
#define STDIO_H

#include <stdarg.h>

/*
    Typedefs
*/

#ifndef SIZE_T
#define SIZE_T

    typedef unsigned long size_t;

#endif

/*
    Macros
*/

#define NULL            ((void*)0)

#define EOF             (-1)
#define FOPEN_MAX       256
#define FILENAME_MAX    256
#define BUFSIZ          256

/* NOLINTBEGIN(bugprone-reserved-identifier) */
#define _IOFBF          1
#define _IOLBF          2
#define _IONBF          3
/* NOLINTEND(bugprone-reserved-identifier) */

#define SEEK_SET        4
#define SEEK_CUR        5
#define SEEK_END        6

#define TMP_MAX         16
#define L_tmpnam        256

/*
    Structs
    TODO: actually implement this properly
*/

/* NOLINTBEGIN(bugprone-reserved-identifier) */
typedef struct __FILE_IO {
    int fd;
} FILE;

typedef struct __FILE_POS {
    long pos;
} fpos_t;
/* NOLINTEND(bugprone-reserved-identifier) */

/*
    File access
*/

FILE *fopen  (const char *filename, const char *mode);
FILE *freopen(const char *filename, const char *mode, FILE *file);

int   fclose (FILE       *file);
int   fflush (FILE       *file);

void  setbuf (FILE       *file, char           *buffer);
int   setvbuf(FILE       *file, char           *buffer, int mode, size_t size);

/*
    Direct input/output
*/

size_t fread (      void *buffer, size_t size, size_t count, FILE *file);
size_t fwrite(const void *buffer, size_t size, size_t count, FILE *file);

/*
    Unformatted input/output
*/

int   fgetc(                      FILE *file);
int   getc (                      FILE *file);
char *fgets(char *str, int count, FILE *file);

int   fputc  (int         character,  FILE *file);
int   putc   (int         character,  FILE *file);
int   fputs  (const char *str, FILE *file);

int   getchar(void);
char *gets   (char *str);

int   putchar(int character);
int   puts   (const char *str);

int   ungetc (int character, FILE *file);

/*
    Formatted input/output
*/

int scanf (const char *fmt,                     ...);
int fscanf(FILE       *file,   const char *fmt, ...);
int sscanf(const char *buffer, const char *fmt, ...);

int printf (const char *fmt,                     ...);
int fprintf(FILE       *file,   const char* fmt, ...);
int sprintf(char       *buffer, const char* fmt, ...);

int vprintf (const char *fmt,                     va_list args);
int vfprintf(FILE       *file,   const char *fmt, va_list args);
int vsprintf(char       *buffer, const char *fmt, va_list args);

/*
    File positioning
*/

long ftell  (FILE *file);
int  fgetpos(FILE *file, fpos_t       *pos);
int  fseek  (FILE *file, long          offset, int origin);
int  fsetpos(FILE *file, const fpos_t *pos);
void rewind (FILE *file);

/*
    Error Handling
*/

void clearerr(FILE *file);
int  foef    (FILE *file);
int  ferror  (FILE *file);
void perror  (const char *str);

/*
    Operations on files
*/

int   remove (const char *pathname);
int   rename (const char *old_filename, const char *new_filename);
FILE *tmpfile(void);
char *tmpnam (char *filename);

/*
    Standard files
*/

/* NOLINTNEXTLINE(bugprone-reserved-identifier) */
extern FILE *_Files[FOPEN_MAX];   

#define stdin  _Files[0]
#define stdout _Files[1]
#define stderr _Files[2]

#endif /* STDIO_H */
