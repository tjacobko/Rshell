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

Git::Git() {}

Git::Git(std::string args) {
	std::string word;
	const char* converted = nullptr;
	char* temp;
	int j = 0;
	
	for(unsigned i = 0; i < args.length(); ++i) {
		//get word before whitespace
		//turn word to char*
		//argList[i] = word
		//++i
		if(args[i] != ' ') {
			word += args[i];
		}
		
		if(args[i] == ' ') {
			++i;	
			converted = word.c_str();
			strcpy(temp, converted);
			argsList.at(j) = temp;
			++j;
		}
		
	}
	converted = word.c_str();
	strcpy(temp, converted);
	this->argsList.at(j) = temp;
	this->argsList.at(j) = NULL;
}

bool Git::execute() {
	char* permList[argsList.size()];
	for(unsigned int i = 0; i < argsList.size(); ++i) {
		permList[i] = argsList.at(i);
	}
	
	pid_t pid = fork();
	
	if(pid == 0) {
		if(execvp(permList[0], permList) == -1) {
			perror("execute failed execute");
		}
		return false;
	}

	if(pid > 0) {
		if(wait(0) == -1) {
			perror("wait error");
		}
		return true;
	}
}

#endif
