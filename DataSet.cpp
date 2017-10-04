#include "DataSet.h"
using namespace std;

DataSet::DataSet() {
	name = "unnamed";
	seed = 3267243;
}

DataSet::DataSet(const Attributes& att) {
	attributes = att;
	name = "unnamed";
	seed = 3267243;
}

void DataSet::add(const Example& ex) {
	examples.push_back(ex);
}

void DataSet::add(const DataSet& ds) {
	for (int i = 0; i < ds.examples.size(); i++) {
		examples.push_back(ds.examples[i]);
	}
}

Attributes DataSet::getAttributes() {
	return attributes;
}

Examples DataSet::getExamples() {
	return examples;
}

long DataSet::getSeed() {
	return seed;
}

bool DataSet::getHasNominalAttributes() {
	return attributes.getHasNominalAttributes();
}

bool DataSet::getHasNumericAttributes() {
	return attributes.getHasNumericAttributes();
}

void DataSet::load(string file) {
	ifstream is(file.c_str());
	if (is) {
		parse(is);
	}
	else {
		cout << "could not load file";
	}
}

void DataSet::parse(istream& is) {
	string line = new char;
	getline(is, line);
	string sLine = line;
	istringstream iss(sLine);
	string word = "";
	iss >> word;
	word = "";
	iss >> word;
	name = word;
	attributes.parse(is);
	attributes.setClassIndex(attributes.getSize() - 1);
	examples.setAttributes(attributes);
	examples.parse(is);
}

void DataSet::setSeed(long s) {
	seed = s;
}

void DataSet::setOptions(const vector<string> options) {
	int s = 0;
	for (int i = 1; i < options.size(); i++) {
		char c = options[i][1];
		switch (c) {
		case 's':
			i++;
			s = atof(options[i].c_str());
			setSeed(s);
			break;
		default:
			i++;
			continue;
		}
	}
}

void DataSet::addExample(Example ex) {
	examples.push_back(ex);
}

ostream& operator<<(ostream& os, const DataSet& ds) {
	os << "@dataset " << ds.name << endl << endl;
	os << ds.attributes << endl;
	os << ds.examples;
	return os;
}