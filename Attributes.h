#ifndef ATTRIBUTES_H
#define ATTRIBUTES_H

#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <typeinfo>
#include "Attribute.h"
#include "AttributeFactory.h"
#include "Nominal.h"
#include "Numeric.h"

class Attributes {
	friend ostream& operator<<(ostream& os, const Attributes& attributes);
	vector<Attribute*> attributes;
	bool hasNumericAttributes;
	bool hasNominalAttributes;
	int classIndex;
public:
	Attributes();
	void add(Attribute* attribute);
	int getClassIndex();
	bool getHasNumericAttributes();
	bool getHasNominalAttributes();
	Attribute* get(int ndx) const;
	Attribute* getClassAttribute();
	int getIndex(string n);
	int getSize() const;
	void parse(istream& is);
	void setClassIndex(int ndx);
};
#endif // !ATTRIBUTES_H
