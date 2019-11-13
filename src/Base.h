#ifndef __BASE_H__
#define __BASE_H__

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

class Base {
	public:
		Base() {};
		virtual bool execute() = 0;
};

#endif
