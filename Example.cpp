#include "Example.h"

using namespace std;

ostream& operator<<(ostream& os, Example ex) {
	for (int i = 0; i < ex.size(); i++) {
		os << i << " ";
	}
	return os;
}

Example::Example(int n) : vector<double>(n) {};