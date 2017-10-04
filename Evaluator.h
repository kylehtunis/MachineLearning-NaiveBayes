#ifndef Evaluator__H
#define Evaluator__H

#include <iostream>
#include "Classifier.h"
#include "KNN.h"
#include "DataSet.h"
#include "Performance.h"
#include "NaiveBayes.h"
#include <algorithm>

class Evaluator {
private:
	DataSet data;
	Performance performance;
	void evaluateOne(vector<Classification> results, DataSet& test);
	int folds;
	int seed;
	int k;
public:
	Evaluator();
	Evaluator(const DataSet& ds);
	Performance getPerformance() const;
	void evaluateKNN();
	void evaluateKNN(DataSet&);
	void evaluateNaiveBayes();
	void evaluateNaiveBayes(DataSet&);
	void setOptions(vector<string>&);
};




#endif // !Evaluator__H
