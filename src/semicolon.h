#ifndef __SEMICOLON_H__
#define __SEMICOLON_H__

#include "Base.h"

class Semicolon : public Base {
    public:
        Semicolon(Base* lhs, Base* rhs) : Base() {this->lhs = lhs; this->rhs = rhs;}
        virtual bool execute();
    private:
        Base* lhs = nullptr;
        Base* rhs = nullptr;
};

#endif
