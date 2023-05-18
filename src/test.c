#include <stdio.h>
#include <string.h>
#include "s21_string.h"

int main() {
  char test[20] = "hello", temp[20] = "hell";
  char test_2[20] = "hello", temp_2[20] = "hell";
  printf("%d\n%d", strcmp("hell", "hello"), s21_strcmp("hell", "hello"));
//  char *test_chr = strstr(test, temp), *test_chr_s21 = s21_strstr(test, temp);
//  printf("%s\n%s", test_chr, test_chr_s21);
//  strcat(test, temp);
//  s21_strcat(test_2, temp_2);
//  s21_strcpy(temp, test);
//  strcpy(temp_2, test_2);
//  printf("%s\n%s", test, test_2);
//  s21_size_t result = s21_strlen(test);
//  s21_size_t expected = strlen(test);
//  printf("%llu\n%llu\n", result, expected);
}