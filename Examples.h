#ifndef EXAMPLES_H
#define EXAMPLES_H

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <typeinfo>
#include <cstdlib>
#include "Example.h"
#include "Attributes.h"

using namespace std;

class Examples : public vector<Example> {
	friend ostream& operator<<(ostream& os, const Examples& ex);
private:
	Attributes attributes;
public:
	Examples();
	Examples(const Attributes& attributes);
	void parse(istream& is);
	void setAttributes(const Attributes& attributes);
};
#endif // !EXAMPLES_H
