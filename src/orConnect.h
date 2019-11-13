#ifndef __ORCONNECT_H__
#define __ORCONNECT_H__

#include "Base.h"

class orConnector : public Base {
	public:
		orConnector();
		orConnector(Base* lhs, Base* rhs);
		void setLHS(Base* lhs);
		void setRHS(Base* rhs);
		virtual bool execute();
	private:
		Base* lhs;
		Base* rhs;
};

#endif
