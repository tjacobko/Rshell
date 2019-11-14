#ifndef __ECHO_CPP__
#define __ECHO_CPP__

#include "Echo.h"

Echo::Echo() {
	this->size = 2;
	std::string echo = "echo";
	this->argList[0] = (char*)echo.c_str();
	this->argList[1] = NULL;
}

Echo::Echo(std::string args) {
	std::string word = " ";
	std::string echo = "echo";
	int count;
	
	for(int i = 0;i < args.length(); ++i) {
		if(args.at(i) == ' ') {
			count++;
		}
	}
	this->size = count;
	
	this->argList[0] = (char*)echo.c_str();
	int arrCount = 1;
	for(int i = 0; i < args.length(); ++i) {
		if(args.at(i) != ' ') {
			word += args.at(i);
		}
		else {
			this->argList[arrCount] = (char*)word.c_str();
			word = " ";
		}
	}
	this->argList[arrCount] = (char*)word.c_str();
	this->argList[arrCount+1] = NULL;
}

Echo::~Echo() {
	delete[] this->argList;
	delete this;
	//std::cout << "Destructor called" << std::endl;
}
/*
bool Echo::getStatus() {
	return this->status;
}

bool Echo::getRun() {
	return this->run;
}

void Echo::setRun(bool newRun) {
	this->run = newRun;
	return;
}
*/
void Echo::execute() {
	pid_t pid = fork();
	
	if(pid < 0) {
		this->status = false;
		perror("fork() error");
		return;
	}
	if(pid == 0) {
		if(execvp(this->argList[0], this->argList) == -1) {
			this->status = false;
			perror("ls failed execute");
			return;
		}
	}
	else {
		if(wait(NULL) == -1) {
			this->status = false;
			perror("wait error");
			return;
		}
		this->status = true;
		return;
	}
}

#endif

