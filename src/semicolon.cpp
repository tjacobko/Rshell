#ifndef __SEMICOLON_CPP__
#define __SEMICOLON_CPP__

#include "Semicolon.h"
#include "Connector.h"

Semicolon::Semicolon() : Connector() {}
Semicolon::Semicolon(Base* lhs, Base* rhs) : Connector(lhs, rhs) {}

bool Semicolon::execute() {
	lhs->execute();
	if(rhs->execute()) {
		return true;
	}
	return false;
}

#endif
