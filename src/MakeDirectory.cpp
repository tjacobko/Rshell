#ifndef __MAKEDIRECTORY_CPP__
#define __MAKEDIRECTORY_CPP__

#include "MakeDirectory.h"

MkDir::MkDir() {
	this->size = 2;
	std::string mkdir = "mkdir";
	this->argList[0] = (char*)mkdir.c_str();
	this->argList[1] = NULL;
}

MkDir::MkDir(std::string args) {
	std::string word = "";
	std::string mkdir = "mkdir";
	int count = 3;
	
	for(int i = 0;i < args.length();++i) {
		if(args.at(i) == ' ') {
			count++;
		}
	}	
	this->size = count;

	this->argList[0] = (char*)mkdir.c_str();
	int arrCount = 1;
	for(int i = 0;i < args.length();++i) {
		if(args.at(i) != ' ') {
			word += args.at(i);
		}
		else {
			this->argList[arrCount] = (char*)word.c_str();
			word = "";
		}
	}
	this->argList[arrCount] = (char*)word.c_str();
	this->argList[arrCount+1] = NULL;
	
}

MkDir::~MkDir() {
	delete[] this->argList;
	delete this;
	//std::cout << "Destructor called" << std::endl;
}

bool MkDir::getStatus() {
        return this->status;
}

bool MkDir::getRun() {
        return this->run;
}

void MkDir::setRun(bool newRun) {
        this->run = newRun;
        return;
}

void MkDir::execute() {
	pid_t pid = fork();
	
	if(pid < 0) {
		this->status = false;
		perror("fork() error");
		return;
	}
	if(pid == 0) {
		if(execvp(this->argList[0],this->argList) == -1) {
			this->status = false;
			perror("MkDir failed to execute");
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
