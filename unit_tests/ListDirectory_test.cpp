#ifndef __LISTDIRECTORY_TEST_CPP__
#define __LISTDIRECTORY_TEST_CPP__

#include "../src/ListDirectory.cpp"
//#include "gtest/gtest.h"

TEST(ListDirectoryTest, ListExecute1) {
	Base* test = new List("-a");
	EXPECT_EQ(test->execute(), true);
}

TEST(ListDirectoryTest, ListExecute2) {
	Base* test = new List();
	EXPECT_EQ(test->execute(), true);
}

TEST(ListDirectoryTest, ListExecute3) {
	Base* test = new List("-l -a");
	EXPECT_EQ(test->execute(), true);
}
#endif
