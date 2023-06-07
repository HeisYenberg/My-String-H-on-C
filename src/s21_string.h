#ifndef S21_STRING_H
#define S21_STRING_H

#include <limits.h>
#include <math.h>
#include <stdarg.h>
#include <stdlib.h>

#include "errors_list.h"

#define S21_NULL ((void *)0)
typedef unsigned long long s21_size_t;

typedef struct format_sprintf {
  char specificator, length_description;
  int dash, plus, zero, hash, space, width, precision;
} Format_sprintf;

typedef struct format_sscanf {
  int asterisk, width;
  char specificator, length_description;
} Format_sscanf;

void *s21_memchr(const void *str, int c, s21_size_t n);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
char *s21_strchr(const char *str, int c);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
s21_size_t s21_strcspn(const char *str1, const char *str2);
char *s21_strerror(int errnum);
s21_size_t s21_strlen(const char *str);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strrchr(const char *str, int c);
char *s21_strstr(const char *haystack, const char *needle);
char *s21_strtok(char *str, const char *delim);

int s21_sprintf(char *str, const char *format, ...);
int read_format_sprintf(va_list args, const char *format,
                        Format_sprintf *input);
int get_width_and_pressision(const char *format, int dot, Format_sprintf *input,
                             va_list args);

char *s21_take_string(va_list args, Format_sprintf *input);
char *s21_take_char(va_list args, Format_sprintf *input, int *end_string);
char *s21_take_integer(va_list args, Format_sprintf *input);
char *s21_signed(va_list args, Format_sprintf *input, int *negative);
char *s21_unsigned(va_list args, Format_sprintf *input, int *negative);
void handle_int_flags(char *filling, char *integer, Format_sprintf *input,
                      int negative, int sign_add, int hex_add);
char *s21_take_float(va_list args, Format_sprintf *input);
char *s21_decimal(long double va_decimal, Format_sprintf *input);
char *s21_double(long double va_float, Format_sprintf *input);
char *s21_notation(long double va_float, Format_sprintf *input);
void s21_spec_n(va_list args, Format_sprintf *input, int count);
void handle_trailing_zeros(char *decimal);

int s21_sscanf(char *str, const char *format, ...);
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

long int s21_atoi(const char *str, int base);
char *s21_itoa(long int, char *str, int base);
long double s21_atof(const char *str);
char *s21_ftoa(long double num, char *str, int afterpoint);
long double s21_frexp(long double x, int *e);

void *s21_to_upper(const char *str);
void *s21_to_lower(const char *str);
void *s21_insert(const char *src, const char *str, s21_size_t start_index);
void *s21_trim(const char *src, const char *trim_chars);

#endif