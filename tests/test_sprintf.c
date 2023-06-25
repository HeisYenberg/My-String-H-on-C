#include "tests.h"

START_TEST(sprintf_c_1) {
  char custom[1000];
  char original[1000];
  char format[100] = "%-21c hello %21corld %021c";
  char a = 'H', b = 'W', c = '!';
  s21_sprintf(custom, format, a, b, c);
  sprintf(original, format, a, b, c);
  ck_assert_str_eq(custom, original);
}
END_TEST

START_TEST(sprintf_c_2) {
  char custom[1000];
  char original[1000];
  char format[100] = "%042c-42%c%042c";
  char a = 'A', b = 'B', c = 'C';
  s21_sprintf(custom, format, a, b, c);
  sprintf(original, format, a, b, c);
  ck_assert_str_eq(custom, original);
}
END_TEST

START_TEST(sprintf_c_3) {
  char custom[1000];
  char original[1000];
  char format[100] = "%cow are %c do%cng %c";
  char a = 'H', b = 'U', c = '!', d = '?';
  s21_sprintf(custom, format, a, b, c, d);
  sprintf(original, format, a, b, c, d);
  ck_assert_str_eq(custom, original);
}
END_TEST

START_TEST(sprintf_c_4) {
  char custom[1000];
  char original[1000];
  char format[100] = "clos% cing%c str%cing%c";
  char a = '\0', b = '\0', c = '\0', d = '\0';
  s21_sprintf(custom, format, a, b, c, d);
  sprintf(original, format, a, b, c, d);
  ck_assert_str_eq(custom, original);
}
END_TEST

START_TEST(sprintf_c_5) {
  char custom[1000];
  char original[1000];
  char format[100] = "%c\f%c\t%c\r%c\n%c\v";
  char a = '0', b = 10, c = 9, d = 127, e = 32;
  s21_sprintf(custom, format, a, b, c, d, e);
  sprintf(original, format, a, b, c, d, e);
  ck_assert_str_eq(custom, original);
}
END_TEST

START_TEST(sprintf_s_1) {
  char custom[1000];
  char original[1000];
  char format[100] = "%-21s hello %21sorld %021s";
  char *a = "hello", *b = "bye", *c = "good night";
  s21_sprintf(custom, format, a, b, c);
  sprintf(original, format, a, b, c);
  ck_assert_str_eq(custom, original);
}
END_TEST

START_TEST(sprintf_s_2) {
  char custom[1000];
  char original[1000];
  char format[100] = "%042s-42%s%042s";
  char *a = "apple", *b = "banana", *c = "closed";
  s21_sprintf(custom, format, a, b, c);
  sprintf(original, format, a, b, c);
  ck_assert_str_eq(custom, original);
}
END_TEST

START_TEST(sprintf_s_3) {
  char custom[1000];
  char original[1000];
  char format[100] = "%sow are %s do%cng %s";
  char *a = "how", *b = "you", *c = "wow", *d = "quest";
  s21_sprintf(custom, format, a, b, c, d);
  sprintf(original, format, a, b, c, d);
  ck_assert_str_eq(custom, original);
}
END_TEST

START_TEST(sprintf_s_4) {
  char custom[1000];
  char original[1000];
  char format[100] = "clos%4sing%1s str%.sing%12.4s";
  char *a = "all you need", *b = "black", *c = "coming", *d = "domestic";
  s21_sprintf(custom, format, a, b, c, d);
  sprintf(original, format, a, b, c, d);
  ck_assert_str_eq(custom, original);
}
END_TEST

START_TEST(sprintf_s_5) {
  char custom[1000];
  char original[1000];
  char format[100] = "%s\f%s\t%s\r%s\n%s\v";
  char *a = "0", *b = "10", *c = "9", *d = "127", *e = "32";
  s21_sprintf(custom, format, a, b, c, d, e);
  sprintf(original, format, a, b, c, d, e);
  ck_assert_str_eq(custom, original);
}
END_TEST

START_TEST(sprintf_short_d_1) {
  char custom[1000];
  char original[1000];
  char format[100] = "%hd\f%hd\t%hd\r%hd\n%hd\v";
  int a = 48, b = 1384278970, c = 9, d = 127, e = 34342;
  s21_sprintf(custom, format, a, b, c, d, e);
  sprintf(original, format, a, b, c, d, e);
  ck_assert_str_eq(custom, original);
}
END_TEST

START_TEST(sprintf_short_d_2) {
  char custom[1000];
  char original[1000];
  char format[100] = "%20hdhel%.10hd w%30.10hdrld%020hd\n%-4hd\v";
  int a = 48, b = 10, c = 0, d = 1, e = 32;
  s21_sprintf(custom, format, a, b, c, d, e);
  sprintf(original, format, a, b, c, d, e);
  ck_assert_str_eq(custom, original);
}
END_TEST

START_TEST(sprintf_regular_d_1) {
  char custom[1000];
  char original[1000];
  char format[100] = "%011dhel%8d w%-034drld%012.5d\n%d\v";
  int a = 48, b = 10, c = 0, d = 1, e = 32;
  s21_sprintf(custom, format, a, b, c, d, e);
  sprintf(original, format, a, b, c, d, e);
  ck_assert_str_eq(custom, original);
}
END_TEST

