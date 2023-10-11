#ifndef CONVERT_H
#define CONVERT_H

char *__itoa__internal(int i, char *buf, int len, int base, int is_unsigned);
char *__ltoa__internal(long l, char *buf, int len, int base, int is_unsigned);

#endif /* CONVERT_H */
