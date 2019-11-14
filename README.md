# CS 100 RShell
## Fall 2019
### Timothy Jacob Ko (861286868) and Ethan Nguyen (861283248)

# Introduction:
This program is a basic command shell called rshell. We will implement a composite pattern to create a working command line, which will be capable of reading in user input through a reader and decipher the correct command based on what is read by choosing the correct class.

# Diagram:
![OMT](https://raw.githubusercontent.com/cs100/assignment-caffeineorfeed/master/images/Rshell%20OMT%20(1).png?token=ANL74FJDUSL2NJHQRT6XJWS52XVPQ)

# Class Descriptions:
**Base Class** : The Base class is the class that all other classes derive from. We have a virtual destructor for our Base class. We use this destructor to call the derived destructor, then the inherited destructor.
The class group is our **Connectors**, which link the command lines between each other. They all use the virtual void execute() function of the Base class in order to perform their own transformations of the function. Additionally, we have the group of **Command line** classes which utilize the Base class's virtual void execute() function to perform the intended command lines. These classes take advantage of the research topics we learned, i.e., waitpid(), execvp(), and fork() in order to work correctly.
# Prototypes/Research:
Because we are unfamiliar with the three functions: waitpid(), execvp(), and fork(). We will attempt to implement and run each function by itself in order to get a grasp on the functionality of them. Additionally, we will test all three functions together to test and run the command lines we will use in Assignment 2.

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
 
# Development and Testing Roadmap:
_To Do_ : 
  * Base Class #1(https://github.com/cs100/assignment-caffeineorfeed/issues/1)
       * ```virtual void execute() = 0;```
  * Command Class #2(https://github.com/cs100/assignment-caffeineorfeed/issues/2)
  * Connector Class #3 (https://github.com/cs100/assignment-caffeineorfeed/issues/3)
       * Add, push, commit, clone, etc . . .
  * Unit Testing for each of the classes #5 (https://github.com/cs100/assignment-caffeineorfeed/issues/5)
        * Make sure each class can work with each other.
  * Parsing Function (most likely in the main.cpp) #6 (https://github.com/cs100/assignment-caffeineorfeed/issues/6)
        * This needs to be able to parse a string for sorting.
  * Integration Testing(script) for our classes #7 (https://github.com/cs100/assignment-caffeineorfeed/issues/7)
         * Integration testing by using shell scripts
  
