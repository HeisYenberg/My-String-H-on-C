#ifndef MY_STRING_H
#define MY_STRING_H

#include <limits.h>
#include <math.h>
#include <stdarg.h>
#include <stdlib.h>

#include "errors_list.h"

#define MY_NULL ((void *)0)
typedef unsigned long long my_size_t;

typedef struct format_sprintf {
  char specificator, length_description;
  int dash, plus, zero, hash, space, width, precision;
} Format_sprintf;

typedef struct format_sscanf {
  int asterisk, width;
  char specificator, length_description;
} Format_sscanf;

void *my_memchr(const void *str, int c, my_size_t n);
int my_memcmp(const void *str1, const void *str2, my_size_t n);
void *my_memcpy(void *dest, const void *src, my_size_t n);
void *my_memset(void *str, int c, my_size_t n);
char *my_strncat(char *dest, const char *src, my_size_t n);
char *my_strchr(const char *str, int c);
int my_strncmp(const char *str1, const char *str2, my_size_t n);
char *my_strncpy(char *dest, const char *src, my_size_t n);
my_size_t my_strcspn(const char *str1, const char *str2);
char *my_strerror(int errnum);
my_size_t my_strlen(const char *str);
char *my_strpbrk(const char *str1, const char *str2);
char *my_strrchr(const char *str, int c);
char *my_strstr(const char *haystack, const char *needle);
char *my_strtok(char *str, const char *delim);

int my_sprintf(char *str, const char *format, ...);
int read_format_sprintf(va_list args, const char *format,
                        Format_sprintf *input);
int get_width_and_pressision(const char *format, int dot, Format_sprintf *input,
                             va_list args);

char *take_string(va_list args, Format_sprintf *input);
char *take_char(va_list args, Format_sprintf *input, int *end_string);
char *take_integer(va_list args, Format_sprintf *input);
char *my_signed(va_list args, Format_sprintf *input, int *negative);
char *my_unsigned(va_list args, Format_sprintf *input, int *negative);
void handle_int_flags(char *filling, char *integer, Format_sprintf *input,
                      int negative, int sign_add, int hex_add);
char *take_float(va_list args, Format_sprintf *input);
char *my_decimal(long double va_decimal, Format_sprintf *input);
char *my_double(long double va_float, Format_sprintf *input);
char *my_notation(long double va_float, Format_sprintf *input);
void spec_n(va_list args, Format_sprintf *input, int count);
void handle_trailing_zeros(char *decimal);

int my_sscanf(char *str, const char *format, ...);
int read_format_sscanf(const char *format, Format_sscanf *input);
int clean_spaces(char *str, Format_sscanf input);
int write_string(va_list args, char *str, Format_sscanf input, int *writen);
int write_char(va_list args, const char *str, Format_sscanf input, int *writen);
int write_signed_int(va_list args, const char *str, Format_sscanf input,
                     int *writen);
int write_unsigned_int(va_list args, char *str, Format_sscanf input,
                       int *writen);
int parse_float(va_list args, char *str, Format_sscanf input, int *writen);
void write_float(va_list args, char *number, Format_sscanf input, int *writen);

long int my_atoi(const char *str, int base);
char *my_itoa(long int, char *str, int base);
long double my_atof(const char *str);
char *my_ftoa(long double num, char *str, int afterpoint);
long double my_frexp(long double x, int *e);

void *my_to_upper(const char *str);
void *my_to_lower(const char *str);
void *my_insert(const char *src, const char *str, my_size_t start_index);
void *my_trim(const char *src, const char *trim_chars);

#endif  // MY_STRING_H