#ifndef __GIT_CPP__
#define __GIT_CPP__

#include "Git.h"
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <string.h>

Git::Git() {
	this->size = 2;	
	std::string git = "git";
	this->argList[0] = (char*)git.c_str();
	this->argList[1] = NULL;
}

Git::Git(std::string args) {
	std::string word;
	std::string git = "git";
	int count = 3;
	
	for(int i = 0;i < args.length(); ++i) {
		if(args.at(i) == ' ') {
			count++;
		}
	}
	this->size = count;

	this->argList[0] = (char*)git.c_str();
	int arrCount = 1;
	for(int i = 0;i < args.length(); ++i) {
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

Git::~Git() {
	delete[] this->argList;
	delete this;
	//std::cout << "Destructor called" << std::endl;
}

bool Git::getStatus() {
	return this->status;
}

bool Git::getRun() {
	return this->run;
}

void Git::setRun(bool newRun) {
	this->run = newRun;
	return;
}

void Git::execute() {
	pid_t pid = fork();
	
	if(pid < 0) {
		this->status = false;
		perror("fork() error");
		return;
	}
	if(pid == 0) {
		if(execvp(this->argList[0], this->argList) == -1) {
			this->status = false;
			perror("git failed execute");
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
