#include "s21_string.h"

s21_size_t s21_strlen(const char *str) {
  s21_size_t result = 0;
  while (*str++)
    result++;
  return result;
}

char *s21_strcpy(char *dest, const char *src) {
  for (s21_size_t i = 0; i < s21_strlen(src) + 1; i++)
    dest[i] = src[i];
  return dest;
}

char *s21_strcat(char *dest, const char *src) {
  for (s21_size_t i = 0, j = s21_strlen(dest); i < s21_strlen(src) + 1; i++)
    dest[j + i] = src[i];
  return dest;
}

char *s21_strchr(const char *str, int c) {
  int found = 0;
  for (int i = 0; str[i]; i++) {
    if (str[i] == c) {
      found = 1;
      break;
    }
  }
  return !found ? S21_NULL : (char *) str;
}

char *s21_strstr(const char *haystack, const char *needle) {
  int found = 0;
  for (int i = 0; haystack[i]; i++) {
    if (haystack[i] == needle[0]) {
      found = 1;
      for (int j = 0; needle[j]; j++) {
        if (haystack[i + j] != needle[j]) {
          found = 0;
          break;
        }
      }
    }
  }
  return !found ? S21_NULL : (char *) haystack;
}

int s21_strcmp(const char *str1, const char *str2) {
  int differences = 0;
  if (s21_strlen(str1) < s21_strlen(str2))
    differences = -1;
  else if (s21_strlen(str1) > s21_strlen(str2))
    differences = 1;
  else {
    while (*str1++ && *str2++) {
      if (*str1 != *str2) {
        differences = 1;
        break;
      }
    }
  }
  return differences;
}