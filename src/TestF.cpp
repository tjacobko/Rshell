#include "TestF.h"
#include <string>

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

TestF::TestF(std::string args) : Base() {
    std::string temp = args;
    if(temp.at(0) == '-') {
        this->flag = temp.at(0);
        this->flag += temp.at(1);
	this->path = temp.substr(3, temp.length()-3);
	std::cout << "Flag: " << this->flag << std::endl;
	std::cout << "Path: " << this->path << std::endl;
    }	
    else {
	this->path = temp;
	std::cout << "Flag: empty" << std::endl;
	std::cout << "Path: " << this->path << std::endl;
    }
}

bool TestF::execute() {
    struct stat buf;
    int temp = 0;
    
    temp = stat(this->path.c_str(), &buf);
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
