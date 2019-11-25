#include "semicolon.h"

bool Semicolon::execute() {
    this->lhs->execute();
    return this->rhs->execute();
}
