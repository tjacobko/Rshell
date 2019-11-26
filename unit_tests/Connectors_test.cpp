#ifndef __CONNECTORS_TEST_CPP__
#define __CONNECTORS_TEST_CPP__

#include "../src/Base.h"
#include "../src/Command.cpp"
#include "../src/orConnect.cpp"
#include "../src/ampersand.cpp"
#include "../src/semicolon.cpp"

TEST(ConnectorsTest, OrConnectorTest) {
	std::string arg = "echo Hello";
	Base* echo1 = new Command(arg);
	
	std::string arg2 = "echo not Hello";
	Base* echo2 = new Command(arg2);
	
	Base* test = new OrConnector(echo1, echo2);
	//Base* test = new Command(arg);
	EXPECT_EQ(test->execute(), true);;
}


TEST(ConnectorsTest, AmpersandTest) {
	std::string arg = "echo Hello";
	Base* echo1 = new Command(arg);

	std::string arg2 = "echo alsoHello";
	Base* echo2 = new Command(arg2);

	Base* test = new Ampersand(echo1, echo2);
	
	EXPECT_EQ(test->execute(), true);
}

TEST(ConnectorsTest, SemicolonTest) {
	std::string arg = "echo This works";
	Base* echo1 = new Command(arg);
	
	std::string arg2 = "echo This also works";
	Base* echo2 = new Command(arg2);
	
	Base* test = new Semicolon(echo1, echo2);
	
	EXPECT_EQ(test->execute(), true);
}

TEST(ConnectorsTest, ThreeCases) {
	std::string arg = "ls adfs";
	Base* ls1 = new Command(arg);

	std::string arg2 = "echo Yes";
	Base* echo1 = new Command(arg2);
	
	Base* arg1and2 = new OrConnector(ls1, echo1);
	//arg1and2->execute();

	std::string arg3 = "echo YesAgain";
	Base* echo2 = new Command(arg3);
	
	Base* allThree = new Ampersand(arg1and2, echo2);
	EXPECT_EQ(allThree->execute(), true);
}

TEST(ConnectorsTest, ThreeCases2) {
	std::string arg = "echo No";
	Base* echo1 = new Command(arg);

	std::string arg2 = "echo Stress";
	Base* echo2 = new Command(arg);
	
	Base* twoEcho = new Ampersand(echo1, echo2);

	std::string arg3 = "echo Environment";
	Base* echo3 = new Command(arg3);
	
	Base* threeEcho = new Ampersand(twoEcho, echo3);
	EXPECT_EQ(threeEcho->execute(), true);
}

TEST(ConnectorsTest, FourCases) {
	std::string arg = "git dsafds";
	Base* gitBAD = new Command(arg);
	
	std::string arg2 = "echo Git didn't work";
	Base* echo1 = new Command(arg2);

	std::string arg3 = "echo THIS WORKS";
	Base* echo2 = new Command(arg3);

	std::string arg4 = "git status";
	Base* git2 = new Command(arg4);

	Base* twoArgs = new OrConnector(gitBAD, echo1);
	Base* threeArgs = new Ampersand(twoArgs, echo2);
	Base* fourArgs = new OrConnector(threeArgs, git2);
	
	EXPECT_EQ(fourArgs->execute(), true);
}




#endif
