#ifndef __ECHO_TEST_CPP__
#define __ECHO_TEST_CPP__

#include "../src/Echo.cpp"

TEST(EchoTest, EchoExecute1) {
	std::string arg = "HelloWorld";
	Base* test = new Echo(arg);
	test->execute();
}

TEST(EchoTest, EchoExecute2) {
	std::string arg = "Hi Hello World";
	Base* test = new Echo(arg);
	test->execute();
}

TEST(EchoTest, No_Params_EchoExecute3) {
	Base* test = new Echo();
	test->execute();
}

TEST(EchoTest, Two_White_Space_EchoExecute4) {
	std::string arg = "Hey  Hello";
	Base* test = new Echo(arg);
	test->execute();
}

#endif
