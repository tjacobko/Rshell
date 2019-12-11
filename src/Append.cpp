#ifndef __APPEND_CPP__
#define __APPEND_CPP__

#include "Append.h"

#include "fcntl.h" //open()
#include "sys/stat.h" //for open()

Append::Append(Base* lhs, Base* rhs) : Base(lhs,rhs) {}

bool Append::execute() {
	string outputFile = //read file from the rhs
	open(outputFile.c_str(), O_WRONLY | O_APPEND | O_CREAT, S_IRSUR | S_IRGRP | S_IWUSR);
		/*
 			This should append the output of a command line to a file
				
  			open(...) establishes connection between file and file descriptor
 			O_WRONLY - open for write only
			O_APPEND - file offset shall be set to the end of the file prior to each write
  			O_CREAT - if file exists, no nothing.
				else, file is created
  			S_IRSUR - read permission, owner
			s_IRGRP - write permission, group
			S_IWUSR - write permission, owner
  		*/
	return lhs->execute();
}

#endif
