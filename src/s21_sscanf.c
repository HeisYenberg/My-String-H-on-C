#include "s21_string.h"

int s21_sscanf(char *str, const char *format, ...) {
  int for_return = -1;
  if (format) {
    va_list args;
    va_start(args, format);
    int format_len = s21_strlen(format), writen = 0;
    for (int i = 0, j = 0; i < format_len + 1; i++) {
      if (format[i] == '%') {
        Format_sscanf input = {0, -1, 0, 0};
        i += read_format_sscanf(format + i, &input);
        char spec = input.specificator;
        j += clean_spaces(str + j, input);
        if (spec == 's') {
          j += write_string(args, str + j, input, &writen);
        } else if (spec == 'c') {
          j += write_char(args, str + j, input, &writen);
        } else if (spec == 'd' || spec == 'i') {
          j += write_signed_int(args, str + j, input, &writen);
        } else if (spec == 'o' || spec == 'u' || spec == 'x' || spec == 'X' ||
                   spec == 'p') {
          j += write_unsigned_int(args, str + j, input, &writen);
        } else if (spec == 'f' || spec == 'e' || spec == 'E' || spec == 'g' ||
                   spec == 'G') {
          j += parse_float(args, str + j, input, &writen);
        } else if (spec == 'n') {
          *va_arg(args, int *) = j;
        } else {
          if (str[j] == '%') j++;
        }
      } else if (s21_strchr(" \n\t\r\f", format[i]) && format[i]) {
        while (s21_strchr(" \n\t\r\f", str[j]) && str[j]) j++;
        continue;
      } else if (format[i] == str[j]) {
        j++;
      } else
        break;
    }
    va_end(args);
    for_return = writen;
  }
  return for_return;
}

int read_format_sscanf(const char *format, Format_sscanf *input) {
  char *specificator = "cdieEfgGosuxXpn%", *nums = "0123456789";
  int i = 1;
  for (; !s21_strchr(specificator, format[i]); i++) {
    if (format[i] == '*') {
      input->asterisk = 1;
    } else if (s21_strchr(nums, format[i])) {
      char number[10];
      int j = 0;
      for (; s21_strchr(nums, format[i]) && j < 10; i++, j++) {
        number[j] = format[i];
      }
      number[j] = '\0';
      i--;
      input->width = s21_atoi(number, 10);
    } else if (s21_strchr("hlL", format[i]) &&
               s21_strchr(specificator, format[i + 1])) {
      input->length_description = format[i];
    }
  }
  if (!input->width) input->width = -1;
  input->specificator = format[i];
  return i;
}

int clean_spaces(char *str, Format_sscanf input) {
  int space = 0;
  if (input.specificator != 'c')
    while (s21_strchr(" \n\t\r\f", str[space]) && str[space]) space++;
  return space;
}

int write_string(va_list args, char *str, Format_sscanf input, int *writen) {
  int read = 0;
  char *buffer = S21_NULL;
  if (!input.asterisk) buffer = va_arg(args, char *);
  while (!s21_strchr(" \n\t\r\f", str[read]) && str[read] &&
         read != input.width)
    read++;
  if (buffer) {
    (*writen)++;
    for (int i = 0; i < read; i++) {
      buffer[i] = str[i];
    }
    buffer[read] = '\0';
  }
  return read;
}

int write_char(va_list args, const char *str, Format_sscanf input,
               int *writen) {
  if (!input.asterisk) {
    *va_arg(args, char *) = str[0];
    (*writen)++;
  }
  return 1;
}

int write_signed_int(va_list args, const char *str, Format_sscanf input,
                     int *writen) {
  int *va_int = S21_NULL, read = 0;
  long int *va_long = S21_NULL;
  short int *va_short = S21_NULL;
  char *number = calloc(s21_strlen(str) + 1, sizeof(char));
  char spec = input.specificator, len_desc = input.length_description;
  if (number) {
    int base = 10;
    if (str[read] == '+' || str[read] == '-') read++;
    if (str[read] == '0' && spec == 'i') {
      base = 8;
      if (str[read + 1] == 'x' || str[read + 1] == 'X') base = 16;
    }
    char *nums = (base == 8)    ? "01234567"
                 : (base == 10) ? "0123456789"
                                : "0123456789abcdefxABCDEFX";
    while (s21_strchr(nums, str[read]) && str[read] && read != input.width)
      read++;
    s21_strncat(number, str, read);
    if (!input.asterisk) {
      if (len_desc == 'h')
        va_short = va_arg(args, short int *);
      else if (len_desc == 'l' || len_desc == 'L')
        va_long = va_arg(args, long int *);
      else
        va_int = va_arg(args, int *);
    }
    if ((va_short || va_int || va_long) && read) {
      if (len_desc == 'h')
        *va_short = s21_atoi(number, base);
      else if (len_desc == 'l' || len_desc == 'L')
        *va_long = s21_atoi(number, base);
      else
        *va_int = s21_atoi(number, base);
      (*writen)++;
    }
    free(number);
  }
  return read;
}

