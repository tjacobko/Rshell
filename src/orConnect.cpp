#ifndef __ORCONNECT_CPP__
#define __ORCONNECT_CPP__

#include "Connector.h"
#include "orConnector.h"

orConnect::orConnect() : Connector() {}
orConnect::orConnect(Base* lhs, Base* rhs) : Connector(lhs, rhs) {}

bool orConnector::execute() {
	if(!lhs->execute()) {
		if(rhs->execute()) {
			return true;
		}
		else {
			return false;
		}
	}
	return true;	
}

#endif
