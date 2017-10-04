#include "Examples.h"

using namespace std;

Examples::Examples() {
	attributes = Attributes();
}

Examples::Examples(const Attributes& att) {
	attributes = att;
}

void Examples::parse(istream& is) {
	string sLine;
	while (getline(is, sLine)) {
		if (sLine.substr(0, 8) == "@dataset" || sLine.substr(0, 10) == "@attribute" || sLine.substr(0, 9) == "@example" || sLine == "") {
			continue;
		}
		else {
			int i = 0;
			istringstream iss(sLine);
			Example ex(attributes.getSize());
			string word = "";
			while (iss >> word) {
				if (typeid(*attributes.get(i)) == typeid(NominalAttribute)) {
					ex[i] = dynamic_cast<NominalAttribute*>(attributes.get(i))->getIndex(word);
				}
				else {
					double value = atof(word.c_str());
					ex[i] = value;
				}
				word = "";
				i++;
			}
			this->push_back(ex);
		}
	}
}

void Examples::setAttributes(const Attributes& att) {
	attributes = att;
}

ostream& operator<<(ostream& os, const Examples& ex) {
	os << "@examples" << endl << endl;
	for (int i = 0; i < ex.size(); i++) {
		for (int j = 0; j < ex[i].size(); j++) {
			if (typeid(*ex.attributes.get(j)) == typeid(NominalAttribute)) {
				os << dynamic_cast<NominalAttribute*>(ex.attributes.get(j))->getValue(ex[i][j]) << " ";
			}
			else {
				os << ex[i][j] << " ";
			}
		}
		os << endl;
	}
	return os;
}