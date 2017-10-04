#ifndef DATASET_H
#define DATASET_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>
#include "Attributes.h"
#include "Examples.h"

using namespace std;

class DataSet {
private:
	friend ostream& operator<<(ostream& os, const DataSet& ds);
protected:
	string name;
	Attributes attributes;
	Examples examples;
	long seed;
public:
	DataSet();
	DataSet(const Attributes& att);
	void add(const DataSet& ds);
	void add(const Example& example);
	Attributes getAttributes();
	Examples getExamples();
	long getSeed();
	bool getHasNominalAttributes();
	bool getHasNumericAttributes();
	void load(string file);
	void parse(istream& is);
	void setOptions(const vector<string> options);
	void setSeed(long s);
	void addExample(Example ex);
};
#endif // !DATASET_H
