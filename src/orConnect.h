#ifndef __ORCONNECTOR_H__
#define __ORCONNECTOR_H__

#include "Base.h"

class OrConnector : public Base {
    public:
        OrConnector(Base* lhs, Base* rhs) : Base() {this->lhs = lhs; this->rhs = rhs;}
        virtual bool execute();
    private:
        Base* lhs = nullptr;
        Base* rhs = nullptr;
};

#endif
