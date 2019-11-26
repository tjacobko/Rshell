#ifndef __TEST_UNIT_CPP__
#define __TEST_UNIT_CPP__

#include "../src/Base.h"
#include "../src/TestF.cpp"

TEST(TestFCase, CheckE) {
	Base* test = new TestF("Test_unit.cpp");
	test->execute();
}

TEST(TestFCase, CheckF) {
	Base* test = new TestF("-f Test_unit.cpp");
	test->execute();
}

#endif