START_TEST(sprintf_regular_d_2) {
  char custom[1000];
  char original[1000];
  char format[100] = "%011dhel%8d w%-034drld%012.5d\n%d\v";
  long int a = 48, b = 10, c = 3172893718718371973, d = 2794928498234, e = 32;
  s21_sprintf(custom, format, a, b, c, d, e);
  sprintf(original, format, a, b, c, d, e);
  ck_assert_str_eq(custom, original);
}
END_TEST

START_TEST(sprintf_long_d_1) {
  char custom[1000];
  char original[1000];
  char format[100] = "%011ldhel%8ld w%-034ldrld%012.5ld\n%ld\v";
  long int a = 48, b = 10, c = 3172893718718371973, d = 2794928498234, e = 32;
  s21_sprintf(custom, format, a, b, c, d, e);
  sprintf(original, format, a, b, c, d, e);
  ck_assert_str_eq(custom, original);
}
END_TEST

START_TEST(sprintf_long_d_2) {
  char custom[1000];
  char original[1000];
  char format[100] = "%011.*ldhel%8ld w%-0*ldrld";
  long int a = 48, b = 10, c = 3172893718718371973, d = 32, e = 2794928498234;
  s21_sprintf(custom, format, a, b, c, d, e);
  sprintf(original, format, a, b, c, d, e);
  ck_assert_str_eq(custom, original);
}
END_TEST

START_TEST(sprintf_short_i_1) {
  char custom[1000];
  char original[1000];
  char format[100] = "%0*hihel%8hi w%-034hirld%012.5hi\n";
  int a = 48, b = 10, c = 718371973, d = 86234, e = 32;
  s21_sprintf(custom, format, a, b, c, d, e);
  sprintf(original, format, a, b, c, d, e);
  ck_assert_str_eq(custom, original);
}
END_TEST

START_TEST(sprintf_short_i_2) {
  char custom[1000];
  char original[1000];
  char format[100] = "%0*hihel%8hi w%-034.*hirld\n";
  int a = 48, b = 10, c = 973, d = 32, e = 86234;
  s21_sprintf(custom, format, a, b, c, d, e);
  sprintf(original, format, a, b, c, d, e);
  ck_assert_str_eq(custom, original);
}
END_TEST

START_TEST(sprintf_regular_i_1) {
  char custom[1000];
  char original[1000];
  char format[100] = "%0*ihel%8i w%-034.*irld\n";
  int a = 48, b = 10, c = 973, d = 32, e = 86234;
  s21_sprintf(custom, format, a, b, c, d, e);
  sprintf(original, format, a, b, c, d, e);
  ck_assert_str_eq(custom, original);
}
END_TEST

START_TEST(sprintf_regular_i_2) {
  char custom[1000];
  char original[1000];
  char format[100] = "%0*ihel%8i w%-034.*irld\n";
  long int a = 48, b = 32123212210, c = 973, d = 32, e = 948233186234;
  s21_sprintf(custom, format, a, b, c, d, e);
  sprintf(original, format, a, b, c, d, e);
  ck_assert_str_eq(custom, original);
}
END_TEST

START_TEST(sprintf_long_i_1) {
  char custom[1000];
  char original[1000];
  char format[100] = "%0-*lihel%8li w%-+034.*lirld\n";
  long int a = 48, b = 32123212210, c = -973, d = -32, e = 948233186234;
  s21_sprintf(custom, format, a, b, c, d, e);
  sprintf(original, format, a, b, c, d, e);
  ck_assert_str_eq(custom, original);
}
END_TEST

START_TEST(sprintf_long_i_2) {
  char custom[1000];
  char original[1000];
  char format[100] = "%0-+*lihel%8li w%-+034.*lirld\n";
  long int a = 48, b = 32123212210, c = -4782747749224973, d = -32,
           e = 948233186234;
  s21_sprintf(custom, format, a, b, c, d, e);
  sprintf(original, format, a, b, c, d, e);
  ck_assert_str_eq(custom, original);
}
END_TEST

START_TEST(sprintf_short_o_1) {
  char custom[1000];
  char original[1000];
  char format[100] = "%0-*hohel%8ho w%-+034.*horld\n";
  unsigned int a = 48, b = 212210, c = -973, d = -32, e = 186234;
  s21_sprintf(custom, format, a, b, c, d, e);
  sprintf(original, format, a, b, c, d, e);
  ck_assert_str_eq(custom, original);
}
END_TEST

START_TEST(sprintf_short_o_2) {
  char custom[1000];
  char original[1000];
  char format[100] = "%0*hohel%8ho w%-034.*horld\n";
  unsigned int a = 48, b = 10, c = 973, d = 32, e = 86234;
  s21_sprintf(custom, format, a, b, c, d, e);
  sprintf(original, format, a, b, c, d, e);
  ck_assert_str_eq(custom, original);
}
END_TEST

START_TEST(sprintf_regular_o_1) {
  char custom[1000];
  char original[1000];
  char format[100] = "%0*ohel%8o w%-034.*orld\n";
  unsigned int a = 48, b = 10, c = 973, d = 32, e = 86234;
  s21_sprintf(custom, format, a, b, c, d, e);
  sprintf(original, format, a, b, c, d, e);
  ck_assert_str_eq(custom, original);
}
END_TEST

