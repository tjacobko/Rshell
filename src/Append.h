#ifndef __APPEND_H__
#define __APPEND_H__

#include "Base.h"

class Append : public Base {
	public:
		Append(Base* lhs, Base* rhs);
		virtual bool execute();
	private:
		Base* lhs = nullptr;
        	Base* rhs = nullptr;
};

#endif

