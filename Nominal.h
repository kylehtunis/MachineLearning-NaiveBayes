#ifndef NOMINAL_H
#define NOMINAL_H

#include <iostream>
#include "Attribute.h"
#include <vector>
#include <string>

using namespace std;

class NominalAttribute : public Attribute {
private:
	friend ostream& operator<<(ostream& os, const NominalAttribute &attribute);
	vector<string> domain;
public:
	virtual void print(ostream& out = cout) const;
	NominalAttribute();
	NominalAttribute(string n);
	int getSize();
	void addValue(string value);
	string getValue(int ndx);
	int getIndex(string val);
};
#endif // !NOMINAL_H
