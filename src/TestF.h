#ifndef __TESTF_H__
#define __TESTF_H__

#include "Base.h"

class TestF : public Base {
    public:
        TestF(std::string args);
        virtual bool execute();
    private:
        std::string flag = "";
        std::string path = "";
};

#endif
