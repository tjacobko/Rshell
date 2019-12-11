#ifndef __PIPE_CPP__
#define __PIPE_CPP__

#include "Pipe.h"
#include "unistd.h"


bool Pipe::execute(int in, int out) {
	int fds[2];
	
	if(pipe(fds) == -1) {
		perror("piping error");
		return false;
	}

	if(!this->lhs->execute(in, fds[1])) {
		return false;
	}
	close(fds[1]);
	
	if(!this->rhs->execute(fds[0], out)) {
		return false;
	}
	close(fds[0]);
	return true;
}

#endif