START_TEST(sprintf_regular_o_2) {
  char custom[1000];
  char original[1000];
  char format[100] = "%0*ohel%8o w%-034.*orld\n";
  unsigned long int a = 48, b = 32123212210, c = 973, d = 32, e = 948233186234;
  s21_sprintf(custom, format, a, b, c, d, e);
  sprintf(original, format, a, b, c, d, e);
  ck_assert_str_eq(custom, original);
}
END_TEST

START_TEST(sprintf_long_o_1) {
  char custom[1000];
  char original[1000];
  char format[100] = "%0-*lohel%8lo w%-+034.*lorld\n";
  unsigned long int a = 48, b = LONG_MAX, c = 973, d = -32, e = 948233186234;
  s21_sprintf(custom, format, a, b, c, d, e);
  sprintf(original, format, a, b, c, d, e);
  ck_assert_str_eq(custom, original);
}
END_TEST

START_TEST(sprintf_long_o_2) {
  char custom[1000];
  char original[1000];
  char format[100] = "%0-+*lohel%8lo w%-+034.*lorld\n";
  unsigned long int a = 48, b = LONG_MIN, c = ULONG_MAX, d = -32,
                    e = 948233186234;
  s21_sprintf(custom, format, a, b, c, d, e);
  sprintf(original, format, a, b, c, d, e);
  ck_assert_str_eq(custom, original);
}
END_TEST

START_TEST(sprintf_short_u_1) {
  char custom[1000];
  char original[1000];
  char format[100] = "%0-*huhel%8hu w%-+034.*hurld\n";
  unsigned int a = 48, b = 212210, c = 973, d = -32, e = 186234;
  s21_sprintf(custom, format, a, b, c, d, e);
  sprintf(original, format, a, b, c, d, e);
  ck_assert_str_eq(custom, original);
}
END_TEST

START_TEST(sprintf_short_u_2) {
  char custom[1000];
  char original[1000];
  char format[100] = "%0*huhel%8hu w%-034.*hurld\n";
  unsigned int a = 48, b = 10, c = 973, d = 32, e = 86234;
  s21_sprintf(custom, format, a, b, c, d, e);
  sprintf(original, format, a, b, c, d, e);
  ck_assert_str_eq(custom, original);
}
END_TEST

START_TEST(sprintf_regular_u_1) {
  char custom[1000];
  char original[1000];
  char format[100] = "%0*uhel%8u w%-034.*urld\n";
  unsigned int a = 48, b = 10, c = 973, d = 32, e = 86234;
  s21_sprintf(custom, format, a, b, c, d, e);
  sprintf(original, format, a, b, c, d, e);
  ck_assert_str_eq(custom, original);
}
END_TEST

START_TEST(sprintf_regular_u_2) {
  char custom[1000];
  char original[1000];
  char format[100] = "%0*uhel%8u w%-034.*urld\n";
  unsigned long int a = 48, b = 32123212210, c = 973, d = 32, e = 948233186234;
  s21_sprintf(custom, format, a, b, c, d, e);
  sprintf(original, format, a, b, c, d, e);
  ck_assert_str_eq(custom, original);
}
END_TEST

START_TEST(sprintf_long_u_1) {
  char custom[1000];
  char original[1000];
  char format[100] = "%0-*luhel%8lu w%-+034.*lurld\n";
  unsigned long int a = 48, b = 32123212210, c = 973, d = -32, e = LONG_MAX;
  s21_sprintf(custom, format, a, b, c, d, e);
  sprintf(original, format, a, b, c, d, e);
  ck_assert_str_eq(custom, original);
}
END_TEST

START_TEST(sprintf_long_u_2) {
  char custom[1000];
  char original[1000];
  char format[100] = "%0-+*luhel%8lu w%-+034.*lurld\n";
  unsigned long int a = 48, b = LONG_MIN, c = 4782747749224973, d = -32,
                    e = ULONG_MAX;
  s21_sprintf(custom, format, a, b, c, d, e);
  sprintf(original, format, a, b, c, d, e);
  ck_assert_str_eq(custom, original);
}
END_TEST

START_TEST(sprintf_short_x_1) {
  char custom[1000];
  char original[1000];
  char format[100] = "%#-*hxhel%8hx w%-#034.*hxrld\n";
  unsigned int a = 48, b = 212210, c = 973, d = -32, e = 186234;
  s21_sprintf(custom, format, a, b, c, d, e);
  sprintf(original, format, a, b, c, d, e);
  ck_assert_str_eq(custom, original);
}
END_TEST

START_TEST(sprintf_short_x_2) {
  char custom[1000];
  char original[1000];
  char format[100] = "%0*hxhel%8hx w%#-034.*hxrld\n";
  unsigned int a = 48, b = 10, c = 973, d = 32, e = 86234;
  s21_sprintf(custom, format, a, b, c, d, e);
  sprintf(original, format, a, b, c, d, e);
  ck_assert_str_eq(custom, original);
}
END_TEST

START_TEST(sprintf_regular_x_1) {
  char custom[1000];
  char original[1000];
  char format[100] = "%0*xhel%8x w%#-034.*xrld\n";
  unsigned int a = 48, b = 10, c = 973, d = 32, e = 86234;
  s21_sprintf(custom, format, a, b, c, d, e);
  sprintf(original, format, a, b, c, d, e);
  ck_assert_str_eq(custom, original);
}
END_TEST

