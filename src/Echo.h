#ifndef __ECHO_H__
#define __ECHO_H__

#include "Base.h"

class Echo : public Base {
	public:
		Echo();
		~Echo();
		Echo(std::string args);
		virtual void execute();
		/*
		bool getStatus();
		bool getRun();
		void setRun(bool);
		*/
	private:
		int size;
		char** argList = new char*[size];
		//bool run;
		//bool status;
};

#endif
