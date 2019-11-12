#ifndef __AMPERSAND_CPP__
#define __AMPERSAND_CPP__

#include "ampersand.h"

Ampersand::Ampersand() : Base() {}

Ampersand::Ampersand(Base* lhs, Base* rhs) : Base() {
	this-> lhs = lhs;
	this-> rhs = rhs;
}

bool Ampersand::execute() {
	if(lhs->execute()) {
		if(rhs->execute()) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}	
}

#endif