START_TEST(sprintf_regular_x_2) {
  char custom[1000];
  char original[1000];
  char format[100] = "%0*xhel%8x w%-034.*xrld\n";
  unsigned long int a = 48, b = 32123212210, c = 973, d = 32, e = 948233186234;
  s21_sprintf(custom, format, a, b, c, d, e);
  sprintf(original, format, a, b, c, d, e);
  ck_assert_str_eq(custom, original);
}
END_TEST

START_TEST(sprintf_long_x_1) {
  char custom[1000];
  char original[1000];
  char format[100] = "%0-*lxhel%8lx w%-+034.*lxrld\n";
  unsigned long int a = 48, b = LONG_MIN, c = 973, d = 32, e = LONG_MAX;
  s21_sprintf(custom, format, a, b, c, d, e);
  sprintf(original, format, a, b, c, d, e);
  ck_assert_str_eq(custom, original);
}
END_TEST

START_TEST(sprintf_long_x_2) {
  char custom[1000];
  char original[1000];
  char format[100] = "%0-+*lxhel%#8lx w%-+034.*lxrld\n";
  unsigned long int a = 48, b = 32123212210, c = 4782747749224973, d = -32,
                    e = 948233186234;
  s21_sprintf(custom, format, a, b, c, d, e);
  sprintf(original, format, a, b, c, d, e);
  ck_assert_str_eq(custom, original);
}
END_TEST

START_TEST(sprintf_short_X_1) {
  char custom[1000];
  char original[1000];
  char format[100] = "%0-*hXhel%#8hX w%-+034.*hXrld\n";
  unsigned int a = 48, b = 212210, c = 973, d = 32, e = 186234;
  s21_sprintf(custom, format, a, b, c, d, e);
  sprintf(original, format, a, b, c, d, e);
  ck_assert_str_eq(custom, original);
}
END_TEST

START_TEST(sprintf_short_X_2) {
  char custom[1000];
  char original[1000];
  char format[100] = "%0*hXhel%8hX w%-034.*hXrld\n";
  unsigned int a = 48, b = 10, c = 973, d = 32, e = 86234;
  s21_sprintf(custom, format, a, b, c, d, e);
  sprintf(original, format, a, b, c, d, e);
  ck_assert_str_eq(custom, original);
}
END_TEST

START_TEST(sprintf_regular_X_1) {
  char custom[1000];
  char original[1000];
  char format[100] = "%0#*Xhel%8X w%-034.*Xrld\n";
  unsigned int a = 48, b = 10, c = 973, d = 32, e = 86234;
  s21_sprintf(custom, format, a, b, c, d, e);
  sprintf(original, format, a, b, c, d, e);
  ck_assert_str_eq(custom, original);
}
END_TEST

START_TEST(sprintf_regular_X_2) {
  char custom[1000];
  char original[1000];
  char format[100] = "%0#*Xhel%8X w%-034.*Xrld\n";
  unsigned long int a = 48, b = 32123212210, c = 973, d = 32, e = 948233186234;
  s21_sprintf(custom, format, a, b, c, d, e);
  sprintf(original, format, a, b, c, d, e);
  ck_assert_str_eq(custom, original);
}
END_TEST

START_TEST(sprintf_long_X_1) {
  char custom[1000];
  char original[1000];
  char format[100] = "%0-*lXhel%8lX w%-+034.*lXrld\n";
  unsigned long int a = 48, b = 32123212210, c = 973, d = 21, e = 948233186234;
  s21_sprintf(custom, format, a, b, c, d, e);
  sprintf(original, format, a, b, c, d, e);
  ck_assert_str_eq(custom, original);
}
END_TEST

START_TEST(sprintf_long_X_2) {
  char custom[1000];
  char original[1000];
  char format[100] = "%#0-+*lXhel%8lX w%-+034.*lXrld\n";
  unsigned long int a = 48, b = 32123212210, c = 4782747749224973, d = 21,
                    e = ULONG_MAX;
  s21_sprintf(custom, format, a, b, c, d, e);
  sprintf(original, format, a, b, c, d, e);
  ck_assert_str_eq(custom, original);
}
END_TEST

START_TEST(sprintf_float_f_1) {
  char custom[1000];
  char original[1000];
  char format[100] = "%0-*fhel%8f w%-+034.*frld\n";
  int a = 48, d = 7;
  double b = 212210.124, c = -973.6723, e = 18623431321.31213;
  s21_sprintf(custom, format, a, b, c, d, e);
  sprintf(original, format, a, b, c, d, e);
  ck_assert_str_eq(custom, original);
}
END_TEST

START_TEST(sprintf_float_f_2) {
  char custom[1000];
  char original[1000];
  char format[100] = "%#0-*fhel%8f w%-+034.*frld\n";
  int a = 48, d = 12;
  double b = 212210.0, c = 21.6723, e = 31321.3121;
  s21_sprintf(custom, format, a, b, c, d, e);
  sprintf(original, format, a, b, c, d, e);
  ck_assert_str_eq(custom, original);
}
END_TEST

