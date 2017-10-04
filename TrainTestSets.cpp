#include "TrainTestSets.h"

TrainTestSets::TrainTestSets() {}

TrainTestSets::TrainTestSets(vector<string> &options) {
	string file;
	for (int i = 1; i < options.size(); i++) {
		char c = options[i][1];
		switch (c) {
		case 't':
			i++;
			file = options[i];
			train.load(file);
			file = "";
			break;
		case 'T':
			i++;
			file = options[i];
			test.load(file);
			file = "";
			break;
		}
	}
	train.setOptions(options);
	test.setOptions(options);
}

DataSet TrainTestSets::getTestSet() const {
	return test;
}

DataSet TrainTestSets::getTrainingSet() const {
	return train;
}

void TrainTestSets::setTestSet(DataSet &ds) {
	test = ds;
}

void TrainTestSets::setTrainingSet(DataSet& ds) {
	train = ds;
}

void TrainTestSets::setOptions(const vector<string>& options) {
	string file;
	for (int i = 1; i < options.size(); i++) {
		char c = options[i][1];
		switch (c) {
		case 't':
			i++;
			file = options[i];
			train.load(file);
			file = "";
			break;
		case 'T':
			i++;
			file = options[i];
			test.load(file);
			file = "";
			break;
		}
	}
	train.setOptions(options);
	test.setOptions(options);
}

ostream& operator<<(ostream& os, const TrainTestSets& tts) {
	os << "Training set: \n" << tts.train << endl << "Test set: \n" << tts.test << endl;
	return os;
}