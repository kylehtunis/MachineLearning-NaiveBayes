#include "Attribute.h"

Attribute::Attribute() {
	name = "unnamed";
}

Attribute::Attribute(string n) {
	name = n;
}

string Attribute::getName() const {
	return name;
}

void Attribute::setName(string n) {
	name = n;
}

int Attribute::getSize() {
	return -1;
}

void Attribute::print(ostream& os) const {}

ostream& operator<<(ostream& os, const Attribute &attribute) {
	os << "@attribute " << attribute.getName();
	return os;
}