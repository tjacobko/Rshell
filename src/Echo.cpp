#ifndef __ECHO_CPP__
#define __ECHO_CPP__

#include "Echo.h"

Echo::Echo() {
	std::string echo = "echo";
	this->argList.push_back((char*)echo.c_str());
	this->argList.push_back(NULL);
}

Echo::Echo(std::string args) {
	std::string word;
	char* temp = nullptr;

	std::string echo = "echo";
	this->argList.push_back((char*)echo.c_str());
	for(unsigned i = 0; i < args.length(); ++i) {
		if(args.at(i) != ' ') {
			word += args.at(i);
		}
		else {
			temp = (char*)word.c_str();
			i++;
			this->argList.push_back(temp);
		}
	}
	temp = (char*)word.c_str();
	this->argList.push_back(temp);
	this->argList.push_back(NULL);
}

bool Echo::execute() {
	char* permList[argList.size()];
	for(unsigned i = 0; i < argList.size(); i++) {
		permList[i] = argList.at(i);
	}
	
	pid_t pid = fork();
	
	if(pid == 0) {
		if(execvp(permList[0], permList) == -1) {
			perror("echo failed execute");
		}
		return false;
	}
	if(pid > 0) {
		if(wait(0) == -1){
			perror("wait error");
		}
		return true;
	}
}

#endif

