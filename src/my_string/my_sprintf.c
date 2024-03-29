#include "my_string.h"

int my_sprintf(char *str, const char *format, ...) {
  int for_return = -1;
  if (format) {
    va_list args;
    va_start(args, format);
    int format_len = my_strlen(format) + 1, j = 0, end_string = 0, ended = 0;
    for (int i = 0; i < format_len; i++) {
      if (format[i] == '%') {
        Format_sprintf input = {0, 0, 0, 0, 0, 0, 0, -1, -1};
        i += read_format_sprintf(args, format + i, &input);
        char *arg = MY_NULL, spec = input.specificator;
        if (spec == 's') {
          arg = take_string(args, &input);
        } else if (spec == 'c') {
          arg = take_char(args, &input, &end_string);
        } else if (spec == 'd' || spec == 'i' || spec == 'u' || spec == 'o' ||
                   spec == 'x' || spec == 'X' || spec == 'p') {
          arg = take_integer(args, &input);
        } else if (spec == 'f' || spec == 'e' || spec == 'E' || spec == 'g' ||
                   spec == 'G') {
          arg = take_float(args, &input);
        } else if (spec == 'n') {
          spec_n(args, &input, j);
        } else
          str[j++] = format[i];
        if (arg) {
          int arg_len = my_strlen(arg);
          if (!ended) my_strncpy(str + j, arg, arg_len + 1);
          if (end_string) {
            if (i < format_len - 2) ended = 1;
            j++;
          }
          j += arg_len;
          free(arg);
        }
      } else {
        if (!ended) str[j] = format[i];
        j++;
      }
    }
    if (str[0] && ended) j--;
    va_end(args);
    for_return += j;
  }
  return for_return;
}

int read_format_sprintf(va_list args, const char *format,
                        Format_sprintf *input) {
  char *specificator = "cdieEfgGosuxXpn%", *nums = "0123456789";
  int dot = 0, i = 1, read_num = 0;
  for (; !my_strchr(specificator, format[i]); i++) {
    if (format[i] == '0' && !dot && !read_num)
      input->zero = 1;
    else if (format[i] == '+' && !dot && !read_num)
      input->plus = 1;
    else if (format[i] == '-' && !dot && !read_num)
      input->dash = 1;
    else if (format[i] == ' ' && !dot && !read_num)
      input->space = 1;
    else if (format[i] == '#' && !dot && !read_num)
      input->hash = 1;
    else if (format[i] == '.') {
      dot = 1;
    } else if ((format[i] == '*' || my_strchr(nums, format[i])) &&
               (input->width == -1 || input->precision == -1)) {
      i += get_width_and_pressision(format + i, dot, input, args);
      read_num = 1;
    } else if (my_strchr("hlL", format[i]) &&
               my_strchr(specificator, format[i + 1])) {
      input->length_description = format[i];
    }
  }
  if (dot && input->precision == -1) input->precision = 0;
  input->specificator = format[i];
  return i;
}

int get_width_and_pressision(const char *format, int dot, Format_sprintf *input,
                             va_list args) {
  int i = 0;
  if (format[i] == '*') {
    int asterisk = va_arg(args, int);
    if (dot) {
      if (asterisk >= 0) input->precision = asterisk;
    } else {
      if (asterisk < 0) input->dash = 1;
      input->width = abs(asterisk);
    }
  } else {
    char number[20], *nums = "0123456789";
    for (; my_strchr(nums, format[i]); i++) number[i] = format[i];
    number[i--] = '\0';
    if (dot)
      input->precision = my_atoi(number, 10);
    else
      input->width = my_atoi(number, 10);
  }
  return i;
}

char *take_string(va_list args, Format_sprintf *input) {
  char *va_string = MY_NULL, *filling = MY_NULL;
  va_string = va_arg(args, char *);
  if (!va_string) va_string = "(null)";
  int cat = my_strlen(va_string);
  if (input->precision > -1 && input->precision < cat) cat = input->precision;
  int fill_in = input->width - cat;
  int size = cat > input->width ? cat : input->width;
  if (va_string) {
    filling = calloc(size + 1, sizeof(char));
    if (filling) {
      char set = input->zero && !input->dash ? '0' : ' ';
      if (fill_in > 0 && !input->dash) my_memset(filling, set, fill_in);
      my_strncat(filling, va_string, cat);
      if (fill_in > 0 && input->dash) my_memset(filling + cat, set, fill_in);
    }
  }
  return filling;
}

