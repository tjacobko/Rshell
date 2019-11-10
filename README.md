# CS 100 RShell
## Fall 2019
### Timothy Jacob Ko (861286868) and Ethan Nguyen (861283248)

# Introduction:
This program is a basic command shell called rshell. We will implement a composite pattern to create a working command line, which will be capable of reading in user input through a reader and decipher the correct command based on what is read by choosing the correct class.

# Diagram:
![OMT](https://raw.githubusercontent.com/cs100/assignment-caffeineorfeed/master/images/Rshell%20OMT.png?token=ANL74FLJRHRBTEVHRIDV37K52HE7K)

# Class Descriptions:
**Base Class**(To be named...): Our Base class is a class that can execute commands from a reader. This base class also has an aggregation relationship with a **Reader** class. The reader class takes in members and searches for the appropriate classes. It also has to be able to read in inclusion/exclusion values such as *;*, *&&* and *||*.

A class group inherits from our base class. They all inherit the **virtual void** execute() function, which should execute any commands that are given by the user. They may also inherit the output() function, which outputs the command that was read in by the system. We have some ideas about the classes that inherit the base class. 

The **Git** class has functions such as add, push, pull, commit, etc. It may have to share some functions of other classes because the class interacts with the whole root directory. 

Another class we have is the **Traversal** class which moves the user across the directory when it is called. 

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
  * Reader Class #2(https://github.com/cs100/assignment-caffeineorfeed/issues/2)
  * Git Class #3 (https://github.com/cs100/assignment-caffeineorfeed/issues/3)
       * Add, push, commit, clone, etc . . .
  * Traversal Class #4 (https://github.com/cs100/assignment-caffeineorfeed/issues/4)
       * cd, ls, search, etc . . .

  * Unit Testing for each of the classes #5 (https://github.com/cs100/assignment-caffeineorfeed/issues/5)
        * Make sure each class can work with each other.
