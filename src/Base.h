#ifndef __BASE_H__
#define __BASE_H__

#include <string>

class Base {
	public:
		Base() {};
		virtual bool execute() = 0;
};

#endif
