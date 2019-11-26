#ifndef __COMMANDS_TEST_CPP__
#define __COMMANDS_TEST_CPP__

#include "../src/Base.h"
#include "../src/Command.cpp"

TEST(CommandsTest, ListDir1) {
	std::string arg = "ls";
	Base* test = new Command(arg);
	EXPECT_EQ(test->execute(),true);
}

TEST(CommandsTest, ListDir2) {
	std::string arg = "ls -a";
	Base* test = new Command(arg);
	EXPECT_EQ(test->execute(),true);
}

TEST(CommandsTest, Echo1) {
	std::string arg = "echo Hello World";
	Base* test = new Command(arg);
	EXPECT_EQ(test->execute(), true);
}

TEST(CommandsTest, Echo2) {
	std::string arg = "echo adsf dsaf adsfsd f dsf asdf daf dsf adsfsd fsda f";
	Base* test = new Command(arg);
	EXPECT_EQ(test->execute(),true);
}

TEST(CommandsTest, Git1) {
	std::string arg = "git status";
	Base* test = new Command(arg);
	EXPECT_EQ(test->execute(),true);
}

TEST(CommandsTest, Git2) {
	std::string arg = "git branch";
	Base* test = new Command(arg);
	EXPECT_EQ(test->execute(),true);
}

TEST(CommandsTest, MakeDir1) {
	std::string arg = "mkdir TESTDIR";
	Base* test = new Command(arg);
	EXPECT_EQ(test->execute(),true);
}

TEST(CommandsTest, MakeDir2) {
	std::string arg = "mkdir";
	Base* test = new Command(arg);
	EXPECT_EQ(test->execute(),true);
}



#endif
