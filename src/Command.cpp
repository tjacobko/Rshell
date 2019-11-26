#ifndef __COMMAND_CPP__
#define __COMMAND_CPP__

#include "Command.h"

bool Command::execute(){
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
    
    int fd[2];
    pipe(fd);
    int n = 0;
    
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork() error");
    }
    if (pid == 0) {
        close(fd[0]);
        if (execvp(argList[0], argList) < 0) {
            perror("failed execute");
            n = 1;
            write(fd[1], &n, 1);
        }
        exit(1);
    }
    else {
        if (waitpid(pid, NULL, 0) == -1) {
            perror("wait error");
        }
        else {
            close(fd[1]);
            read(fd[0], &n, 1);
            if (n == 1) {
                return false;
            }
            else {
                return true;
            }
        }
    }
}

#endif
