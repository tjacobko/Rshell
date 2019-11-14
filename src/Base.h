#ifndef __BASE_H__
#define __BASE_H__

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

class Base {
	public:
		Base() {};
		virtual ~Base() = 0;
		virtual void execute() = 0;
		
		virtual bool getStatus() = 0;
		virtual bool getRun() = 0;
		virtual void setRun(bool newRun) = 0;
	/*protected:
		bool status = false;
		bool run = false;*/
};

Base::~Base() {
	std::cout << "Base Destructor called???" << std::endl;
}

#endif
