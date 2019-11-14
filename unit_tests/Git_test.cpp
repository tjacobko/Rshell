#ifndef __GIT_TEST_CPP__
#define __GIT_TEST_CPP__

#include "../src/Git.cpp"

TEST(GitTest, GitExecute1) {
	std::string arg = "status";
	Base* test = new Git(arg);
	test->execute();

	std::string arg2 = "branch";
	Base* test2 = new Git(arg2);
	test2->execute();
}

TEST(GitTest, GitExecute2) {
	std::string arg = "branch";
	Base* test = new Git(arg);
	test->execute();
}

TEST(GitTest, GitExecute3) {
	std::string arg = "add";
	Base* test = new Git(arg);
	test->execute();
}

#endif
