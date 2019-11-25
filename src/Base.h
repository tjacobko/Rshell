#ifndef __BASE_H__
#define __BASE_H__

#include <iostream>
#include <string>
#include <string.h>
#include <cstring>
#include <vector>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

class Base {
	public:
		Base() {};
		virtual bool execute() = 0;
};

#endif
