#include "Classifier.h"

Classification Classifier::classify(Example& ex) {
	return Classification();
}

vector<Classification> Classifier::classify(DataSet& ds) {
	return *(new vector<Classification>);
}

void Classifier::train(DataSet& ds) {
	return;
}