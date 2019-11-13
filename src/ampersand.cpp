#ifndef __AMPERSAND_CPP__
#define __AMPERSAND_CPP__

#include "ampersand.h"

Ampersand::Ampersand() : Base() {
	this-> lhs = nullptr;
	this-> rhs = nullptr;
}

Ampersand::Ampersand(Base* lhs, Base* rhs) : Base() {
	this-> lhs = lhs;
	this-> rhs = rhs;
}

void Ampersand::setLHS(Base* lhs) {
	this-> lhs = lhs;
}

void Ampersand::setRHS(Base* rhs) {
	this-> rhs = rhs;
}

bool Ampersand::execute() {
	if(lhs->execute()) {
		rhs->execute();
	}	
}

#endif
