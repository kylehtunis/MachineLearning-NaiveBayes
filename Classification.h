#ifndef CLASSIFICATION__H
#define CLASSIFICATION__H

#include <iostream>

class Classification {
private:
	int result;
	double certainty;
public:
	Classification();
	Classification(int r, double c);
	int getResult() const;
	double getCertainty() const;
};


#endif // !CLASSIFICATION__H




