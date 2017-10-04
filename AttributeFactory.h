#ifndef ATTRIBUTEFACTORY_H
#define ATTRIBUTEFACTORY_H

#include <iostream>
#include <sstream>
#include "Attribute.h"
#include "Nominal.h"
#include "Numeric.h"

using namespace std;

class AttributeFactory {
public:
	static Attribute* make(istream& is);
};
#endif // !ATTRIBUTEFACTORY_H
