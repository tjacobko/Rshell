#ifndef __GIT_H__
#define __GIT_H__

#include "Base.h"
#include <vector>

class Git : public Base {
	public:
		Git();
		~Git();
		Git(std::string args);
		virtual void execute();
		
		virtual bool getStatus();
		virtual bool getRun();
		virtual void setRun(bool);
	private:
		int size;
		char** argList = new char*[size];
		bool status = false;
		bool run = false;
};

#endif
