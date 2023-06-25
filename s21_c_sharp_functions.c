#include "s21_string.h"

void *s21_to_upper(const char *str) {
  char *result = S21_NULL;
  if (str) {
    int str_len = s21_strlen(str);
    result = malloc(str_len + 1);
    if (result) {
      for (int i = 0; i < str_len + 1; i++) {
        result[i] = str[i];
        if (result[i] >= 'a' && result[i] <= 'z') {
          result[i] -= 32;
        }
      }
    }
  }
  return (void *)result;
}

void *s21_to_lower(const char *str) {
  char *result = S21_NULL;
  if (str) {
    int str_len = s21_strlen(str);
    result = malloc(str_len + 1);
    if (result) {
      for (int i = 0; i < str_len + 1; i++) {
        result[i] = str[i];
        if (result[i] >= 'A' && result[i] <= 'Z') {
          result[i] += 32;
        }
      }
    }
  }
  return (void *)result;
}

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  char *result = S21_NULL;
  if (src && str) {
    s21_size_t len_src = s21_strlen(src) + 1, len_str = s21_strlen(str) + 1;
    if (len_src > start_index) {
      result = calloc(len_src + len_str, sizeof(char));
      if (result) {
        s21_strncpy(result, src, start_index);
        s21_strncpy(result + start_index, str, len_str);
        s21_strncpy(result + (start_index + len_str - 1), src + start_index,
                    len_src - start_index);
      }
    }
  }
  return (void *)result;
}

void *s21_trim(const char *src, const char *trim_chars) {
  char *result = S21_NULL;
  if (src) {
    if (!trim_chars) trim_chars = " ";
    int start = 0, len = s21_strlen(src), end = len;
    while (start < len + 1 && s21_strchr(trim_chars, src[start])) start++;
    while (s21_strchr(trim_chars, src[end - 1]) && end > 0) end--;
    result = calloc(end - start + 1, sizeof(char));
    if (result) {
      s21_strncpy(result, src + start, end - start);
      result[end - start] = '\0';
    }
  }
  return (void *)result;
}