START_TEST(sprintf_double_f_1) {
  char custom[1000];
  char original[1000];
  char format[100] = "%0-*lfhel%8lf w%-+034.*lfrld\n";
  int a = 48, d = 9;
  double b = NAN, c = -973.6723, e = 18623431321.31213;
  s21_sprintf(custom, format, a, b, c, d, e);
  sprintf(original, format, a, b, c, d, e);
  ck_assert_str_eq(custom, original);
}
END_TEST

START_TEST(sprintf_double_f_2) {
  char custom[1000];
  char original[1000];
  char format[100] = "%0-*lfhel%#8lf w%#-+034.*lfrld\n";
  int a = 48, d = 12;
  double b = NAN, c = -INFINITY, e = 18623431321.31213;
  s21_sprintf(custom, format, a, b, c, d, e);
  sprintf(original, format, a, b, c, d, e);
  ck_assert_str_eq(custom, original);
}
END_TEST

START_TEST(sprintf_long_f_1) {
  char custom[1000];
  char original[1000];
  char format[100] = "%0-*Lfhel%8Lf w%#-+034.*Lfrld\n";
  int a = 48, d = 2;
  long double b = 3e-4, c = -INFINITY, e = 18623431321.31213;
  s21_sprintf(custom, format, a, b, c, d, e);
  sprintf(original, format, a, b, c, d, e);
  ck_assert_str_eq(custom, original);
}
END_TEST

START_TEST(sprintf_long_f_2) {
  char custom[1000];
  char original[1000];
  char format[100] = "%0-*Lfhel%8Lf w%#-+034.*Lfrld\n";
  int a = 21, d = 12;
  long double b = 3e-4, c = -INFINITY, e = INFINITY;
  s21_sprintf(custom, format, a, b, c, d, e);
  sprintf(original, format, a, b, c, d, e);
  ck_assert_str_eq(custom, original);
}
END_TEST

START_TEST(sprintf_float_e_1) {
  char custom[1000];
  char original[1000];
  char format[100] = "%0-*ehel%8e w%#-+034.*erld\n";
  int a = 48, d = 0;
  double b = 212210.124, c = -973.6723, e = 18623431321.0;
  s21_sprintf(custom, format, a, b, c, d, e);
  sprintf(original, format, a, b, c, d, e);
  ck_assert_str_eq(custom, original);
}
END_TEST

START_TEST(sprintf_float_e_2) {
  char custom[1000];
  char original[1000];
  char format[100] = "%0-*ehel%8e w%-+034.*erld\n";
  int a = 48, d = 12;
  double b = 212210.124, c = 21.6723, e = 31321.3121;
  s21_sprintf(custom, format, a, b, c, d, e);
  sprintf(original, format, a, b, c, d, e);
  ck_assert_str_eq(custom, original);
}
END_TEST

START_TEST(sprintf_double_e_1) {
  char custom[1000];
  char original[1000];
  char format[100] = "%0-*lehel%8le w%-+034.*lerld\n";
  int a = 48, d = 5;
  double b = NAN, c = -973.6723, e = 18623431321.31213;
  s21_sprintf(custom, format, a, b, c, d, e);
  sprintf(original, format, a, b, c, d, e);
  ck_assert_str_eq(custom, original);
}
END_TEST

START_TEST(sprintf_double_e_2) {
  char custom[1000];
  char original[1000];
  char format[100] = "%0-*lehel%#8le w%-+034.*lerld\n";
  int a = 48, d = 10;
  double b = NAN, c = -INFINITY, e = 18623431321.31213;
  s21_sprintf(custom, format, a, b, c, d, e);
  sprintf(original, format, a, b, c, d, e);
  ck_assert_str_eq(custom, original);
}
END_TEST

START_TEST(sprintf_long_e_1) {
  char custom[1000];
  char original[1000];
  char format[100] = "%0-*Lehel%8Le w%-+034.*Lerld\n";
  int a = 48, d = 14;
  long double b = 3e-4, c = -INFINITY, e = 18623431321.31213;
  s21_sprintf(custom, format, a, b, c, d, e);
  sprintf(original, format, a, b, c, d, e);
  ck_assert_str_eq(custom, original);
}
END_TEST

START_TEST(sprintf_long_e_2) {
  char custom[1000];
  char original[1000];
  char format[100] = "%0-*Lehel%8Le w%-+034.*Lerld\n";
  int a = 21, d = 12;
  long double b = 3e-4, c = -INFINITY, e = INFINITY;
  s21_sprintf(custom, format, a, b, c, d, e);
  sprintf(original, format, a, b, c, d, e);
  ck_assert_str_eq(custom, original);
}
END_TEST

START_TEST(sprintf_float_E_1) {
  char custom[1000];
  char original[1000];
  char format[100] = "%0-*Ehel%8E w%-+034.*Erld\n";
  int a = 48, d = 9;
  double b = 212210.124, c = -973.6723, e = 18623431321.31213;
  s21_sprintf(custom, format, a, b, c, d, e);
  sprintf(original, format, a, b, c, d, e);
  ck_assert_str_eq(custom, original);
}
END_TEST

