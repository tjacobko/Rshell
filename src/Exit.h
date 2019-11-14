#ifndef __EXIT_H__
#define __EXIT_H__

#include "Base.h"

class Exit : public Base {
	public:
		Exit();
		virtual bool getStatus();
		virtual bool getRun();
		virtual void setRun(bool);
		virtual void execute();
	private:
		bool status = false;
		bool run = false;
};
#endif
