#include "Pipe.h"

bool Pipe::execute() {
    int pipefd[2];
    pid_t cpid;
    
    pipe(pipefd);
    
    cpid = fork();
    if (cpid == 0) {
        close(pipefd[0]);
        dup2(pipefd[1], STDOUT_FILENO);
        this->lhs->execute();
        exit(1);
    }
    cpid = fork();
    if (cpid == 0) {
        close(pipefd[1]);
        dup2(pipefd[0], STDIN_FILENO);
        this->rhs->execute();
        exit(1);
    }
    close(pipefd[0]);
    close(pipefd[1]);
    
    waitpid(-1, NULL, 0);
    waitpid(-1, NULL, 0);
    
    return true;
}
