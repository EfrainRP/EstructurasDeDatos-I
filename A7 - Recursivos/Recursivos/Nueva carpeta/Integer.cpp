#include "Integer.h"

using namespace std;

Integer::Integer() {}

Integer::Integer(const Integer& i) : integer(i.integer) {}

Integer& Integer::operator=(const Integer& i) {
    integer = i.integer;
    return *this;
}

void Integer::setInteger(const long long int& i) {
    integer = i;
}

long long int Integer::getInteger() const {
    return integer;
}

string Integer::toString() const {
    string result;
    result += to_string(integer);
    return result;
}

bool Integer::operator == (const Integer& i) const {
    return integer == i.integer;
}

bool Integer::operator != (const Integer& i) const {
    return integer != i.integer;
}

bool Integer::operator < (const Integer& i) const {
    return integer < i.integer;
}

bool Integer::operator <= (const Integer& i) const {
    return integer <= i.integer;
}

bool Integer::operator > (const Integer& i) const {
    return integer > i.integer;
}

bool Integer::operator >= (const Integer& i) const {
    return integer >= i.integer;
}
