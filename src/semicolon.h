#ifndef __SEMICOLON_H__
#define __SEMICOLON_H__

#include "Base.h"

class Semicolon : public Base {
	public:
		Semicolon();
		Semicolon(Base* lhs, Base* rhs);
		~Semicolon();
		void setLHS(Base* lhs);
		void setRHS(Base* rhs);
		virtual void execute();
	private:
		Base* lhs;
		Base* rhs;
};
#endif
