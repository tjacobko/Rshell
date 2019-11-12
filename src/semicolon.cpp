#ifndef __SEMICOLON_CPP__
#define __SEMICOLON_CPP__

#include "semicolon.h"

Semicolon::Semicolon() : Base() {
	this->lhs = nullptr;
	this->rhs = nullptr;
}

Semicolon::Semicolon(Base* lhs, Base* rhs) : Base() {
	this->lhs = lhs;
	this->rhs = rhs;
}

bool Semicolon::execute() {
	lhs->execute();
	if(rhs->execute()) {
		return true;
	}
	return false;
}

#endif
