#ifndef __LISTDIRECTORY_CPP__
#define __LISTDIRECTORY_CPP__

#include "ListDirectory.h"

List::List() {
	std::string ls = "ls";
	this->argList.push_back((char*)ls.c_str());
	this->argList.push_back(NULL);
}

List::List(std::string args) {
	std::string word;
	char* temp = nullptr;
		
	std::string ls = "ls";
	this->argList.push_back((char*)ls.c_str());
	for (int i = 0; i < args.length(); i++) {
		if (args.at(i) != ' ') {
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

bool List::execute() {
	char* permList[argList.size()];
        for (int i = 0; i < argList.size(); i++) {
                permList[i] = argList.at(i);
        }

	// Need fork and wait to do more processes after execvp
	/*pid_t pid = fork();

	if (pid == )*/
	
	if (execvp(permList[0], permList) == -1) {
		perror("exec");
	}
}

#endif
