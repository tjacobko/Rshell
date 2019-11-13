#ifndef __LISTDIRECTORY_TEST_CPP__
#define __LISTDIRECTORY_TEST_CPP__

#include "../src/ListDirectory.cpp"

TEST(ListDirectoryTest, ListExecute) {
	Base* test = new List("status");
	EXPECT_EQ(test->execute(), true);
}

#endif
