#include <stdio.h>

#include "s21_string.h"

long int s21_atoi(const char *str, int base) {
  long int result = 0;
  int sign = 1, i = 0;
  if (str[0] == '-') {
    sign = -1;
    i++;
  } else if (str[0] == '+')
    i++;
  int str_len = s21_strlen(str);
  for (; i < str_len; i++) {
    long int digit = 0;
    if (str[i] == 'x' || str[i] == 'X')
      continue;
    else if (str[i] >= '0' && str[i] <= '9')
      digit = str[i] - '0';
    else if (str[i] >= 'a' && str[i] <= 'f')
      digit = str[i] - 'a' + 10;
    else if (str[i] >= 'A' && str[i] <= 'F')
      digit = str[i] - 'A' + 10;
    else
      break;
    result = result * base + digit;
  }
  return result * sign;
}

char *s21_itoa(long int num, char *str, int base) {
  if (!num) {
    str = s21_strncpy(str, "0", 2);
  } else if (num >= LONG_MAX) {
    if (base == 8) s21_strncpy(str, "777777777777777777777", 23);
    if (base == 10) s21_strncpy(str, "9223372036854775807", 21);
    if (base == 16) s21_strncpy(str, "7fffffffffffffff", 18);
  } else if (num <= LONG_MIN) {
    if (base == 8) s21_strncpy(str, "1000000000000000000000", 24);
    if (base == 10) s21_strncpy(str, "9223372036854775808", 21);
    if (base == 16) s21_strncpy(str, "8000000000000000", 18);
  } else if ((long unsigned int)num >= ULONG_MAX) {
    if (base == 8) s21_strncpy(str, "1777777777777777777777", 24);
    if (base == 10) s21_strncpy(str, "18446744073709551615", 22);
    if (base == 16) s21_strncpy(str, "ffffffffffffffff", 18);
  } else {
    int negative = 0, i = 0;
    if (num < 0) {
      negative = 1;
      num = -num;
    }
    char *digits = "0123456789abcdef";
    for (; num; i++) {
      long int temp = num % base;
      str[i] = digits[temp];
      num /= base;
    }
    if (negative) str[i++] = '-';
    str[i] = '\0';
    for (int k = 0, j = i - 1; k < j; k++, j--) {
      char temp = str[k];
      str[k] = str[j];
      str[j] = temp;
    }
  }
  return str;
}

long double s21_atof(const char *str) {
  long double result = 0, decimal = 1;
  int sign = 1, i = 0, str_len = s21_strlen(str);
  int exp = 0, exp_sign = 1;
  if (str[0] == '-') {
    sign = -1;
    i++;
  } else if (str[0] == '+')
    i++;
  if (str[i] == 'n' || str[i] == 'N' || str[i] == 'i' || str[i] == 'I') {
    char *lower = s21_to_lower(str + i);
    if (lower) {
      if (!s21_strncmp("nan", lower, 3))
        result = NAN;
      else if (!s21_strncmp("inf", lower, 3))
        result = INFINITY;
      free(lower);
    }
  } else {
    int decimal_found = 0;
    for (; i < str_len; i++) {
      if (str[i] >= '0' && str[i] <= '9') {
        if (decimal_found) {
          decimal *= 0.1;
          result = result + (str[i] - '0') * decimal;
        } else
          result = result * 10 + (str[i] - '0');
      } else if (str[i] == '.' && !decimal_found)
        decimal_found = 1;
      else
        break;
    }
    if (str[i] == 'e' || str[i] == 'E') {
      i++;
      if (str[i] == '-') exp_sign = -1;
      if (str[i]) exp = labs(s21_atoi(str + i, 10));
    }
  }
  return result * sign * pow(10, exp_sign * exp);
}

char *s21_ftoa(long double num, char *str, int afterpoin) {
  if (isnan(num)) {
    str = s21_strncpy(str, "nan", 4);
  } else if (num == INFINITY) {
    str = s21_strncpy(str, "inf", 4);
  } else if (num == -INFINITY) {
    str = s21_strncpy(str, "-inf", 5);
  } else {
    num += (5 * powl(10, -(afterpoin + 1)));
    long double int_part = 0, decimal = modfl(num, &int_part);
    int i = 0, negative = int_part < 0 ? 1 : 0;
    int_part = int_part < 0 ? -int_part : int_part;
    if (!floorl(int_part)) str[i++] = '0';
    for (; floorl(int_part); i++) {
      long double temp = fmodl(int_part, 10.L);
      str[i] = '0' + (int)temp;
      int_part /= 10;
    }
    if (negative) str[i++] = '-';
    str[i] = '\0';
    for (int k = 0, j = i - 1; k < j; k++, j--) {
      char temp = str[k];
      str[k] = str[j];
      str[j] = temp;
    }
    if (afterpoin) {
      str[i++] = '.';
      while (afterpoin--) {
        decimal *= 10;
        int digit = decimal;
        str[i++] = digit + '0';
        decimal -= digit;
      }
    }
    str[i] = '\0';
  }
  return str;
}

long double s21_frexp(long double x, int *e) {
  if (floorl(x) > 9) {
    *e = log10l(fabsl(x));
    x /= powl(10, *e);
    while (floorl(x) > 9) {
      x /= 10;
      (*e)++;
    }
  } else if (x && floorl(x) < 1) {
    *e = log10l(fabsl(x));
    x /= powl(10, *e);
    while (floorl(x) < 1) {
      x *= 10;
      (*e)--;
    }
  }
  return x;
}