#ifndef __MAKEDIRECTORY_TEST_CPP__
#define __MAKEDIRECTORY_TEST_CPP__

#include "../src/MakeDirectory.cpp"

TEST(MakeDirectoryTest, MkDirExecute1) {
	//Base* test = new MkDir("TEST_DIRECTORY");
	//EXPECT_EQ(test->execute(), true);
}

TEST(MakeDirectoryTest, MkDirExecute2) {
	Base* test = new MkDir();
	EXPECT_EQ(test->execute(), true);
}

TEST(MakeDirectoryTest, MkDirExecute3) {
        //Base* test1 = new MkDir("TEST_DIRECTORY2");
	//Base* test2 = new MkDir("TEST_DIRECTORY3");
        //EXPECT_EQ(test1->execute(), true);
	//EXPECT_EQ(test2->execute(), true);
}

#endif
