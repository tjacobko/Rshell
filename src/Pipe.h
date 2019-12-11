#ifndef __PIPE_H__
#define __PIPE_H__

#include "Base.h"

class Pipe : public Base {
	public:
		Pipe(Base* lhs, Base* rhs) : Base() {this->lhs = lhs; this->rhs = rhs;}
		virtual bool execute();
	private:
		Base* lhs = nullptr;
		Base* rhs = nullptr;		
};

#endif
