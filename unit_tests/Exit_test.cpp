#ifndef __EXIT_CPP__
#define __EXIT_CPP__

#include "../src/Exit.cpp"

TEST(ExitTest, Exit1) {
	std::string arg = "exit";
	Base* test = new Exit();
	test->execute();
}

#endif
