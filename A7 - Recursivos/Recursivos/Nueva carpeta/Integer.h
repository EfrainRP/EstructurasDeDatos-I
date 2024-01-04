#ifndef INTEGER_H_INCLUDED
#define INTEGER_H_INCLUDED

#include <iostream>
#include <string>

class Integer{
private:
    long long int integer;

public:
Integer();
Integer(const Integer&);

Integer& operator=(const Integer& );

void setInteger(const long long int& );

long long int getInteger() const;

std::string toString() const;

bool operator == (const Integer&) const;

bool operator != (const Integer&)  const;

bool operator < (const Integer&) const;

bool operator <= (const Integer&) const;

bool operator > (const Integer&) const;

bool operator >= (const Integer&) const;
};

#endif // INTEGER_H_INCLUDED
