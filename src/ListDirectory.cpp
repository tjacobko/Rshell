#ifndef __LISTDIRECTORY_CPP__
#define __LISTDIRECTORY_CPP__

#include "ListDirectory.h"

List::List() : Base() {
	this->size = 2;
	std::string ls = "ls";
	this->argList[0] = (char*)ls.c_str();
	this->argList[1] = NULL;
}

List::List(std::string args) : Base() {
	std::string word = "";
	std::string ls = "ls";
	int count = 3;

	for (int i = 0; i < args.length(); i++) {
		if (args.at(i) == ' ') {
			count++;
		}
	}
	this->size = count;
	
	this->argList[0] = (char*)ls.c_str();
	int arrCount = 1;
	for (int i = 0; i < args.length(); i++) {
		if (args.at(i) != ' ') {
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

List::~List() {
	delete[] this->argList;
	delete this;
	std::cout << "Destructor called" << std::endl;
}

void List::execute() {
	pid_t pid = fork();
	
	if (pid < 0) {
		this->status = false;
		perror("fork() error");
		return;
	}
	if (pid == 0) { // Child processes
		if (execvp(this->argList[0], this->argList) == -1) {
			this->status = false;
			perror("ls failed execute");
			return;
		}
		//exit(0);
	}
	else { // Parent processes
		if (wait(NULL) == -1) {
			this->status = false;
			perror("wait error");
			return;
		}
		//delete[] argList;
		this->status = true;
		return;
	}
}

#endif
