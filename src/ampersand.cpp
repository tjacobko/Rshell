#ifndef __AMPERSAND_CPP__
#define __AMPERSAND_CPP__

#include "ampersand.h"
#include "Connector.h"

Ampersand::Ampersand() : Connector() {}
Ampersand::Ampersand(Base* lhs, Base* rhs) : Connector(lhs, rhs) {}

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

#define
