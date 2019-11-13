#ifndef __ECHO_H__
#define __ECHO_H__

#include "Base.h"

class Echo : public Base {
	public:
		Echo();
		Echo(std::string args);
		bool execute();
	private:
		std::vector<char*> argList;
};

#endif
