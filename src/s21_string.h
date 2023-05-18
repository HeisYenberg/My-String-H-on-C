#ifndef S21_STRING_H
#define S21_STRING_H

#define s21_size_t unsigned long long
#define S21_NULL (void *)0

s21_size_t s21_strlen(const char *str);
char *s21_strcpy(char *dest, const char *src);
char *s21_strcat(char *dest, const char *src);
char *s21_strchr(const char *str, int c);
char *s21_strstr(const char *haystack, const char *needle);
int s21_strcmp(const char *str1, const char *str2);

#endif