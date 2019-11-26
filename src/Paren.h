#ifndef __PAREN_H__
#define __PAREN_H__

#include "Base.h"

class Paren : public Base {
	public:
		Paren(Base*);
		virtual bool execute();
	private:
		Base* element = nullptr;
};

#endif
