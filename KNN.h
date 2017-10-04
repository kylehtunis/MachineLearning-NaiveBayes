#ifndef KNN__H
#define KNN__H

#include "Classifier.h"

class KNN : public Classifier {
private:
	DataSet instances;
	int k;
public:
	KNN(int k);
	KNN(DataSet&, int);
	virtual void train(DataSet&);
	virtual Classification classify(Example &ex);
	virtual vector<Classification> classify(DataSet &ds);
};




#endif // !KNN__H
