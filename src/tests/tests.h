#ifndef TESTS_H
#define TESTS_H

#include <check.h>
#include <stdio.h>
#include <string.h>

#include "../my_string/my_string.h"

Suite *test_sprintf();
Suite *test_memchr(void);
Suite *test_memcmp(void);
Suite *test_memcpy(void);
Suite *test_memset(void);
Suite *test_strncat(void);
Suite *test_strchr(void);
Suite *test_strncmp(void);
Suite *test_strncpy(void);
Suite *test_strcspn(void);
Suite *test_strerror(void);
Suite *test_strlen(void);
Suite *test_strpbrk(void);
Suite *test_strrchr(void);
Suite *test_strstr(void);
Suite *test_strtok(void);
Suite *test_to_upper(void);
Suite *test_to_lower(void);
Suite *test_insert(void);
Suite *test_trim(void);
Suite *test_sscanf_c(void);
Suite *test_sscanf_d(void);
Suite *test_sscanf_i(void);
Suite *test_sscanf_o(void);
Suite *test_sscanf_x(void);
Suite *test_sscanf_p(void);
Suite *test_sscanf_n(void);
Suite *test_sscanf_real(void);

#endif