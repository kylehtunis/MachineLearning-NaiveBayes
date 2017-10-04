#ifndef NAIVEBAYES__H
#define NAIVEBAYES__H

#include <iostream>
#include <vector>
#include "DataSet.h"
#include "Classifier.h"
#include "Nominal.h"

using namespace std;

class NaiveBayes : public Classifier {
private:
	vector<int> classCounts;
	vector<vector< vector<int> > > conditionalCounts; //(attribute, value, class value)
public:
	NaiveBayes();
	NaiveBayes(DataSet&);
	virtual void train(DataSet&);
	virtual Classification classify(Example&);
	virtual vector<Classification> classify(DataSet&);
};




#endif // !NAIVEBAYES__H
