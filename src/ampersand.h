#ifndef __AMPERSAND_H__
#define __AMPERSAND_H__

#include "Base.h"

class Ampersand : public Base {
	public:
		Ampersand();
		Ampersand(Base* lhs, Base* rhs);
		~Ampersand();
		virtual bool getStatus() {};
		virtual bool getRun() {};
		virtual void setRun(bool) {};

		virtual void execute();
	private:
		Base* lhs;
		Base* rhs;
};
#endif
