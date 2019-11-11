#ifndef __CONNECTOR_H__
#define __CONNECTOR_H__

#include "Base.h"
using namespace std;

class Connector : public Base {
	protected:
		Base* lhs;
		Base* rhs;

	public:
		Connector();
		Connector(Base* lhs, Base* rhs);
		
		virtual bool execute() = 0;
};

#endif
