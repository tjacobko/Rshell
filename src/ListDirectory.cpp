#ifndef __LISTDIRECTORY_CPP__
#define __LISTDIRECTORY_CPP__

#include "ListDirectory.h"

List::List() {}

List::List(std::string args) {
	std::string word;
	const char* charWord = nullptr;
	char* temp = nullptr;
	/*int pos = 0;
	int size = 1;
	for (int i = 0; i < args.length(); i++) {
		if (args.at(i) == ' ') {
			size++;
		}
	}
	this->argList[size];*/

	for (int i = 0; i < args.length(); i++) {
		if (args.at(i) != ' ') {
			word += args.at(i);
		}
		else {
			charWord = word.c_str();
			strcpy(temp, charWord);
			i++;
			this->argList.push_back(temp);
		}
	}
	charWord = word.c_str();
	strcpy(temp, charWord);
	this->argList.push_back(temp);
	this->argList.push_back(NULL);

	std::cout << argList.size() << std::endl;
}

bool List::execute() {
	pid_t pid;
	char* permList[argList.size()];
	for (int i = 0; i < argList.size(); i++) {
		permList[i] = argList.at(i);
	}
	
	if ((pid = fork()) == -1) {
		perror("fork() error");
		return false;
	}
	else if (pid == 0) {
		execvp("ls", permList);
		return true;
	}
}

#endif
