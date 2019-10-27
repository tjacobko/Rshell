#include <stdio.h>
#include <unistd.h> //std library for fork()
#include <sys/types.h>
#include <sys/wait.h> //library for wait()
#include <iostream>

//Testing three functions:
//	waitpid(), execvp() and fork()
int main() {
	//Testing wait() and fork()
	//This creates 4 processes(because of the 2 forks)
	//Will have: 1 parent, 2 child, 1 grandchild.
	pid_t p1 = fork();	//Two Processes created
	pid_t p2 = fork();	//Two Processes created

	if(p1 > 0 && p2 > 0) {
		wait(NULL); //First wait, Pauses p1
		wait(NULL); //Second wait
		std::cout << "Parent Process ends...\n";
	}
	

	else if(p1 == 0 && p2 > 0) {
		//Stops processes. 2 seconds.
		sleep(2);
		wait(NULL);
		std::cout << "Child 1 ends...\n";
	}

	else if(p1 > 0 && p2 == 0) {
		sleep(1);
		std::cout << "Child 2 ends...\n";
	}

	else {
		std::cout << "GrandChild ends...\n";
	}
	//Should output in order: Granchild->Child2->Child1->Parent...
return 0;
}