int write_unsigned_int(va_list args, char *str, Format_sscanf input,
                       int *writen) {
  int read = 0;
  unsigned short int *va_unsigned_short = S21_NULL;
  unsigned int *va_unsigned = S21_NULL;
  unsigned long int *va_unsigned_long = S21_NULL;
  char *number = calloc(s21_strlen(str) + 1, sizeof(char));
  if (number) {
    char spec = input.specificator, len_desc = input.length_description;
    char *nums = (spec == 'o')   ? "01234567"
                 : (spec == 'u') ? "0123456789"
                                 : "0123456789abcdefxABCDEFX";
    if (str[read] == '+' || str[read] == '-') read++;
    while (s21_strchr(nums, str[read]) && str[read] && read != input.width)
      read++;
    s21_strncpy(number, str, read);
    number[read] = '\0';
    if (!input.asterisk) {
      if (spec == 'p')
        va_unsigned_long = va_arg(args, void *);
      else if (len_desc == 'h')
        va_unsigned_short = va_arg(args, unsigned short int *);
      else if (len_desc == 'l' || len_desc == 'L')
        va_unsigned_long = va_arg(args, unsigned long int *);
      else
        va_unsigned = va_arg(args, unsigned int *);
    }
    if ((va_unsigned_short || va_unsigned || va_unsigned_long) && read) {
      int base = spec == 'o' ? 8 : spec == 'u' ? 10 : 16;
      if (spec == 'p')
        *va_unsigned_long = s21_atoi(number, base);
      else if (len_desc == 'h')
        *va_unsigned_short = s21_atoi(number, base);
      else if (len_desc == 'l' || len_desc == 'L')
        *va_unsigned_long = s21_atoi(number, base);
      else
        *va_unsigned = s21_atoi(number, base);
      (*writen)++;
    }
    free(number);
  }
  return read;
}

int parse_float(va_list args, char *str, Format_sscanf input, int *writen) {
  int read = 0, str_len = s21_strlen(str);
  char *number = calloc(str_len + 1, sizeof(char));
  if (number) {
    char *nums = "0123456789";
    if (str[read] == '+' || str[read] == '-') read++;
    if (str[read] == 'n' || str[read] == 'N' || str[read] == 'i' ||
        str[read] == 'I') {
      int nan_width = read + 3;
      while (s21_strchr("NAIFnaif", str[read]) && str[read] &&
             read != input.width && read < nan_width)
        read++;
    } else {
      int decimal_found = 0;
      while ((s21_strchr(nums, str[read]) || str[read] == '.') && str[read] &&
             decimal_found < 2 && read != input.width) {
        if (str[read] == '.') decimal_found++;
        read++;
      }
      if (str[read] == 'e' || str[read] == 'E') {
        read++;
        if (str[read] == '+' || str[read] == '-') read++;
        while (s21_strchr(nums, str[read]) && str[read]) read++;
      }
    }
    s21_strncat(number, str, read);
    if (read == 1 && !s21_strchr(nums, number[0])) number[0] = '\0';
    write_float(args, number, input, writen);
    free(number);
  }
  return read;
}

void write_float(va_list args, char *number, Format_sscanf input, int *writen) {
  float *va_float = S21_NULL;
  double *va_double = S21_NULL;
  long double *va_long_double = S21_NULL;
  if (!input.asterisk) {
    if (input.length_description == 'l')
      va_double = va_arg(args, double *);
    else if (input.length_description == 'L')
      va_long_double = va_arg(args, long double *);
    else
      va_float = va_arg(args, float *);
  }
  if ((va_float || va_double || va_long_double) && number[0]) {
    long double result = s21_atof(number);
    if (input.length_description == 'l')
      *va_double = result;
    else if (input.length_description == 'L')
      *va_long_double = result;
    else
      *va_float = result;
    (*writen)++;
  }
}