START_TEST(sprintf_float_E_2) {
  char custom[1000];
  char original[1000];
  char format[100] = "%0-*Ehel%8E w%-+034.*Erld\n";
  int a = 48, d = 12;
  double b = 212210.124, c = 21.6723, e = 31321.3121;
  s21_sprintf(custom, format, a, b, c, d, e);
  sprintf(original, format, a, b, c, d, e);
  ck_assert_str_eq(custom, original);
}
END_TEST

START_TEST(sprintf_double_E_1) {
  char custom[1000];
  char original[1000];
  char format[100] = "%0-*lEhel%8lE w%-+034.*lErld\n";
  int a = 48, d = 11;
  double b = NAN, c = -973.6723, e = 18623431321.31213;
  s21_sprintf(custom, format, a, b, c, d, e);
  sprintf(original, format, a, b, c, d, e);
  ck_assert_str_eq(custom, original);
}
END_TEST

START_TEST(sprintf_double_E_2) {
  char custom[1000];
  char original[1000];
  char format[100] = "%0-*lEhel%8lE w%-+034.*lErld\n";
  int a = 48, d = 9;
  double b = NAN, c = -INFINITY, e = 18623431321.31213;
  s21_sprintf(custom, format, a, b, c, d, e);
  sprintf(original, format, a, b, c, d, e);
  ck_assert_str_eq(custom, original);
}
END_TEST

START_TEST(sprintf_long_E_1) {
  char custom[1000];
  char original[1000];
  char format[100] = "%0-*LEhel%8LE w%-+034.*LErld\n";
  int a = 48, d = 6;
  long double b = 3e-4, c = -INFINITY, e = 18623431321.31213;
  s21_sprintf(custom, format, a, b, c, d, e);
  sprintf(original, format, a, b, c, d, e);
  ck_assert_str_eq(custom, original);
}
END_TEST

START_TEST(sprintf_long_E_2) {
  char custom[1000];
  char original[1000];
  char format[100] = "%0-*LEhel%8LE w%-+034.*LErld\n";
  int a = 21, d = 12;
  long double b = 3e-4, c = -INFINITY, e = INFINITY;
  s21_sprintf(custom, format, a, b, c, d, e);
  sprintf(original, format, a, b, c, d, e);
  ck_assert_str_eq(custom, original);
}
END_TEST

START_TEST(sprintf_float_g_1) {
  char custom[1000];
  char original[1000];
  char format[100] = "%0-*ghel%8g w%-+034.*grld\n";
  int a = 48, d = 10;
  double b = 212210.124, c = -973.6723, e = 18623431321.31213;
  s21_sprintf(custom, format, a, b, c, d, e);
  sprintf(original, format, a, b, c, d, e);
  ck_assert_str_eq(custom, original);
}
END_TEST

START_TEST(sprintf_float_g_2) {
  char custom[1000];
  char original[1000];
  char format[100] = "%0-*ghel%8g w%-+034.*grld\n";
  int a = 48, d = 12;
  double b = 212210.124, c = 21.6723, e = 31321.3121;
  s21_sprintf(custom, format, a, b, c, d, e);
  sprintf(original, format, a, b, c, d, e);
  ck_assert_str_eq(custom, original);
}
END_TEST

START_TEST(sprintf_double_g_1) {
  char custom[1000];
  char original[1000];
  char format[100] = "%0-*lghel%8lg w%-+034.*lgrld\n";
  int a = 48, d = 13;
  double b = NAN, c = -973.6723, e = 18623431321.31213;
  s21_sprintf(custom, format, a, b, c, d, e);
  sprintf(original, format, a, b, c, d, e);
  ck_assert_str_eq(custom, original);
}
END_TEST

START_TEST(sprintf_double_g_2) {
  char custom[1000];
  char original[1000];
  char format[100] = "%#0-*lghel%8lg w%-+034.*lgrld\n";
  int a = 48, d = 4;
  double b = NAN, c = -INFINITY, e = 18623431321.31213;
  s21_sprintf(custom, format, a, b, c, d, e);
  sprintf(original, format, a, b, c, d, e);
  ck_assert_str_eq(custom, original);
}
END_TEST

START_TEST(sprintf_long_g_1) {
  char custom[1000];
  char original[1000];
  char format[100] = "%0-*Lghel%8Lg w%-+034.*Lgrld\n";
  int a = 48, d = 12;
  long double b = 3e-4, c = -INFINITY, e = 18623431321.31213;
  s21_sprintf(custom, format, a, b, c, d, e);
  sprintf(original, format, a, b, c, d, e);
  ck_assert_str_eq(custom, original);
}
END_TEST

START_TEST(sprintf_long_g_2) {
  char custom[1000];
  char original[1000];
  char format[100] = "%#0-*Lghel%8Lg w%-+034.*Lgrld\n";
  int a = 21, d = 12;
  long double b = 3e-4, c = -INFINITY, e = INFINITY;
  s21_sprintf(custom, format, a, b, c, d, e);
  sprintf(original, format, a, b, c, d, e);
  ck_assert_str_eq(custom, original);
}
END_TEST

START_TEST(sprintf_float_G_1) {
  char custom[1000];
  char original[1000];
  char format[100] = "%0-*Ghel%8G w%-+034.*Grld\n";
  int a = 48, d = 9;
  double b = 212210.124, c = -973.6723, e = 18623431321.31213;
  s21_sprintf(custom, format, a, b, c, d, e);
  sprintf(original, format, a, b, c, d, e);
  ck_assert_str_eq(custom, original);
}
END_TEST

