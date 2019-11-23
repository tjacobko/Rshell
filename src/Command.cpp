#include "Command.h"

void Command::execute() {
    this->sizeArr = 2;
    for (int i = 0; i < this->args.length(); i++) {
        if (this->args.at(i) == ' ') {
            this->sizeArr++;
        }
    }
    
    char cstr[this->args.length()+1];
    std::strcpy(cstr, this->args.c_str());
    char* pch;
    char* argList[this->sizeArr];
    
    pch = std::strtok(cstr, " ");
    int i = 0;
    while (pch != NULL) {
        argList[i] = pch;
        i++;
        pch = std::strtok(NULL, " ");
    }
    argList[i] = NULL;
    
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork() error");
    }
    if (pid == 0) {
        if (execvp(argList[0], argList) == -1) {
            perror("ls failed execute");
        }
    }
    else {
        if (wait(NULL) == -1) {
            perror("wait error");
        }
        return;
    }
}
