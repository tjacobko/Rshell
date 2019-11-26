#ifndef __TEST_UNIT_CPP__
#define __TEST_UNIT_CPP__

#include "../src/Base.h"
#include "../src/TestF.cpp"

TEST(TestFCase, CheckNoFlag) {
	std::string args = "rshell";
	Base* test = new TestF(args);
	EXPECT_EQ(test->execute(), true);
}

TEST(TestFCase, CheckE) {
	std::string args = "-e names.txt";
	Base* test = new TestF(args);
	EXPECT_EQ(test->execute(), true);
}

TEST(TestFCase, CheckF) {
	Base* test = new TestF("-f CMakeLists.txt");
	EXPECT_EQ(test->execute(), true);
}

TEST(TestFCase, CheckD) {
	Base* test1 = new TestF("-d src");
	Base* test2 = new TestF("-f src");
	EXPECT_EQ(test1->execute(), true);
	EXPECT_EQ(test2->execute(), false);
}

TEST(TestFCase, CheckF2) {
	Base* test1 = new TestF("-f names.txt");
	Base* test2 = new TestF("-d names.txt");
	EXPECT_EQ(test1->execute(), true);
	EXPECT_EQ(test2->execute(), false);
}

#endif
