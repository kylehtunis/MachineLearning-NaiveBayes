#include "Attributes.h"

using namespace std;

Attributes::Attributes() {
	hasNominalAttributes = false;
	hasNumericAttributes = false;
	classIndex = -1;
}

void Attributes::add(Attribute* attribute) {
	attributes.push_back(attribute);
}

int Attributes::getClassIndex() {
	return classIndex;
}

bool Attributes::getHasNominalAttributes() {
	return hasNominalAttributes;
}

bool Attributes::getHasNumericAttributes() {
	return hasNumericAttributes;
}

Attribute* Attributes::get(int ndx) const {
	return attributes[ndx];
}

Attribute* Attributes::getClassAttribute() {
	return attributes[classIndex];
}

int Attributes::getIndex(string n) {
	for (int i = 0; i < attributes.size(); i++) {
		if (attributes[i]->getName() == n) {
			return i;
		}
	}
}

int Attributes::getSize() const {
	return attributes.size();
}

void Attributes::parse(istream &is) {
	string sLine = new char;
	int noLineCount = 0;
	while (getline(is, sLine)) {
		if (sLine.substr(0, 10) == "@attribute") {
			istringstream iss(sLine);
			Attribute* att = AttributeFactory::make(iss);
			attributes.push_back(att);
			if (typeid(*att) == typeid(NominalAttribute)) {
				hasNominalAttributes = true;
			}
			else {
				hasNumericAttributes = true;
			}
		}
		else if (sLine.substr(0, 9) == "@examples") {
			break;
		}
	}
}

void Attributes::setClassIndex(int ndx) {
	classIndex = ndx;
}

ostream& operator<<(ostream& os, const Attributes& att) {
	for (int i = 0; i < att.getSize(); i++) {
		att.get(i)->print(os);
		os << endl;
	}
	return os;
}