START_TEST(sprintf_float_G_2) {
  char custom[1000];
  char original[1000];
  char format[100] = "%0-*Ghel%8G w%-+034.*Grld\n";
  int a = 48, d = 12;
  double b = 212210.124, c = 21.6723, e = 31321.3121;
  s21_sprintf(custom, format, a, b, c, d, e);
  sprintf(original, format, a, b, c, d, e);
  ck_assert_str_eq(custom, original);
}
END_TEST

START_TEST(sprintf_double_G_1) {
  char custom[1000];
  char original[1000];
  char format[100] = "%#0-*lGhel%8lG w%-+034.*lGrld\n";
  int a = 48, d = 12;
  double b = NAN, c = -973.6723, e = 18623431321.31213;
  s21_sprintf(custom, format, a, b, c, d, e);
  sprintf(original, format, a, b, c, d, e);
  ck_assert_str_eq(custom, original);
}
END_TEST

START_TEST(sprintf_double_G_2) {
  char custom[1000];
  char original[1000];
  char format[100] = "%0-*lGhel%8lG w%-+034.*lGrld\n";
  int a = 48, d = 6;
  double b = NAN, c = -INFINITY, e = 18623431321.31213;
  s21_sprintf(custom, format, a, b, c, d, e);
  sprintf(original, format, a, b, c, d, e);
  ck_assert_str_eq(custom, original);
}
END_TEST

START_TEST(sprintf_long_G_1) {
  char custom[1000];
  char original[1000];
  char format[100] = "%#0-*LGhel%8LG w%-+034.*LGrld\n";
  int a = 48, d = 5;
  long double b = 3e-4, c = -INFINITY, e = 18623431321.31213;
  s21_sprintf(custom, format, a, b, c, d, e);
  sprintf(original, format, a, b, c, d, e);
  ck_assert_str_eq(custom, original);
}
END_TEST

START_TEST(sprintf_long_G_2) {
  char custom[1000];
  char original[1000];
  char format[100] = "%#0-*LGhel%8LG w%-+034.*LGrld\n";
  int a = 21, d = 12;
  long double b = 3e-4, c = -INFINITY, e = INFINITY;
  s21_sprintf(custom, format, a, b, c, d, e);
  sprintf(original, format, a, b, c, d, e);
  ck_assert_str_eq(custom, original);
}
END_TEST

START_TEST(sprintf_p_1) {
  char custom[1000];
  char original[1000];
  char format[100] = "%#0-*phel%8p w%-+034.*prld\n";
  int a = 0;
  double b = 12.21;
  char c = 'D';
  char *d = "test";
  size_t e = 21;
  s21_sprintf(custom, format, a, b, c, d, e);
  sprintf(original, format, a, b, c, d, e);
  ck_assert_str_eq(custom, original);
}

START_TEST(sprintf_p_2) {
  char custom[1000];
  char original[1000];
  char format[100] = "%#0-*phel%21p w%-+042.prld%#p\n";
  int a = 10;
  double b = 42.24;
  char c = 'C';
  char *d = "testing_yes";
  size_t e = 42;
  s21_sprintf(custom, format, a, b, c, d, e);
  sprintf(original, format, a, b, c, d, e);
  ck_assert_str_eq(custom, original);
}

START_TEST(sprintf_n_1) {
  char custom[1000];
  char original[1000];
  const char *format = "%hnhel%hn world%hn\n";
  short int a = 0, b = 0, c = 0;
  short int a1 = 0, b1 = 0, c1 = 0;
  s21_sprintf(custom, format, &a, &b, &c);
  sprintf(original, format, &a1, &b1, &c1);
  ck_assert_str_eq(custom, original);
  ck_assert_int_eq(a, a1);
  ck_assert_int_eq(b, b1);
  ck_assert_int_eq(c, c1);
}

START_TEST(sprintf_n_2) {
  char custom[1000];
  char original[1000];
  const char *format = "%nhel%n w%nrld\n";
  int a = 0, b = 0, c = 0;
  int a1 = 0, b1 = 0, c1 = 0;
  s21_sprintf(custom, format, &a, &b, &c);
  sprintf(original, format, &a1, &b1, &c1);
  ck_assert_str_eq(custom, original);
  ck_assert_int_eq(a, a1);
  ck_assert_int_eq(b, b1);
  ck_assert_int_eq(c, c1);
}

START_TEST(sprintf_n_3) {
  char custom[1000];
  char original[1000];
  const char *format = "%lnel%ln w%lnrld\n";
  long int a = 0, b = 0, c = 0;
  long int a1 = 0, b1 = 0, c1 = 0;
  s21_sprintf(custom, format, &a, &b, &c);
  sprintf(original, format, &a1, &b1, &c1);
  ck_assert_str_eq(custom, original);
  ck_assert_int_eq(a, a1);
  ck_assert_int_eq(b, b1);
  ck_assert_int_eq(c, c1);
}

START_TEST(sprintf_percent) {
  char custom[1000];
  char original[1000];
  const char *format = "%%nel%%n w%%nrld%%%d\n";
  int a = 0, b = 0;
  s21_sprintf(custom, format, a);
  sprintf(original, format, b);
  ck_assert_str_eq(custom, original);
}

