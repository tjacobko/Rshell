#ifndef __EXIT_TEST_CPP__
#define __EXIT_TEST_CPP__

#include "../src/Exit.cpp"

TEST(ExitTest, ExitExecute1) {
	Base* test = new Exit();
	test->execute();
}

#endif
