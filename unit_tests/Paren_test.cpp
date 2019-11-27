#ifndef __PAREN_TEST_CPP__
#define __PAREN_TEST_CPP__

#include "../src/Base.h"
#include "../src/Command.cpp"
#include "../src/Paren.cpp"
//#include "../src/orConnect.cpp"
//#include "../src/ampersand.cpp"
//#include "../src/semicolon.cpp"

TEST(ParenTest, Paren1) {
	Base* ls = new Command("ls");
	Base* paren = new Paren(ls);
	EXPECT_EQ(paren->execute(), true);
}

TEST(ParenTest, Paren2) {
	Base* ls = new Command("ls -a");
	Base* echo = new Command("echo failed");
	Base* orC = new OrConnector(ls, echo);
	Base* paren = new Paren(orC);
	EXPECT_EQ(paren->execute(), true);
}

TEST(ParenTest, Paren3) {
	Base* echo1 = new Command("echo A");
	Base* echo2 = new Command("echo B");
	Base* echo3 = new Command("echo C");
	Base* amp = new Ampersand(echo1, echo2);
	Base* paren = new Paren(amp);
	Base* orC = new OrConnector(paren, echo3);
	EXPECT_EQ(orC->execute(), true);
}

#endif
