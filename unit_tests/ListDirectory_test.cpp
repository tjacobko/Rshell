#ifndef __LISTDIRECTORY_TEST_CPP__
#define __LISTDIRECTORY_TEST_CPP__

#include "../src/ListDirectory.cpp"

TEST(ListDirectoryTest, ListExecute1) {
	std::string arg = "-a";
	Base* test = new List(arg);
	test->execute();
}

TEST(ListDirectoryTest, ListExecute2) {
	std::string arg = "-a";
	Base* test = new List(arg);
	test->execute();
	
	std::string arg2 = "-l";
	Base* test2 = new List(arg2);
	test2->execute();
}

TEST(ListDirectoryTest, ListExecute3) {
	std::string arg = "-l";
	std::string arg2 = "-a";
	Base* test = new List();
	Base* test2 = new List(arg2);

	test->execute();
	test2->execute();
}
/*
TEST(ListDirectoryTest, ListExecute4) {
	std::string arg = "-a -l";
	Base* test = new List(arg);
	EXPECT_EQ(test->execute(), true);
}

TEST(ListDirectoryTest, ListExecute5) {
	Base* test = new List();
	std::string a = "-a";
	Base* test2 = new List(a);
	//std::string l = "-l";
	//Base* test3 = new List(l);
	EXPECT_EQ(test->execute(), true);
	EXPECT_EQ(test2->execute(), true);
	//EXPECT_EQ(test3->execute(), true);
}

TEST(ListDirectoryTest, ListExecute6) {
        Base* test1 = new List();
        //Base* test2 = new List();
        EXPECT_EQ(test1->execute(), true);
        //EXPECT_EQ(test2->execute(), true);
}*/

#endif