char *take_char(va_list args, Format_sprintf *input, int *end_string) {
  int width = input->width, size = width > 0 ? width : 1;
  char va_char = va_arg(args, int), *filling = calloc(size + 1, sizeof(char));
  if (!va_char) *end_string = 1;
  if (filling) {
    char set = input->zero && !input->dash ? '0' : ' ';
    my_memset(filling, va_char, 1);
    if (width > 0 && !input->dash) {
      my_memset(filling, set, width - 1);
      my_memset(filling + (width - 1), va_char, 1);
    } else if (width > 0 && input->dash)
      my_memset(filling + 1, set, width - 1);
  }
  return filling;
}

char *take_integer(va_list args, Format_sprintf *input) {
  char *integer = MY_NULL, *filling = MY_NULL, spec = input->specificator;
  int sign_add = 0, hex_add = 0, negative = 0;
  if (spec == 'd' || spec == 'i')
    integer = my_signed(args, input, &negative);
  else
    integer = my_unsigned(args, input, &negative);
  if ((spec == 'd' || spec == 'i') && (input->space || negative || input->plus))
    sign_add = 1;
  if ((((spec == 'x' || spec == 'X') && input->hash && !negative)) ||
      spec == 'p')
    hex_add = 1;
  if (integer) {
    int length = my_strlen(integer), extra = hex_add ? 2 : sign_add ? 1 : 0;
    int size = input->width >= input->precision && input->width >= length
                   ? input->width
               : input->precision >= input->width && input->precision >= length
                   ? input->precision
                   : length;
    filling = calloc(size + extra + 1, sizeof(char));
    if (filling) {
      handle_int_flags(filling, integer, input, negative, sign_add, hex_add);
      if (spec == 'X') {
        char *temp = my_to_upper(filling);
        if (temp) {
          my_strncpy(filling, temp, my_strlen(temp));
          free(temp);
        }
      }
    }
    free(integer);
  }
  return filling;
}

void handle_int_flags(char *filling, char *integer, Format_sprintf *input,
                      int negative, int sign_add, int hex_add) {
  int precision = input->precision, width = input->width, plus = input->plus,
      zero = input->zero, dash = input->dash, length = my_strlen(integer);
  int extra = hex_add ? 2 : sign_add ? 1 : 0, zeros = precision - length;
  int fill_in = width - (precision > length ? precision : length) - extra;
  char symbol = negative ? '-' : (!negative && plus) ? '+' : ' ';
  char set = zero && precision == -1 && !dash ? '0' : ' ';
  if (sign_add && (dash || set == '0' || fill_in <= 0))
    my_memset(filling, symbol, 1);
  if (hex_add && (dash || set == '0' || fill_in <= 0))
    my_strncat(filling, "0x", 2);
  if (fill_in > 0 && !dash)
    my_memset(filling + my_strlen(filling), set, fill_in);
  if (!dash && fill_in > 0 && set != '0' && sign_add)
    my_memset(filling + my_strlen(filling), symbol, 1);
  if (!dash && fill_in > 0 && set != '0' && hex_add)
    my_strncat(filling, "0x", 2);
  if (zeros > 0) my_memset(filling + my_strlen(filling), '0', zeros);
  my_strncat(filling, integer, my_strlen(integer));
  if (fill_in > 0 && dash)
    my_memset(filling + my_strlen(filling), set, fill_in);
}

char *my_signed(va_list args, Format_sprintf *input, int *negative) {
  char *integer = calloc(25, sizeof(char));
  if (integer) {
    long int va_int = 0;
    if (input->length_description == 'h')
      va_int = (short int)va_arg(args, int);
    else if (input->length_description == 'l' ||
             input->length_description == 'L')
      va_int = va_arg(args, long int);
    else
      va_int = va_arg(args, int);
    if (va_int < 0) *negative = 1;
    if (input->precision || va_int) my_itoa(labs(va_int), integer, 10);
  }
  return integer;
}

char *my_unsigned(va_list args, Format_sprintf *input, int *negative) {
  char spec = input->specificator;
  char *result = calloc(25, sizeof(char));
  if (result) {
    unsigned long int va_unsigned = 0;
    if (input->specificator == 'p') {
      va_unsigned = (unsigned long int)va_arg(args, void *);
    } else if (input->length_description == 'h')
      va_unsigned = (unsigned short int)va_arg(args, unsigned int);
    else if (input->length_description == 'l' ||
             input->length_description == 'L')
      va_unsigned = va_arg(args, unsigned long int);
    else
      va_unsigned = va_arg(args, unsigned int);
    if (!va_unsigned) *negative = 1;
    int base = spec == 'o' ? 8 : spec == 'u' ? 10 : 16;
    if (spec == 'o' && input->hash && va_unsigned) result[0] = '0';
    if (input->precision || va_unsigned)
      my_itoa(va_unsigned, result + my_strlen(result), base);
  }
  return result;
}

