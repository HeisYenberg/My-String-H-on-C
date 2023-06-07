#include "tests.h"

START_TEST(sscanf_spec_c_1) {
  char format[] = "%c";
  char str[] = "\t1";
  char c1, c2;

  int16_t res1 = s21_sscanf(str, format, &c1);
  int16_t res2 = sscanf(str, format, &c2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(c1, c2);
}
END_TEST

START_TEST(sscanf_spec_c_2) {
  char format[] = "%c";
  char str[] = "wed\ta";
  char c1, c2;
  int16_t res1 = s21_sscanf(str, format, &c1);
  int16_t res2 = sscanf(str, format, &c2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(c1, c2);
}
END_TEST

START_TEST(sscanf_spec_c_3) {
  char format[] = "%c%c%c";
  char str[] = "1 \n fr \t";
  char c11, c12, c13, c21, c22, c23;

  int16_t res1 = s21_sscanf(str, format, &c11, &c12, &c13);
  int16_t res2 = sscanf(str, format, &c21, &c22, &c23);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(c11, c21);
  ck_assert_int_eq(c12, c22);
  ck_assert_int_eq(c13, c23);
}
END_TEST

START_TEST(sscanf_spec_c_4) {
  char format[] = "%c %c \t%c";
  char str[] = "\t\n\n  3    5 6 \n  \t";
  char c11, c12, c13, c21, c22, c23;

  int16_t res1 = s21_sscanf(str, format, &c11, &c12, &c13);
  int16_t res2 = sscanf(str, format, &c21, &c22, &c23);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(c11, c21);
  ck_assert_int_eq(c12, c22);
  ck_assert_int_eq(c13, c23);
}
END_TEST

START_TEST(sscanf_spec_c_5) {
  char format[] = "%c %c \n%c";
  char str[] = "\t\n\n  324 \n  \t";
  char c11, c12, c13, c21, c22, c23;

  int16_t res1 = s21_sscanf(str, format, &c11, &c12, &c13);
  int16_t res2 = sscanf(str, format, &c21, &c22, &c23);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(c11, c21);
  ck_assert_int_eq(c12, c22);
  ck_assert_int_eq(c13, c23);
}
END_TEST

// %s

START_TEST(sscanf_spec_s_1) {
  char format[] = "%s";
  char str[] = "\t1jnj";
  char c1[100], c2[100];

  int16_t res1 = s21_sscanf(str, format, &c1);
  int16_t res2 = sscanf(str, format, &c2);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(c1, c2);
}
END_TEST

START_TEST(sscanf_spec_s_2) {
  char format[] = "%s";
  char str[] = "wed\ta";
  char c1[100], c2[100];
  int16_t res1 = s21_sscanf(str, format, &c1);
  int16_t res2 = sscanf(str, format, &c2);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(c1, c2);
}
END_TEST

START_TEST(sscanf_spec_s_3) {
  char format[] = "%s%s%s";
  char str[] = "wefwe ewfer ere";
  char c11[100], c12[100], c13[100], c21[100], c22[100], c23[100];

  int16_t res1 = s21_sscanf(str, format, &c11, &c12, &c13);
  int16_t res2 = sscanf(str, format, &c21, &c22, &c23);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(c11, c21);
  ck_assert_str_eq(c12, c22);
  ck_assert_str_eq(c13, c23);
}
END_TEST

START_TEST(sscanf_spec_s_4) {
  char format[] = "%1s %4s %s";
  char str[] = "sbfgbfgb  1dfgvdfsg    2 3 \n  \t";
  char c11[100], c12[100], c13[100], c21[100], c22[100], c23[100];

  int16_t res1 = s21_sscanf(str, format, &c11, &c12, &c13);
  int16_t res2 = sscanf(str, format, &c21, &c22, &c23);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(c11, c21);
  ck_assert_str_eq(c12, c22);
  ck_assert_str_eq(c13, c23);
}
END_TEST

START_TEST(sscanf_spec_s_5) {
  char format[] = "%s %% %s \n%*s";
  char str[] = "wefewf % 453 \nwef";
  char c11[100], c12[100], c21[100], c22[100];

  int16_t res1 = s21_sscanf(str, format, &c11, &c12);
  int16_t res2 = sscanf(str, format, &c21, &c22);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(c11, c21);
}
END_TEST

// %d

START_TEST(sscanf_spec_hd_1) {
  char format[] = "%hd";
  char str[] = "101";
  short d1, d2;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hd_2) {
  char format[] = "%4hd";
  char str[] = "-104";
  short d1, d2;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hd_3) {
  char format[] = "%*hd";
  char str[] = "115";
  short d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_d_4) {
  char format[] = "%d";
  char str[] = "1147483647";
  int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_ld_5) {
  char format[] = "%4ld";
  char str[] = "-104";
  long int d1, d2;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

// %i

START_TEST(sscanf_spec_hi_dec_1) {
  char format[] = "%hi%hi%hi";
  char str[] = "108 +148 -34";
  unsigned short d1, d2;
  unsigned short q1, q2;
  unsigned short z1, z2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_hi_dec_6) {
  char format[] = "%30hi %24hi %21hi";
  char str[] = "13 +137 -8";
  unsigned short d1, d2;
  unsigned short q1, q2;
  unsigned short z1, z2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_i_dec_1) {
  char format[] = "%i%i%i";
  char str[] = "116 +198 -87";
  unsigned int d1, d2;
  unsigned int q1, q2;
  unsigned int z1, z2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_i_oct_7) {
  char format[] = "%i %i %i %i";
  char str[] = "037777777777 +040000000000 -040000000000 -040000000001";
  unsigned int d1, d2;
  unsigned int q1, q2;
  unsigned int z1, z2;
  unsigned int w1, w2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_uint_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_spec_i_hex_1) {
  char format[] = "%i%i%i";
  char str[] = "0x113 +0X198 0xc0ffe";
  unsigned int d1, d2;
  unsigned int q1, q2;
  unsigned int z1, z2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

// %n

START_TEST(sscanf_spec_n_1) {
  char format[] = "%n";
  char str[] = "Afvd";
  int n1 = 0, n2 = 0;

  int16_t res1 = s21_sscanf(str, format, &n1);
  int16_t res2 = sscanf(str, format, &n2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(sscanf_spec_n_2) {
  char format[] = "%d %n";
  char str[] = "65 fgfgnh";
  int d1 = 0, d2 = 0;
  int n1 = 0, n2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &n1);
  int16_t res2 = sscanf(str, format, &d2, &n2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(sscanf_spec_n_3) {
  char format[] = "%d %d %n %d %d %d";
  char str[] = "45 23 7 545 123";
  int d1 = 0, d2 = 0;
  int dd1 = 0, dd2 = 0;
  int f1 = 0, f2 = 0;
  int ff1 = 0, ff2 = 0;
  int k1 = 0, k2 = 0;
  int n1 = 0, n2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &dd1, &n1, &f1, &ff1, &k1);
  int16_t res2 = sscanf(str, format, &d2, &dd2, &n2, &f2, &ff2, &k2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(dd1, dd2);
  ck_assert_int_eq(f1, f2);
  ck_assert_int_eq(ff1, ff2);
  ck_assert_int_eq(k1, k2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(sscanf_spec_n_4) {
  char format[] = "privet %n ";
  char str[] = "privet";
  int *n1 = 0, *n2 = 0;

  int16_t res1 = s21_sscanf(str, format, &n1);
  int16_t res2 = sscanf(str, format, &n2);
  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(n1, n2);
}
END_TEST

START_TEST(sscanf_spec_n_5) {
  char format[] = "%d %hn %d %d %d %d";
  char str[] = "80 50 70 371 327";
  int d1 = 0, d2 = 0;
  int dd1 = 0, dd2 = 0;
  int f1 = 0, f2 = 0;
  int ff1 = 0, ff2 = 0;
  int k1 = 0, k2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &dd1, &f1, &ff1, &k1, &k1);
  int16_t res2 = sscanf(str, format, &d2, &dd2, &f2, &ff2, &k2, &k2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(dd1, dd2);
  ck_assert_int_eq(f1, f2);
  ck_assert_int_eq(ff1, ff2);
  ck_assert_int_eq(k1, k2);
  ck_assert_int_eq(k1, k2);
}
END_TEST

// %0

START_TEST(sscanf_spec_ho_1) {
  char format[] = "%ho%ho%ho";
  char str[] = "102 +1564 -1723";
  unsigned short d1 = 0, d2 = 0;
  unsigned short q1 = 0, q2 = 0;
  unsigned short z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_o_2) {
  char format[] = "%o%o%o";
  char str[] = "105 +1564 -1723";
  unsigned int d1 = 0, d2 = 0;
  unsigned int q1 = 0, q2 = 0;
  unsigned int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_o_3) {
  char format[] = "%2o %2o %2o";
  char str[] = "0114 +04 -3723";
  unsigned int d1 = 0, d2 = 0;
  unsigned int q1 = 0, q2 = 0;
  unsigned int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_o_4) {
  char format[] = "%*o %*o %*o";
  char str[] = "0118 +04 -3723";
  unsigned int d1 = 0, d2 = 0;
  unsigned int q1 = 0, q2 = 0;
  unsigned int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_lo_5) {
  char format[] = "%2lo %2lo %2lo";
  char str[] = "0111 +04 -3723";
  unsigned long int d1 = 0, d2 = 0;
  unsigned long int q1 = 0, q2 = 0;
  unsigned long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

// %p

START_TEST(sscanf_spec_p_1) {
  char format[] = "%p";
  char str[] = "0xAAAA";
  int *p1 = 0, *p2 = 0;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(p1, p2);
}
END_TEST

START_TEST(sscanf_spec_p_2) {
  char format[] = "%p";
  char str[] = "0x0000";
  int *p1 = 0, *p2 = 0;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(p1, p2);
}
END_TEST

START_TEST(sscanf_spec_p_3) {
  char format[] = "%p";
  char str[] = "0xA3361598";
  int *p1 = 0, *p2 = 0;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(p1, p2);
}
END_TEST

START_TEST(sscanf_spec_p_4) {
  char format[] = "%p";
  char str[] = "0x33567hjk";
  int *p1 = 0, *p2 = 0;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(p1, p2);
}
END_TEST

START_TEST(sscanf_spec_p_5) {
  char format[] = "%p";
  char str[] = "1234567890ABCDEF";
  int *p1 = 0, *p2 = 0;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(p1, p2);
}
END_TEST

// real

START_TEST(sscanf_spec_real_1) {
  char format[] = "%fg %f w%fx";
  char str[] = "75g +19.8w -87.x";
  float d1, d2;
  float q1, q2;
  float z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
  ck_assert_float_eq(q1, q2);
  ck_assert_float_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_real_2) {
  char format[] = "%lf %lf %lf %lf";
  char str[] = "NAN nan -INF +inf";
  double d1, d2;
  double q1, q2;
  double z1, z2;
  double w1, w2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_double_nan(d1);
  ck_assert_double_nan(d2);
  ck_assert_double_nan(q1);
  ck_assert_double_nan(q2);
  ck_assert_double_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_real_3) {
  char format[] = "%*Lf %7Lf %*Lf %*Lf";
  char str[] = "34.5+6e3 83.2e-4 +43e+1 +2.43e3";
  long double d1, d2;
  long double q1 = 0, q2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1);
  int16_t res2 = sscanf(str, format, &d2, &q2);
  ck_assert_int_eq(res1, res2);
  ck_assert_ldouble_eq(d1, d2);
  ck_assert_ldouble_eq(q1, q2);
}
END_TEST

START_TEST(sscanf_spec_real_4) {
  char format[] = "%fb %7f p";
  char str[] = "34.5b 83.2ep4";
  float d1, d2;
  float q1 = 0, q2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1);
  int16_t res2 = sscanf(str, format, &d2, &q2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
  ck_assert_float_eq(q1, q2);
}
END_TEST

START_TEST(sscanf_spec_real_5) {
  char format[] = "%f %fh %2f1 %2fx %*f %*f";
  char str[] = "1.1 2.h 1.1 2.x 1.1 2.x";
  float d1, d2;
  float q1 = 0, q2 = 0;
  float z1 = 0, z2 = 0;
  float w1 = 0, w2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
  ck_assert_float_eq(q1, q2);
  ck_assert_float_eq(z1, z2);
  ck_assert_float_eq(w1, w2);
}
END_TEST

// %x

START_TEST(sscanf_spec_hx_1) {
  char format[] = "%hx%hx%hx";
  char str[] = "112 +178 -77";
  unsigned short d1, d2;
  unsigned short q1, q2;
  unsigned short z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_hx_2) {
  char format[] = "%3hx %3hx %3hx";
  char str[] = "0x111 +0X4 -37x23";
  unsigned short d1 = 0, d2 = 0;
  unsigned short q1 = 0, q2 = 0;
  unsigned short z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_x_3) {
  char format[] = "%x%x%x";
  char str[] = "111 +176 -76";
  unsigned int d1, d2;
  unsigned int q1, q2;
  unsigned int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_lx_4) {
  char format[] = "%3lx %3lx %3lx";
  char str[] = "0x114 +0X4 -37x23";
  unsigned long int d1 = 0, d2 = 0;
  unsigned long int q1 = 0, q2 = 0;
  unsigned long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_lx_5) {
  char format[] = "%*lx %*lx %*lx";
  char str[] = "0x104 +04 -372f3";
  unsigned long int d1 = 0, d2 = 0;
  unsigned long int q1 = 0, q2 = 0;
  unsigned long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

Suite *test_sscanf_c(void) {
  Suite *s = suite_create("\033[42m-=S21_SSCANF_C=-\033[0m");
  TCase *tc = tcase_create("sscanf_tc");

  tcase_add_test(tc, sscanf_spec_c_1);
  tcase_add_test(tc, sscanf_spec_c_2);
  tcase_add_test(tc, sscanf_spec_c_3);
  tcase_add_test(tc, sscanf_spec_c_4);
  tcase_add_test(tc, sscanf_spec_c_5);

  tcase_add_test(tc, sscanf_spec_s_1);
  tcase_add_test(tc, sscanf_spec_s_2);
  tcase_add_test(tc, sscanf_spec_s_3);
  tcase_add_test(tc, sscanf_spec_s_4);
  tcase_add_test(tc, sscanf_spec_s_5);

  suite_add_tcase(s, tc);
  return s;
}

Suite *test_sscanf_d(void) {
  Suite *s = suite_create("\033[42m-=S21_SSCANF_D=-\033[0m");
  TCase *tc = tcase_create("sscanf_tc");

  tcase_add_test(tc, sscanf_spec_hd_1);
  tcase_add_test(tc, sscanf_spec_hd_2);
  tcase_add_test(tc, sscanf_spec_hd_3);
  tcase_add_test(tc, sscanf_spec_d_4);
  tcase_add_test(tc, sscanf_spec_ld_5);

  suite_add_tcase(s, tc);
  return s;
}

Suite *test_sscanf_i(void) {
  Suite *s = suite_create("\033[42m-=S21_SSCANF_I=-\033[0m");
  TCase *tc = tcase_create("sscanf_tc");

  tcase_add_test(tc, sscanf_spec_i_dec_1);
  tcase_add_test(tc, sscanf_spec_i_oct_7);
  tcase_add_test(tc, sscanf_spec_i_hex_1);
  tcase_add_test(tc, sscanf_spec_hi_dec_1);
  tcase_add_test(tc, sscanf_spec_hi_dec_6);

  suite_add_tcase(s, tc);
  return s;
}

Suite *test_sscanf_n(void) {
  Suite *s = suite_create("\033[42m-=S21_SSCANF_N=-\033[0m");
  TCase *tc = tcase_create("sscanf_tc");

  tcase_add_test(tc, sscanf_spec_n_1);
  tcase_add_test(tc, sscanf_spec_n_2);
  tcase_add_test(tc, sscanf_spec_n_3);
  tcase_add_test(tc, sscanf_spec_n_4);
  tcase_add_test(tc, sscanf_spec_n_5);

  suite_add_tcase(s, tc);
  return s;
}

Suite *test_sscanf_o(void) {
  Suite *s = suite_create("\033[42m-=S21_SSCANF_O=-\033[0m");
  TCase *tc = tcase_create("sscanf_tc");

  tcase_add_test(tc, sscanf_spec_ho_1);
  tcase_add_test(tc, sscanf_spec_o_2);
  tcase_add_test(tc, sscanf_spec_o_3);
  tcase_add_test(tc, sscanf_spec_o_4);
  tcase_add_test(tc, sscanf_spec_lo_5);

  suite_add_tcase(s, tc);
  return s;
}

Suite *test_sscanf_p(void) {
  Suite *s = suite_create("\033[42m-=S21_SSCANF_P=-\033[0m");
  TCase *tc = tcase_create("sscanf_tc");

  tcase_add_test(tc, sscanf_spec_p_1);
  tcase_add_test(tc, sscanf_spec_p_2);
  tcase_add_test(tc, sscanf_spec_p_3);
  tcase_add_test(tc, sscanf_spec_p_4);
  tcase_add_test(tc, sscanf_spec_p_5);

  suite_add_tcase(s, tc);
  return s;
}

Suite *test_sscanf_real(void) {
  Suite *s = suite_create("\033[42m-=S21_SSCANF_REAL=-\033[0m");
  TCase *tc = tcase_create("sscanf_tc");

  tcase_add_test(tc, sscanf_spec_real_1);
  tcase_add_test(tc, sscanf_spec_real_2);
  tcase_add_test(tc, sscanf_spec_real_3);
  tcase_add_test(tc, sscanf_spec_real_4);
  tcase_add_test(tc, sscanf_spec_real_5);

  suite_add_tcase(s, tc);
  return s;
}

Suite *test_sscanf_x(void) {
  Suite *s = suite_create("\033[42m-=S21_SSCANF_X=-\033[0m");
  TCase *tc = tcase_create("sscanf_tc");

  tcase_add_test(tc, sscanf_spec_hx_1);
  tcase_add_test(tc, sscanf_spec_hx_2);
  tcase_add_test(tc, sscanf_spec_x_3);
  tcase_add_test(tc, sscanf_spec_lx_4);
  tcase_add_test(tc, sscanf_spec_lx_5);

  suite_add_tcase(s, tc);
  return s;
}