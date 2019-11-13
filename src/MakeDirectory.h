#ifndef __MAKEDIRECTORY_H__
#define __MAKEDIRECTORY_H__

#include "Base.h"

class MkDir : public Base {
	public:
		MkDir();
		MkDir(std::string args);
		virtual bool execute();
	private:
		std::vector<char*> argList;
};

#endif
