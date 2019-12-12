#include "Append.h"
#include "Base.h"

#include "fcntl.h"
#include "sys/stat.h"

bool Append::execute() {
    char cstr[this->file.length()+1];
    std::strcpy(cstr, this->file.c_str());

    int pipefd[2];
    pid_t cpid;
    
    pipe(pipefd);

    cpid = fork();
    if (cpid == 0) {
        close(pipefd[0]);
        int fd = open(cstr, O_WRONLY | O_APPEND | O_CREAT, S_IRUSR | S_IRGRP | S_IWUSR);
	if (fd < 0) {
	    perror("error opening file");
	    return false;
	}
        dup2(fd, STDOUT_FILENO);
        close(pipefd[0]);
        close(pipefd[1]);
        this->lhs->execute();
        close(fd);
        exit(1);
    }
    else {
        if (waitpid(cpid, NULL, 0) == -1) {
            perror("wait error");
	    return false;
        }
        close(pipefd[1]);
        close(pipefd[0]);
        return true;
    }
}
