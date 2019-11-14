#ifndef __EXIT_CPP__
#define __EXIT_CPP__

#include "Exit.h"

Exit::Exit() : Base() {}

void Exit::execute() {
	exit(0);
}

#endif
