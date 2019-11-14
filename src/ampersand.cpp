#ifndef __AMPERSAND_CPP__
#define __AMPERSAND_CPP__

#include "ampersand.h"

Ampersand::Ampersand() : Base() {
	this->lhs = nullptr;
	this->rhs = nullptr;
}

Ampersand::Ampersand(Base* lhs, Base* rhs) : Base() {
	this->lhs = lhs;
	this->rhs = rhs;
}

Ampersand::~Ampersand() {

}

void Ampersand::execute() {
	if(this->lhs->getRun() == false) {
		this->lhs->execute();
	}
	if(this->lhs->getStatus() == true) {
		this->rhs->execute();
	}
	else {
		this->rhs->setRun(true);
	}
}

#endif
