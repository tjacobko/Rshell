#ifndef __PIPE_CPP__
#define __PIPE_CPP__

#include "Pipe.h"
#include "unistd.h"


Pipe::Pipe(Base* lhs,Base* rhs) : Base(lhs, rhs) {}

bool Pipe::execute() {
	int fds[2];
	
	if(pipe(fds) == 1) {
		perror("pipe issue");
		return false;
	}
	
	if(!lhs->execute() {
		
	}
}

#endif
