#ifndef EXAMPLE_H
#define EXAMPLE_H

#include <iostream>
#include <vector>

using namespace std;

class Example : public vector<double> {
	friend ostream& operator<<(ostream& os, Example ex);
public:
	Example(int n);
};
#endif // !EXAMPLE_H
