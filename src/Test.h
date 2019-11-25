#ifndef __TEST_H__
#define __TEST_H__

#include "Base.h"

class Test : public Base {
	public:
		Test() : Base() {};
		virtual bool execute();
};

#endif
