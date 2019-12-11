#ifndef __PIPE_CPP__
#define __PIPE_CPP__

#include "Pipe.h"
#include "unistd.h"

bool Pipe::execute() {
    int pipefd[2];
    pid_t cpid;
    
    pipe(pipefd);

    cpid = fork();
    if (cpid == 0) {    // Child for left cmd
        close(pipefd[0]);   // Close unused read end
        dup2(pipefd[1], STDOUT_FILENO);     // Makes output go to pipe
        close(pipefd[0]);
        close(pipefd[1]);
        this->lhs->execute();
        exit(1);
    }
    else {
        if (waitpid(cpid, NULL, 0) == -1) {
            perror("wait error");
        }
        close(pipefd[1]);   // Close unused write end
        dup2(pipefd[0], STDIN_FILENO);  // Get input from pipe
        close(pipefd[0]);
        close(pipefd[1]);
        bool ret = this->rhs->execute();
        return ret;
    }
}

#endif
