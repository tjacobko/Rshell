#ifndef __SEMICOLON_H__
#define __SEMICOLON_H__

#include "Connector.h"

class Semicolon : public Connector {
	public:
		Semicolon();
		Semicolon(Base* lhs, Base* rhs);

		virtual bool execute();
};
#endif
