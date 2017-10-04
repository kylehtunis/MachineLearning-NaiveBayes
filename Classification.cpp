#include "Classification.h"

Classification::Classification() {
	result = 0;
	certainty = 0;
}

Classification::Classification(int r, double c) {
	result = r;
	certainty = c;
}

int Classification::getResult() const {
	return result;
}

double Classification::getCertainty() const {
	return certainty;
}