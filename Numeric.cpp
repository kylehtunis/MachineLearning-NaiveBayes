#include "Numeric.h"

NumericAttribute::NumericAttribute() : Attribute() {}

NumericAttribute::NumericAttribute(string n) : Attribute(n) {}

void NumericAttribute::print(ostream& os) const {
	os << "@attribute " << name << " numeric";
}

ostream& operator<<(ostream& os, NumericAttribute &attribute) {
	os << "@attribute " << attribute.name << " numeric";
	return os;
}