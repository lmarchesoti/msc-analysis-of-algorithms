#include "../lib/tinytest.h"
#include "functions.cpp"

/* test suite declarations */
TINYTEST_DECLARE_SUITE(suite);

/* test specifications */
int test(){

	return 1;
}

/* test suite initializations */
TINYTEST_START_SUITE(suite);
  TINYTEST_ADD_TEST(test);
TINYTEST_END_SUITE();

/* test main */
TINYTEST_MAIN_SINGLE_SUITE(suite);
