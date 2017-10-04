#include "Nominal.h"

NominalAttribute::NominalAttribute() : Attribute() {}

NominalAttribute::NominalAttribute(string n) : Attribute(n) {};

void NominalAttribute::addValue(string value) {
	domain.push_back(value);
}

int NominalAttribute::getSize() {
	return domain.size();
}

string NominalAttribute::getValue(int ndx) {
	return domain.at(ndx);
}

int NominalAttribute::getIndex(string val) {
	for (int i = 0; i < domain.size(); i++) {
		if (val == domain[i]) {
			return i;
		}
	}
	return 0;
}

void NominalAttribute::print(ostream& os) const {
	os << "@attribute " << name << " ";
	for (int i = 0; i < domain.size(); i++) {
		os << domain.at(i) << " ";
	}
}

ostream& operator<<(ostream& os, const NominalAttribute &attribute) {
	os << "@attribute " << attribute.name << " ";
	for (int i = 0; i < attribute.domain.size(); i++) {
		os << attribute.domain.at(i) << " ";
	}
	return os;
}