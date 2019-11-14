#ifndef __EXIT_CPP__
#define __EXIT_CPP__

#include "Exit.h"

Exit::Exit() : Base() {}

bool Exit::getStatus() {
        return this->status;
}

bool Exit::getRun() {
        return this->run;
}

void Exit::setRun(bool newRun) {
        this->run = newRun;
        return;
}

void Exit::execute() {
	exit(0);
}

#endif
