#include "minunit.h"
#include <lcthw/bstrlib.h>

char *test_create() {
  bstring string = bfromcstr("Hello, World!");
  mu_assert(string != NULL, "bstring create failed.");
  return NULL;
}

char *test_compare() {
  bstring string1 = bfromcstr("Hello, World!");
  bstring string2 = bfromcstr("Hello, World!");
  mu_assert(bstricmp(string1, string2) == 0, "bstring compare failed.");
  return NULL;
}

char *test_in() {
  bstring string1 = bfromcstr("Hello, World!");
  bstring string2 = bfromcstr("lo, Wor");
  mu_assert(binstr(string1, 0, string2), "bstring in failed.");
  return NULL;
}

char * all_tests() {
  mu_suite_start();
  mu_run_test(test_create);
  mu_run_test(test_compare);
  return NULL;
}

RUN_TESTS(all_tests);
