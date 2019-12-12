#ifndef __APPEND_TEST_CPP__
#define __APPEND_TEST_CPP__

#include "../src/Base.h"
#include "../src/Append.cpp"
#include "../src/Command.cpp"
#include "../src/Pipe.cpp"
#include "../src/Write.cpp"

TEST(PipeTest, Test1) {
	Base* com1 = new Command("cat unit_tests/testTXTdir/test.txt");
	Base* com2 = new Command("tr a-z A-Z");

	Base* pipe1 = new Pipe(com1, com2);
	
	Base* com3 = new Command("tee unit_tests/testTXTdir/newOutputFile");
	
	Base* pipe2 = new Pipe(pipe1, com3);
	pipe2->execute();
}

TEST(PipeTest, Test2) {
	Base* com1 = new Command("cat unit_tests/testTXTdir/test2.txt");
	Base* com2 = new Command("tr A-Z a-z");
	
	Base* pipe1 = new Pipe(com1, com2);
	
	Base* com3 = new Command("tee unit_tests/testTXTdir/newOutputFile2");
	
	Base* pipe2 = new Pipe(pipe1, com3);
	pipe2->execute();
}

TEST(PipeTest, Test3) {
	Base* com1 = new Command("cat -n unit_tests/testTXTdir/multipleLines.txt");
	Base* com2 = new Command("tr a-z A-Z");
	
	Base* pipe1 = new Pipe(com1, com2);
	
	Base* com3 = new Command("tee unit_tests/testTXTdir/newOutputFile3");
	
	Base* pipe2 = new Pipe(pipe1, com3);
	pipe2->execute();
}

TEST(AppendTest, AppTest1) {
	Base* com1 = new Command("cat unit_tests/testTXTdir/input.txt");
	Base* com2 = new Command("tr a-z A-Z");
	
	Base* pipe1 = new Pipe(com1, com2);
	Base* append = new Append(pipe1, "testTXTdir/append.txt");
	append->execute();
}

TEST(WriteTest, WriteTest1) {
	Base* com1 = new Command("cat unit_tests/testTXTdir/input2.txt");
	Base* com2 = new Command("tr A-Z a-z");
	
	Base* pipe1 = new Pipe(com1, com2);
	Base* write = new Write(pipe1, "unit_tests/testTXTdir/write.txt");
	write->execute();
}

#endif
