# CS 100 RShell
## Fall 2019
### Timothy Jacob Ko (861286868) and Ethan Nguyen (861283248)

# Introduction:
This program is a basic command shell called rshell. We will implement a composite pattern to create a working command line, which will be capable of reading in user input through a reader and decipher the correct command based on what is read by choosing the correct class.

# Diagram:
![OMT](https://raw.githubusercontent.com/cs100/assignment-caffeineorfeed/master/images/Rshell%20OMT%20(3).png?token=ANL74FOELJN7WNWP7I3KSP257MND2)

# Class Descriptions:
**Base Class** : The Base class is the class that all other classes derive from. We have a virtual destructor for our Base class. We use this destructor to call the derived destructor, then the inherited destructor.
The class group is our **Connectors**, which link the command lines between each other. They all use the virtual void execute() function of the Base class in order to perform their own transformations of the function. Additionally, we have the group of **Command** classes which utilize the Base class's virtual void execute() function to perform the intended command lines. These classes take advantage of the research topics we learned, i.e., waitpid(), execvp(), and fork() in order to work correctly. Our **Test** class will implement the bash test command for test -e, -f, and -d. 

# Prototypes/Research:
Because we are unfamiliar with the three functions: waitpid(), execvp(), and fork(). We will attempt to implement and run each function by itself in order to get a grasp on the functionality of them. Additionally, we will test all three functions together to test and run the command lines we will use.

**fork()** : is a system call when creating new processes. A child process and a parent process. It does not have any parameters and return an integer. This integer tells us three things:
   1. A **negative** value shows the creation of a child process was unsuccessful.
   2. A **zero** value shows that it returned to a newly created child process.
   3. A **positive** value shows that it returned to a parent or user.
   
**waitpid()** : is a system call that blocks the calling process until one of the child processes exit *or* when a signal is received.

**execvp()** : is a system call that creates a child process that **does not** run the same process that the parent does. It can also allow a process to run any program files, which include a binary executable or a shell script.
*Example code courtesy of GeeksForGeeks*
```
int execvp (const char *file, char *const argv[]);
```
 *file* represents the file name associated to the file being executed.
 *argv* is a null-terminated array of character pointers.
 
 ***pipe()*** : is a connection between two processes. In our case we will use piping in order to get the data from our child process to make our command execute function correctly.
 
 ***Test Commands*** : these commands are already integrated in bash. They test a multitude of commands, but in our case we only need to worry about the **-e, -f,** and **-d** flags. The tests will return either a true or false boolean.
Alongside the test commands, we need to utilize macros in order to run these test commands. We will use ***S_ISREG*** and ***S_ISDIR*** to run the **-f** and **-d** flags. These macros will interpret the values of the stat struct and will evaluate true or false based on if the path is a regular file or regular directory.
 
 ***dup()*** : what this command aims to do is to copy the file descriptor, using the lowest-numbered *unused* file descriptor. If it works, we may use the old and new file descriptor interchangeably.
 
 ***dup2()*** : it does the same job as dup() but instead of using the lowest-numbered unused file descriptor, is uses the file descriptor specified in __newfd__ .
 
 
 
# Development and Testing Roadmap:
DONE : 
  * Piping Class ( #13 ) 
      * This class is responsible for *piping* the arguments. It is considered a connector class and will act as such.
         https://github.com/cs100/assignment-caffeineorfeed/issues/13
  * Input and Output Implementation ( #14 ) and ( #15 )
      * We need a way to make the class work for ( > ) as well as ( >> ) and ( < ).
         https://github.com/cs100/assignment-caffeineorfeed/issues/14
         https://github.com/cs100/assignment-caffeineorfeed/issues/15
  * Unit and Integration Tests ( #16 )
      * Testing for the new enhancements we made for our rshell.
      https://github.com/cs100/assignment-caffeineorfeed/issues/16
