#include "Sequence.h"
#include <iostream>

std::ostream& operator<<(std::ostream& out, const Sequence&) {
    return out;
}

std::istream& operator>>(std::istream& in, Sequence&) {
    return in;
}