char *take_float(va_list args, Format_sprintf *input) {
  if (input->precision == -1) input->precision = 6;
  int space = input->space, plus = input->plus, zero = input->zero,
      dash = input->dash, width = input->width;
  long double va_float = 0;
  if (input->length_description == 'l')
    va_float = va_arg(args, double);
  else if (input->length_description == 'L')
    va_float = va_arg(args, long double);
  else
    va_float = va_arg(args, double);
  int sign_add = (space || va_float < 0 || plus) ? 1 : 0;
  char symbol = va_float < 0 ? '-' : (va_float >= 0 && input->plus) ? '+' : ' ';
  char set = zero && !dash ? '0' : ' ';
  char *decimal = my_decimal(fabsl(va_float), input), *filling = MY_NULL;
  if (decimal) {
    int len_decimal = my_strlen(decimal), extra = sign_add ? 1 : 0,
        fill_in = width - len_decimal - extra;
    int size = (len_decimal > width ? len_decimal : width) + extra;
    filling = calloc(size + 1, sizeof(char));
    if (filling) {
      if (sign_add && (dash || zero || fill_in <= 0))
        my_memset(filling, symbol, 1);
      if (fill_in > 0 && !dash)
        my_memset(filling + my_strlen(filling), set, fill_in);
      if ((!dash && fill_in > 0 && set == ' ') && sign_add)
        my_memset(filling + my_strlen(filling), symbol, 1);
      my_strncat(filling, decimal, (int)my_strlen(decimal));
      if (fill_in > 0 && dash)
        my_memset(filling + my_strlen(filling), set, fill_in);
    }
    free(decimal);
  }
  return filling;
}

char *my_decimal(long double va_decimal, Format_sprintf *input) {
  int precision = input->precision;
  char *result = MY_NULL, spec = input->specificator;
  if (isnan(va_decimal) || fabsl(va_decimal) == INFINITY) {
    result = calloc(5, sizeof(char));
    if (result) my_ftoa(fabsl(va_decimal), result, precision);
  } else {
    if (spec == 'f')
      result = my_double(va_decimal, input);
    else if (spec == 'e' || spec == 'E')
      result = my_notation(va_decimal, input);
    else {
      int e = 0;
      my_frexp(va_decimal, &e);
      if ((precision > e && e >= -4) || !e) {
        input->precision -= (e + 1);
        if (input->precision < 0) input->precision = 0;
        result = my_double(va_decimal, input);
      } else {
        if (precision > 0) input->precision--;
        result = my_notation(va_decimal, input);
      }
    }
  }
  if (spec == 'E' || spec == 'G') {
    char *temp = my_to_upper(result);
    if (temp) {
      my_strncpy(result, temp, my_strlen(temp));
      free(temp);
    }
  }
  return result;
}

char *my_double(long double va_float, Format_sprintf *input) {
  char *result = calloc(310 + input->precision, sizeof(char));
  if (result) {
    my_ftoa(fabsl(va_float), result, input->precision);
    if ((input->specificator == 'g' || input->specificator == 'G') &&
        !input->hash && input->precision > 0)
      handle_trailing_zeros(result +
                            (my_strlen(result) - input->precision - 2));
    if (input->hash && !input->precision) my_strncat(result, ".", 2);
  }
  return result;
}

char *my_notation(long double va_float, Format_sprintf *input) {
  char *result = calloc(310 + input->precision, sizeof(char));
  if (result) {
    int e = 0;
    char exp[10];
    va_float = my_frexp(va_float, &e);
    exp[0] = 'e';
    exp[1] = e < 0 ? '-' : '+';
    if (abs(e) < 10) {
      exp[2] = '0';
      my_itoa(abs(e), exp + 3, 10);
    } else
      my_itoa(abs(e), exp + 2, 10);
    my_ftoa(fabsl(va_float), result, input->precision);
    if ((input->specificator == 'g' || input->specificator == 'G') &&
        !input->hash && input->precision > 0)
      handle_trailing_zeros(result +
                            (my_strlen(result) - input->precision - 2));
    if (input->hash && !input->precision) my_strncat(result, ".", 2);
    my_strncat(result, exp, my_strlen(exp) + 1);
  }
  return result;
}

void spec_n(va_list args, Format_sprintf *input, int index) {
  if (input->length_description == 'l' || input->length_description == 'L')
    *va_arg(args, long int *) = index;
  else if (input->length_description)
    *va_arg(args, short int *) = index;
  else
    *va_arg(args, int *) = index;
}

void handle_trailing_zeros(char *decimal) {
  int len = my_strlen(decimal) - 1;
  while ((decimal[len] == '0' || decimal[len] == '.') && len > 0) len--;
  decimal[len + 1] = '\0';
}