#ifndef __WRITE_H__
#define __WRITE_H__

#include "Base.h"

class Write : public Base {
        public:
                Write(Base* lhs, std::string file) : Base() {this->lhs = lhs; this->file = file;}
                virtual bool execute();
        private:
                Base* lhs = nullptr;
		std::string file;
};

#endif
