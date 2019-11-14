#ifndef __AMPERSAND_H__
#define __AMPERSAND_H__

#include "Base.h"

class Ampersand : public Base {
	public:
		Ampersand();
		Ampersand(Base* lhs, Base* rhs);
		~Ampersand();
		void setLHS(Base* lhs);
		void setRHS(Base* rhs);
		virtual void execute();
	private:
		Base* lhs;
		Base* rhs;
};
#endif
