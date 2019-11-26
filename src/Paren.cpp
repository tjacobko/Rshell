#include "Paren.h"

Paren::Paren(Base* element) : Base() {
	this->element = element;
}

bool Paren::execute() {
	return this->element->execute();
}
