#ifndef __TEST_H__
#define __TEST_H__

#include "Base.h"

class Test : public Base {
    public:
        Test(std::string args);
        virtual bool execute();
    private:
        std::string flag = "";
        std::string path = "";
};

#endif
