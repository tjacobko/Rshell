#ifndef __GIT_H__
#define __GIT_H__

#include "Base.h"

class Git : public Base {
	public:
		Git();
		Git(std::string args);
		bool execute();
};

#endif
