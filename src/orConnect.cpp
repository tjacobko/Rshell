#include "orConnect.h"

bool OrConnector::execute() {
    if (this->lhs->execute() == false) {
        return this->rhs->execute();
    }
    else {
        return false;
    }
}
