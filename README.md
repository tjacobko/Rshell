# CS 100 RShell
## Fall 2019
### Timothy Jacob Ko (861286868) and Ethan Nguyen (861283248)

# Introduction:
This program is a basic command shell called rshell. This project aims to further our understanding of working in a group environment and utilizing methods such as SCRUM, AGILE, WATERFALL, etc. We will implement composite patterns and strategy patterns to structure programs.

# Diagram:

# Class Descriptions:
**Base Class**(To be named...): Our Base class is a class that can execute commands from a reader. This base class also has an aggregation relationship with a **Reader** class. The reader class takes in members and searches for the appropriate classes. It also has to be able to read in inclusion/exclusion values such as *;*, *&&* and *||*.

A class group inherits from our base class. They all inherit the **virtual void** execute() function, which should execute any commands that are given by the user. They may also inherit the output() function, which outputs the command that was read in by the system. We have some ideas about the classes that inherit the base class. 

The **Git** class has functions such as add, push, pull, commit, etc. It may have to share some functions of other classes because the class interacts with the whole root directory. 

Another class we have is the **Traversal** class which moves the user across the directory when it is called. 

# Prototypes/Research:
Because we are unfamiliar with the three functions: waitpid(), execvp(), and fork(). We will attempt to implement and run each function by itself in order to get a grasp on the functionality of them. Additionally, we will test all three functions together to test and run the command lines we will use in Assignment 2.
# Development and Testing Roadmap:
_To Do_ : 
  * Base Class #1
       * ```virtual void execute() = 0;```
  * Reader Class #2
  * Git Class #3
       * Add, push, commit, clone, etc . . .
  * Traversal Class #4
       * cd, ls, search, etc . . .
