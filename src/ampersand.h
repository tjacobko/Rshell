#ifndef __AMPERSAND_H__
#define __AMPERSAND_H__

#include "Base.h"

class Ampersand : public Base {
    public:
        Ampersand(Base* lhs, Base* rhs) : Base() {this->lhs = lhs; this->rhs = rhs;}
        virtual bool execute();
    private:
        Base* lhs = nullptr;
        Base* rhs = nullptr;
};

#endif