Suite *test_sprintf() {
  Suite *s = suite_create("\033[42m-=S21_SPRINTF=-\033[0m");
  TCase *tc = tcase_create("S21_SPRINTF");
  tcase_add_test(tc, sprintf_c_1);
  tcase_add_test(tc, sprintf_c_2);
  tcase_add_test(tc, sprintf_c_3);
  tcase_add_test(tc, sprintf_c_4);
  tcase_add_test(tc, sprintf_c_5);
  tcase_add_test(tc, sprintf_s_1);
  tcase_add_test(tc, sprintf_s_2);
  tcase_add_test(tc, sprintf_s_3);
  tcase_add_test(tc, sprintf_s_4);
  tcase_add_test(tc, sprintf_s_5);
  tcase_add_test(tc, sprintf_short_d_1);
  tcase_add_test(tc, sprintf_short_d_2);
  tcase_add_test(tc, sprintf_regular_d_1);
  tcase_add_test(tc, sprintf_regular_d_2);
  tcase_add_test(tc, sprintf_long_d_1);
  tcase_add_test(tc, sprintf_long_d_2);
  tcase_add_test(tc, sprintf_short_i_1);
  tcase_add_test(tc, sprintf_short_i_2);
  tcase_add_test(tc, sprintf_regular_i_1);
  tcase_add_test(tc, sprintf_regular_i_2);
  tcase_add_test(tc, sprintf_long_i_1);
  tcase_add_test(tc, sprintf_long_i_2);
  tcase_add_test(tc, sprintf_short_o_1);
  tcase_add_test(tc, sprintf_short_o_2);
  tcase_add_test(tc, sprintf_regular_o_1);
  tcase_add_test(tc, sprintf_regular_o_2);
  tcase_add_test(tc, sprintf_long_o_1);
  tcase_add_test(tc, sprintf_long_o_2);
  tcase_add_test(tc, sprintf_short_u_1);
  tcase_add_test(tc, sprintf_short_u_2);
  tcase_add_test(tc, sprintf_regular_u_1);
  tcase_add_test(tc, sprintf_regular_u_2);
  tcase_add_test(tc, sprintf_long_u_1);
  tcase_add_test(tc, sprintf_long_u_2);
  tcase_add_test(tc, sprintf_short_x_1);
  tcase_add_test(tc, sprintf_short_x_2);
  tcase_add_test(tc, sprintf_regular_x_1);
  tcase_add_test(tc, sprintf_regular_x_2);
  tcase_add_test(tc, sprintf_long_x_1);
  tcase_add_test(tc, sprintf_long_x_2);
  tcase_add_test(tc, sprintf_short_X_1);
  tcase_add_test(tc, sprintf_short_X_2);
  tcase_add_test(tc, sprintf_regular_X_1);
  tcase_add_test(tc, sprintf_regular_X_2);
  tcase_add_test(tc, sprintf_long_X_1);
  tcase_add_test(tc, sprintf_long_X_2);
  tcase_add_test(tc, sprintf_float_f_1);
  tcase_add_test(tc, sprintf_float_f_2);
  tcase_add_test(tc, sprintf_double_f_1);
  tcase_add_test(tc, sprintf_double_f_2);
  tcase_add_test(tc, sprintf_long_f_1);
  tcase_add_test(tc, sprintf_long_f_2);
  tcase_add_test(tc, sprintf_float_e_1);
  tcase_add_test(tc, sprintf_float_e_2);
  tcase_add_test(tc, sprintf_double_e_1);
  tcase_add_test(tc, sprintf_double_e_2);
  tcase_add_test(tc, sprintf_long_e_1);
  tcase_add_test(tc, sprintf_long_e_2);
  tcase_add_test(tc, sprintf_float_E_1);
  tcase_add_test(tc, sprintf_float_E_2);
  tcase_add_test(tc, sprintf_double_E_1);
  tcase_add_test(tc, sprintf_double_E_2);
  tcase_add_test(tc, sprintf_long_E_1);
  tcase_add_test(tc, sprintf_long_E_2);
  tcase_add_test(tc, sprintf_float_g_1);
  tcase_add_test(tc, sprintf_float_g_2);
  tcase_add_test(tc, sprintf_double_g_1);
  tcase_add_test(tc, sprintf_double_g_2);
  tcase_add_test(tc, sprintf_long_g_1);
  tcase_add_test(tc, sprintf_long_g_2);
  tcase_add_test(tc, sprintf_float_G_1);
  tcase_add_test(tc, sprintf_float_G_2);
  tcase_add_test(tc, sprintf_double_G_1);
  tcase_add_test(tc, sprintf_double_G_2);
  tcase_add_test(tc, sprintf_long_G_1);
  tcase_add_test(tc, sprintf_long_G_2);
  tcase_add_test(tc, sprintf_p_1);
  tcase_add_test(tc, sprintf_p_2);
  tcase_add_test(tc, sprintf_n_1);
  tcase_add_test(tc, sprintf_n_2);
  tcase_add_test(tc, sprintf_n_3);
  tcase_add_test(tc, sprintf_percent);

  suite_add_tcase(s, tc);
  return s;
}
