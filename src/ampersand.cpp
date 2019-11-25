#include "ampersand.h"

bool Ampersand::execute() {
    if (this->lhs->execute() == true) {
        return this->rhs->execute();
    }
    else {
        return false;
    }
}
