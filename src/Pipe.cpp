#ifndef __PIPE_CPP__
#define __PIPE_CPP__

#include "Pipe.h"
#include "unistd.h"


Pipe::Pipe(Base* lhs,Base* rhs) : Base(lhs, rhs) {
	this->inputRedir = 0;
	this->outputRedir = 0;
}

bool Pipe::execute() {
	int fds[2];
	bool test;
	
	if(pipe(fds) == -1) {
		perror("pipe issue");
		return false;
	}
	
	lhs->setRedir(inputRedir, fds[1]);
	test = lhs->execute();
	if(test == false) {
		return false;
	}	
	
	if(close(fds[1]) == -1) {
		perror("pipe closing issue");
		return false;
	}
	
	rhs->setRedir(fds[0], outputRedir);
	test = rhs->execute();
	if(test == false) {
		return true;
	}
	
	if(close(fds[1]) == -1)  {
		perror("pipe closing issue");
		return false;
	}
	
	return true;
}

void Pipe::setRedir(int input, int output) {
	this->inputRedir = input;
	this->outputRedir = output;
}

#endif
