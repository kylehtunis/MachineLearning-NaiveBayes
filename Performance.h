#ifndef PERFORMANCE__H
#define PERFORMANCE__H

#include <iostream>
#include "DataSet.h"
#include "KNN.h"

using namespace std;

class Performance {
private:
	vector<double> accuracies;
	vector<double> certainties;
public:
	Performance();
	vector<double> getAccuracies() const;
	void addAccuracy(double acc);
	void addAccuracy(double correct, double total);
	void addCertainty(double c);
	double getVariance();
	double getAccuracy();
	vector<double> getCertainties() const;
	double getAverageCertainty();
	void clear();
};




#endif // !PERFORMANCE__H
