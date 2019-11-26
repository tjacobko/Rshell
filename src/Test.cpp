#include "Test.h"
#include <string>

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

Test::Test(std::string args) {
    if(args.at(0) == '-') {
        this->flag = args.at(0);
        this->flag += args.at(1);
    }
    std::cout << this->flag << std::endl;
    args.erase(args.begin(), args.begin()+2);
    this->path = args;
    std::cout << this->path << std::endl;
}

bool Test::execute() {
    struct stat buffer;
    int temp = 0;
    
    temp = stat(this->path.c_str(), &buffer);
    std::cout << temp << std::endl;
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
        if(S_ISREG(buffer.st_mode) != 0) {
            std::cout << "(True)" << std::endl;
            return true;
        }
        else {
            std::cout << "(False)" << std::endl;
            return false;
        }
    }
    else if(this->flag == "-d") {
        if(S_ISDIR(buffer.st_mode) != 0) {
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
