#include "AttributeFactory.h"

Attribute* AttributeFactory::make(istream& is) {
	string word = "";
	is >> word;
	word = "";
	is >> word;
	string name = word;
	word = "";
	is >> word;
	if (word == "numeric") {
		return new NumericAttribute(name);
	}
	else {
		NominalAttribute* nom = NULL;
		nom = new NominalAttribute(name);
		nom->addValue(word);
		while (is >> word) {
			nom->addValue(word);
		}
		return nom;
	}
}
