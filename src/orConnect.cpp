#ifndef __ORCONNECT_CPP__
#define __ORCONNECT_CPP__

#include "orConnect.h"

orConnector::orConnector() : Base() {
	this->lhs = nullptr;
	this->rhs = nullptr;
}

orConnector::orConnector(Base* lhs, Base* rhs) : Base() {
	this->lhs = lhs;
	this->rhs = rhs;
}

void orConnector::setLHS(Base* lhs) {
	this->lhs = lhs;
}

void orConnector::setRHS(Base* rhs) {
	this->rhs = rhs;
}

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
