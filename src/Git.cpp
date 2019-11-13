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
	pid_t pid;
	int size = argsList.size();
	
	char* permList[size];
	for(unsigned int i = 0; i < size; ++i) {
		permList[i] = argsList.at(i);
	}
	
	//char* permList[] = {argsArr};
	//push vector elements into array
	/*
	for(unsigned int i = 0; i < size; ++i){
		permList[i] = argsList[i];
	}
	*/
	if((pid = fork()) == -1) {
		perror("fork() error");
		return false;
	}

	else if(pid == 0) {
		execvp("git", permList);
		return true;
	}
}

#endif
