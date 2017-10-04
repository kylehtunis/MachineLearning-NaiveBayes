#ifndef TRAINTESTSETS__H
#define TRAINTESTSETS__H

#include "DataSet.h"
#include <vector>

using namespace std;

class TrainTestSets {
	friend ostream& operator<<(ostream&, const TrainTestSets&);
protected:
	DataSet train;
	DataSet test;
public:
	TrainTestSets();
	TrainTestSets(vector<string> &options);
	DataSet getTrainingSet() const;
	DataSet getTestSet() const;
	void setTrainingSet(DataSet &ds);
	void setTestSet(DataSet &ds);
	void setOptions(const vector<string> &options);
};




#endif // !TRAINTESTSETS__H
