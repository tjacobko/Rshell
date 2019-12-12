#ifndef __APPEND_H__
#define __APPEND_H__

#include "Base.h"

class Append : public Base {
        public:
                Append(Base* lhs, std::string file) : Base() {this->lhs = lhs; this->file = file;}
                virtual bool execute();
        private:
                Base* lhs = nullptr;
		std::string file;
};

#endif
