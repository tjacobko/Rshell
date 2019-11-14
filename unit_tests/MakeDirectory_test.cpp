#ifndef __MAKEDIRECTORY_TEST_CPP__
#define __MAKEDIRECTORY_TEST_CPP__

#include "../src/MakeDirectory.cpp"

TEST(MakeDirectoryTest, MkDirExecute1) {
	Base* test = new MkDir();
	test->execute();
}

TEST(MakeDirectoryTest, MkDirExecute2) {
	std::string arg = "testDirectory";
	Base* test = new MkDir(arg);
	test->execute();
}

TEST(MakeDirectoryTest, MkDirExecute3) {
        std::string arg = "_im";
	Base* test = new MkDir(arg);
	test->execute();	

	std::string arg2 = "_tired";
	Base* test2 = new MkDir(arg2);
	test2->execute();
}

#endif
