#define TEST(method_name) static void method_name(void)
#define TEST_SUITE(suite_name) static void suite_name(void)

#define SAFE_BLOCK(block) do {\
	block\
} while(0)

#define RUN_SUITE(suite_name) SAFE_BLOCK(\
	suite_name();\
)

#define RUN_TEST(test) SAFE_BLOCK(\
	test_status = 0;\
	test();\
	test_run++;\
	if (test_status) {\
		test_fail++;\
	}\
)

#define check_assert(test, message) SAFE_BLOCK(\
	test_assert++;\
	if (!(test)) {\
		printk("Test %s failed: %s", __func__, message);\
		printk("In %s:%d",  __FILE__, __LINE__);\
		test_status = 1;\
		return;\
	}\
)

#define TEST_REPORT() SAFE_BLOCK(\
	printk("Result: %d tests, %d assertions, %d failures\n", test_run, test_assert, test_fail);\
)