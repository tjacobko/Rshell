#ifndef __COMMAND_H__
#define __COMMAND_H__

#include "Base.h"

class Command : public Base {
    public:
        Command(std::string args) : Base() {this->args = args;}
        virtual void execute();
    private:
        std::string args;
        int sizeArr;
};

#endif
