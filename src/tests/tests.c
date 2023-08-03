#include "tests.h"

int main() {
  int failed = 0;
  Suite *test_string_plus[] = {test_sprintf(),
                               test_memchr(),
                               test_memcmp(),
                               test_memcpy(),
                               test_memset(),
                               test_strncat(),
                               test_strchr(),
                               test_strncmp(),
                               test_strncpy(),
                               test_strcspn(),
                               test_strerror(),
                               test_strlen(),
                               test_strpbrk(),
                               test_strrchr(),
                               test_strstr(),
                               test_strtok(),
                               test_to_upper(),
                               test_to_lower(),
                               test_insert(),
                               test_trim(),
                               test_sscanf_c(),
                               test_sscanf_d(),
                               test_sscanf_i(),
                               test_sscanf_o(),
                               test_sscanf_x(),
                               test_sscanf_p(),
                               test_sscanf_n(),
                               test_sscanf_real(),
                               NULL};
  for (int i = 0; test_string_plus[i]; i++) {
    SRunner *sr = srunner_create(test_string_plus[i]);
    srunner_run_all(sr, CK_NORMAL);
    failed += srunner_ntests_failed(sr);
    srunner_free(sr);
  }
  printf("========= FAILED: %d =========\n", failed);
}