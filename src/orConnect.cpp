#include "orConnect.h"

bool OrConnector::execute() {
    if(!this->lhs->execute()) {
       return this->rhs->execute();
    }
    else {
        return true;
    }
}
