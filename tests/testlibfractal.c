#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <CUnit/CUnit.h>

#include "../libfractal/fractal.h"

extern char *name;
extern int width;
extern int height;
extern double a;
extern double b;

void test_lib_getname() {
  fractal_t *testf = fractal_new("testname", width, height, a, b);
  CU_ASSERT_EQUAL(fractal_get_name(testf), "testname");
  fractal_free(testf);
}
void test_lib_getwidth() {
	fractal_t *testf = fractal_new(name, 69, height, a, b);
	CU_ASSERT_EQUAL(fractal_get_width(testf), 69);
	fractal_free(testf);
}

void test_lib_getheight() {
	fractal_t *testf = fractal_new(name, width, 69, a, b);
	CU_ASSERT_EQUAL(fractal_get_height(testf), 69);
	fractal_free(testf);
}

void test_lib_geta() {
	fractal_t *testf = fractal_new(name, width, height, 69.0, b);
	CU_ASSERT_EQUAL(fractal_get_a(testf), 69.0);
	fractal_free(testf);
}

void test_lib_getb() {
	fractal_t *testf = fractal_new(name, width, height, a, 69.0);
	CU_ASSERT_EQUAL(fractal_get_b(testf), 69.0);
	fractal_free(testf);
}

void test_setvalue_and_getvalue(){
  fractal_t *testf = fractal_new(name, 15, 15, a, b);
  int xwidth = fractal_get_width(testf);
  int xheight = fractal_get_height(testf);
  int i = 0, j = 0;
  for ( i=0; i<xheight ; i++) {
    for ( j=0 ; j<xwidth ; j++){
      fractal_set_value(testf, j, i, j+i*15);
    }
  }

  for ( i = 0; i < xheight ; i++) {
  for( j = 0; j < xwidth ; j++)  {
    CU_ASSERT_EQUAL(fractal_get_value(ptr, j, i), j+i*15);
  }
}
  fractal_free(testf);
}
int setup(void) {
	*name = "testname";
	width = 0;
	height = 0;
	a = 0.0;
	b = 0.0;
	return 0;
}

int teardown(void) {
	return 0;
}

int main(int argc, char const *argv[]) {
	if (CUE_SUCCESS != CU_initialize_registry())
		return CU_get_error();
	CU_pSuite pSuite = NULL;
	pSuite = CU_add_suite("Suite de tests : libfractal", setup, teardown);
	if (NULL == pSuite) {
		CU_cleanup_registry();
		return CU_get_error();
	}
	if ((NULL == CU_add_test(pSuite, "Name", test_libfractal_get_name)) ||
			(NULL == CU_add_test(pSuite, "Name", test_libfractal_get_width)) ||
			(NULL == CU_add_test(pSuite, "Name", test_libfractal_get_height)) ||
			(NULL == CU_add_test(pSuite, "Name", test_libfractal_get_a)) ||
			(NULL == CU_add_test(pSuite, "Name", test_libfractal_get_b))||
			(NULL == CU_add_test(pSuite, "Name", test_libfractal_set_and_get_value))) {
		CU_cleanup_registry();
		return CU_get_error();
	}
	CU_basic_run_tests();
	CU_basic_show_failures(CU_get_failure_list());
	CU_cleanup_registry();
	return 0;
}
