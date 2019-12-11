#ifndef __APPEND_TEST_CPP__
#define __APPEND_TEST_CPP__

#include "../src/Base.h"
#include "../src/Append.h"
#include "../src/Command.cpp"
#include "../src/Pipe.cpp"


TEST(AppendTest, Test1) {
	Base* com1 = new Command("cat test.txt");
	Base* com2 = new Command("tr a-z A-Z");

	Base* pipe1 = new Pipe(com1, com2);
	
	Base* com3 = new Command("tee newOutputFile");
	
	Base* pipe2 = new Pipe(pipe1, com3);
	pipe2->execute();
}

TEST(AppendTest, Test2) {
	Base* com1 = new Command("cat test2.txt");
	Base* com2 = new Command("tr A-Z a-z");
	
	Base* pipe1 = new Pipe(com1, com2);
	
	Base* com3 = new Command("tee newOutputFile2");
	
	Base* pipe2 = new Pipe(pipe1, com3);
	pipe2->execute();
}

TEST(AppendTest, Test3) {
	Base* com1 = new Command("cat -n multipleLines.txt");
	Base* com2 = new Command("tr a-z A-Z");
	
	Base* pipe1 = new Pipe(com1, com2);
	
	Base* com3 = new Command("tee newOutputFile3");
	
	Base* pipe2 = new Pipe(pipe1, com3);
	pipe2->execute();
}

#endif
