#ifndef __PIPE_H__
#define __PIPE_H__

#include "Base.h"

class Pipe : public Base {
	public:
		Pipe(Base* lhs, Base* rhs);
		virtual bool execute();
		
};

#endif
