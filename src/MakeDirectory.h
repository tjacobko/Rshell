#ifndef __MAKEDIRECTORY_H__
#define __MAKEDIRECTORY_H__

#include "Base.h"

class MkDir : public Base {
	public:
		MkDir();
		MkDir(std::string args);
		~MkDir();
		virtual void execute();
	private:
		int size;
		char** argList = new char*[size];
};

#endif
