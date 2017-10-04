#ifndef NUMERIC_H
#define NUMERIC_H

#include <iostream>
#include <string>
#include "Attribute.h"

using namespace std;

class NumericAttribute : public Attribute {
	friend ostream& operator<<(ostream& os, NumericAttribute &attribute);
public:
	virtual void print(ostream& os = cout) const;
	NumericAttribute();
	NumericAttribute(string n);
};
#endif // !NUMERIC_H
