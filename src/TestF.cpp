#include "TestF.h"
#include <string>

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>

TestF::TestF(std::string args) : Base() {
    if(args.at(0) == '-') {
        this->flag = args.at(0);
        this->flag += args.at(1);
	this->path = args.substr(2, args.length()-2);
    }	
	else {
		this->path = args;
	}
    //std::cout << this->flag << std::endl;
    
    //std::cout << this->path << std::endl;
}

bool TestF::execute() {
    struct stat buf;
    int temp = 0;
   
	//std::cout << this->path << std::endl;
 	
    temp = stat(this->path.c_str(), &buf);
    //std::cout << temp << std::endl;
    if(this->flag == "-e" || this->flag == "") {
        if(temp == 0){
            std::cout << "(True)" << std::endl;
            return true;
        }
        else if(temp == -1) {
            std::cout << "(False)" << std::endl;
            return false;
        }
    }
    else if(this->flag == "-f"){
        if(S_ISREG(buf.st_mode) != 0) {
            std::cout << "(True)" << std::endl;
            return true;
        }
        else {
            std::cout << "(False)" << std::endl;
            return false;
        }
    }
    else if(this->flag == "-d") {
        if(S_ISDIR(buf.st_mode) != 0) {
            std::cout << "(True)" << std::endl;
            return true;
        }
        else {
            std::cout << "(False)" << std::endl;
            return false;
        }
    }
    else {
        std::cout << "Flag failed" << std::endl;
        return false;
    }
}
