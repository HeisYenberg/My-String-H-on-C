#include "s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  unsigned const char *temp = str;
  void *result = S21_NULL;
  for (s21_size_t i = 0; i < n && !result; i++) {
    if (temp[i] == c) result = (void *)(temp + i);
  }
  return result;
}

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  unsigned const char *temp1 = str1, *temp2 = str2;
  int differences = 0;
  for (s21_size_t i = 0; i < n && !differences; i++) {
    if (temp1[i] != temp2[i]) {
      differences = temp1[i] - temp2[i];
    }
  }
  return differences;
}

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  unsigned char *temp_dest = dest;
  unsigned const char *temp_src = src;
  for (s21_size_t i = 0; i < n; i++) temp_dest[i] = temp_src[i];
  return (void *)temp_dest;
}

void *s21_memset(void *str, int c, s21_size_t n) {
  unsigned char *temp = str;
  for (s21_size_t i = 0; i < n; i++) {
    temp[i] = c;
  }
  return temp;
}

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  s21_strncpy(dest + s21_strlen(dest), src, n);
  return dest;
}

char *s21_strchr(const char *str, int c) {
  char *result = S21_NULL;
  int str_len = s21_strlen(str), stop = 0;
  for (int i = 0; i < str_len + 1 && !stop; i++) {
    if (str[i] == c) {
      result = (char *)str + i;
      stop = 1;
    }
  }
  return result;
}

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  s21_size_t len_str1 = s21_strlen(str1);
  int differences = 0;
  for (s21_size_t i = 0; i < len_str1 + 1 && i < n && !differences; i++) {
    if (str1[i] != str2[i]) differences = str1[i] - str2[i];
  }
  return differences;
}

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  s21_size_t src_len = s21_strlen(src);
  for (s21_size_t i = 0; i < src_len + 1 && i < n; i++) dest[i] = src[i];
  return dest;
}

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t non_matching = 0;
  while (!s21_strchr(str2, str1[non_matching])) non_matching++;
  return non_matching;
}

char *s21_strerror(int errnum) {
  static char error[100];
  if (errnum >= 0 && errnum < ERRNUM_MAX)
    s21_sprintf(error, "%s", error_list[errnum]);
  else {
    s21_sprintf(error, "%s%d", UNKNOWN_ERROR, errnum);
  }
  return error;
}

s21_size_t s21_strlen(const char *str) {
  s21_size_t result = 0;
  while (*str++) result++;
  return result;
}

char *s21_strpbrk(const char *str1, const char *str2) {
  char *result = S21_NULL;
  int str1_len = s21_strlen(str1), stop = 0;
  for (int i = 0; i < str1_len && !stop; i++) {
    if (s21_strchr(str2, str1[i])) {
      result = (char *)str1 + i;
      stop = 1;
    }
  }
  return result;
}

char *s21_strrchr(const char *str, int c) {
  char *result = S21_NULL;
  int found = -1, str_len = s21_strlen(str);
  for (int i = 0; i < str_len + 1; i++) {
    if (str[i] == c) {
      found = i;
    }
  }
  if (found > -1) result = (char *)str + found;
  return result;
}

char *s21_strstr(const char *haystack, const char *needle) {
  char *result = S21_NULL;
  int found = -1, len_haystack = s21_strlen(haystack), stop = 0,
      len_needle = s21_strlen(needle);
  for (int i = 0; i < len_haystack + 1 && !stop; i++) {
    if (haystack[i] == needle[0]) {
      found = i;
      for (int j = 0; j < len_needle && found > -1; j++) {
        if (haystack[i + j] != needle[j]) found = -1;
      }
      if (found > -1) stop = 1;
    }
  }
  if (found == len_haystack)
    result = (char *)haystack;
  else if (found > -1)
    result = (char *)haystack + found;
  return result;
}

char *s21_strtok(char *str, const char *delim) {
  static char *original_string = S21_NULL;
  char temp = 0;
  if (!str) str = original_string;
  while (s21_strchr(delim, temp) && str) {
    if (!(temp = *str++)) str = S21_NULL;
  }
  if (str) {
    str--;
    original_string = str + s21_strcspn(str, delim);
    if (*original_string) *original_string++ = '\0';
  } else
    original_string = S21_NULL;
  return str;
}