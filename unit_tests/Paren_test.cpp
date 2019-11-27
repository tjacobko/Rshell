#ifndef __PAREN_TEST_CPP__
#define __PAREN_TEST_CPP__

#include "../src/Base.h"
#include "../src/Command.cpp"
#include "../src/Paren.cpp"

TEST(ParenTest, Paren1) {
	Base* ls = new Command("ls");
	Base* paren = new Paren(ls);
	EXPECT_EQ(paren->execute(), true);
}

#endif
