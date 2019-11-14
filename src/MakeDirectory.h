#ifndef __MAKEDIRECTORY_H__
#define __MAKEDIRECTORY_H__

#include "Base.h"

class MkDir : public Base {
	public:
		MkDir();
		MkDir(std::string args);
		~MkDir();
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
