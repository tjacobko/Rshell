#ifndef __EXIT_CPP__
#define __EXIT_CPP__

#include "Exit.h"
#include "Commands.h"
#include "Base.h"

Exit::Exit() {}

bool Exit::execute() {
	exit(0);
}

#endif
