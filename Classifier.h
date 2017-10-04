#ifndef CLASSIFIER__H
#define CLASSIFIER__H

#include <iostream>
#include "DataSet.h"
#include "Attributes.h"
#include "Classification.h"

class Classifier {
public:
	virtual void train(DataSet&);
	virtual Classification classify(Example &ex);
	virtual vector<Classification> classify(DataSet &ds);
};





#endif // !CLASSIFIER__H
