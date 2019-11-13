#ifndef __GIT_TEST_CPP
#define __GIT_TEST_CPP

#include "../src/Git.h"
#include "../src/Base.h"
#include "./CMakeLists.txt"

TEST(GitTest, FirstTest) {
	Base* test = new Git("status");
	EXPECT_EQ(test->execute(), true);
}

#endif
