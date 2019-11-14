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

orConnector::~orConnector() {}

void orConnector::execute() {
	if(this->lhs->getRun() == false) {
		this->lhs->execute();
	}	
	if(this->lhs->getStatus() == false) {
		this->rhs->execute();
	}
	else {
		this->rhs->setRun(true);
	}
}

#endif
