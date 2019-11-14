#ifndef __ORCONNECT_H__
#define __ORCONNECT_H__

#include "Base.h"

class orConnector : public Base {
	public:
		orConnector();
		orConnector(Base* lhs, Base* rhs);
		~orConnector();
		
		bool getStatus() {}
		bool getRun() {}
		void setRun(bool newRun) {}

		virtual void execute();
	private:
		Base* lhs;
		Base* rhs;
		
};

#endif
