#ifndef __LISTDIRECTORY_H__
#define __LISTDIRECTORY_H__

#include "Base.h"

class List : public Base {
	public:
		List();
		List(std::string args);
		bool execute();
	private:
		std::vector<char*> argList;
};

#endif
