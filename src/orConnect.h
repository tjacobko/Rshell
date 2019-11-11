#ifndef __ORCONNECT_H__
#define __ORCONNECT_H__

#include "Connector.h"

class orConnector : public Connector {
	public:
		orConnector();
		orConnector(Base* lhs, Base* rhs);

		virtual bool execute();
};
