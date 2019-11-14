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
		
		bool getStatus() {
			return this->status;
		}
		bool getRun() {
			return this->run;
		}
		void setRun(bool newRun) {
			this->run = newRun;
			return;
		}
	protected:
		bool status;
		bool run;	
};

Base::~Base() {
	std::cout << "Base Destructor called???" << std::endl;
}

#endif
