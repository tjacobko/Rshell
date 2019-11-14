#ifndef __LISTDIRECTORY_H__
#define __LISTDIRECTORY_H__

#include "Base.h"

class List : public Base {
	public:
		List();
		List(std::string args);
		~List();
		virtual void execute();
	private:
		int size;
		char** argList = new char*[size];
};

#endif
