#include "my_string.h"

void *my_memchr(const void *str, int c, my_size_t n) {
  unsigned const char *temp = str;
  void *result = MY_NULL;
  for (my_size_t i = 0; i < n && !result; i++) {
    if (temp[i] == c) result = (void *)(temp + i);
  }
  return result;
}

int my_memcmp(const void *str1, const void *str2, my_size_t n) {
  unsigned const char *temp1 = str1, *temp2 = str2;
  int differences = 0;
  for (my_size_t i = 0; i < n && !differences; i++) {
    if (temp1[i] != temp2[i]) {
      differences = temp1[i] - temp2[i];
    }
  }
  return differences;
}

void *my_memcpy(void *dest, const void *src, my_size_t n) {
  unsigned char *temp_dest = dest;
  unsigned const char *temp_src = src;
  for (my_size_t i = 0; i < n; i++) temp_dest[i] = temp_src[i];
  return (void *)temp_dest;
}

void *my_memset(void *str, int c, my_size_t n) {
  unsigned char *temp = str;
  for (my_size_t i = 0; i < n; i++) {
    temp[i] = c;
  }
  return temp;
}

char *my_strncat(char *dest, const char *src, my_size_t n) {
  my_strncpy(dest + my_strlen(dest), src, n);
  return dest;
}

char *my_strchr(const char *str, int c) {
  char *result = MY_NULL;
  int str_len = my_strlen(str), stop = 0;
  for (int i = 0; i < str_len + 1 && !stop; i++) {
    if (str[i] == c) {
      result = (char *)str + i;
      stop = 1;
    }
  }
  return result;
}

int my_strncmp(const char *str1, const char *str2, my_size_t n) {
  my_size_t len_str1 = my_strlen(str1);
  int differences = 0;
  for (my_size_t i = 0; i < len_str1 + 1 && i < n && !differences; i++) {
    if (str1[i] != str2[i]) differences = str1[i] - str2[i];
  }
  return differences;
}

char *my_strncpy(char *dest, const char *src, my_size_t n) {
  my_size_t src_len = my_strlen(src);
  for (my_size_t i = 0; i < src_len + 1 && i < n; i++) dest[i] = src[i];
  return dest;
}

my_size_t my_strcspn(const char *str1, const char *str2) {
  my_size_t non_matching = 0;
  while (!my_strchr(str2, str1[non_matching])) non_matching++;
  return non_matching;
}

char *my_strerror(int errnum) {
  static char error[100];
  if (errnum >= 0 && errnum < ERRNUM_MAX)
    my_sprintf(error, "%s", error_list[errnum]);
  else {
    my_sprintf(error, "%s%d", UNKNOWN_ERROR, errnum);
  }
  return error;
}

my_size_t my_strlen(const char *str) {
  my_size_t result = 0;
  while (*str++) result++;
  return result;
}

char *my_strpbrk(const char *str1, const char *str2) {
  char *result = MY_NULL;
  int str1_len = my_strlen(str1), stop = 0;
  for (int i = 0; i < str1_len && !stop; i++) {
    if (my_strchr(str2, str1[i])) {
      result = (char *)str1 + i;
      stop = 1;
    }
  }
  return result;
}

char *my_strrchr(const char *str, int c) {
  char *result = MY_NULL;
  int found = -1, str_len = my_strlen(str);
  for (int i = 0; i < str_len + 1; i++) {
    if (str[i] == c) {
      found = i;
    }
  }
  if (found > -1) result = (char *)str + found;
  return result;
}

char *my_strstr(const char *haystack, const char *needle) {
  char *result = MY_NULL;
  int found = -1, len_haystack = my_strlen(haystack), stop = 0,
      len_needle = my_strlen(needle);
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

char *my_strtok(char *str, const char *delim) {
  static char *original_string = MY_NULL;
  char temp = 0;
  if (!str) str = original_string;
  while (my_strchr(delim, temp) && str) {
    if (!(temp = *str++)) str = MY_NULL;
  }
  if (str) {
    str--;
    original_string = str + my_strcspn(str, delim);
    if (*original_string) *original_string++ = '\0';
  } else
    original_string = MY_NULL;
  return str;
}