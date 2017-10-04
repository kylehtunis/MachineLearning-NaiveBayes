#include "Evaluator.h"

Evaluator::Evaluator() {
	folds = 10;
	seed = 123456789;
	k = 3;
};

Evaluator::Evaluator(const DataSet& ds) {
	data = ds;
	seed = 123456789;
	folds = 10;
	k = 3;
}

void Evaluator::evaluateOne(vector<Classification> results, DataSet& test) {
	double correct = 0;
	double total = 0;
	for (int i = 0; i < results.size(); i++) {
		if (test.getExamples()[i][test.getAttributes().getClassIndex()] == results[i].getResult()) {
			correct++;
		}
		total++;
	}
//	cout << "Accuracy = " << correct / total << endl;
	performance.addAccuracy(correct, total);
}

Performance Evaluator::getPerformance() const {
	return performance;
}

void Evaluator::evaluateKNN() {
	performance.clear();
	vector<int> indexes(data.getExamples().size());
	for (int i = 0; i < indexes.size(); i++) {
		indexes[i] = i;
	}
	srand(seed);
	random_shuffle(indexes.begin(), indexes.end());
	for (int i = 0; i < folds; i++) {
		DataSet train(data.getAttributes());
		DataSet test(data.getAttributes());
		for (int j = 0; j < data.getExamples().size(); j++) {
			if (j%folds == i) {
				test.addExample(data.getExamples()[indexes[j]]);
			}
			else {
				train.addExample(data.getExamples()[indexes[j]]);
			}
		}
		KNN knn(train, k);
		evaluateOne(knn.classify(test), test);
	}
	cout << "Accuracy with " << "k = " << k << ": " << getPerformance().getAccuracy() << " with variance = " << getPerformance().getVariance() << endl;
}

void Evaluator::evaluateKNN(DataSet& ds) {
	performance.clear();
	KNN knn(data, k);
	evaluateOne(knn.classify(ds), ds);
	cout << "Accuracy on test set = " << performance.getAccuracy() << " with a variance of " << performance.getVariance() << endl;
}

void Evaluator::evaluateNaiveBayes() {
	performance.clear();
	vector<int> indexes(data.getExamples().size());
	for (int i = 0; i < indexes.size(); i++) {
		indexes[i] = i;
	}
	srand(seed);
	random_shuffle(indexes.begin(), indexes.end());
	for (int i = 0; i < folds; i++) {
		DataSet train(data.getAttributes());
		DataSet test(data.getAttributes());
		for (int j = 0; j < data.getExamples().size(); j++) {
			if (j%folds == i) {
				test.addExample(data.getExamples()[indexes[j]]);
			}
			else {
				train.addExample(data.getExamples()[indexes[j]]);
			}
		}
		//cout << "Training NaiveBayes\n";
		NaiveBayes nb(train);
		//cout << "Evaluating NaiveBayes Model\n";
		evaluateOne(nb.classify(test), test);
	}
	cout << "Accuracy with " << folds << " folds = " << getPerformance().getAccuracy() << " with variance = " << getPerformance().getVariance() << endl;
}

void Evaluator::evaluateNaiveBayes(DataSet& ds) {
	NaiveBayes nb(data);
	evaluateOne(nb.classify(ds), ds);
	cout << "Accuracy on test set = " << performance.getAccuracy() << " with a variance of " << performance.getVariance() << endl;

}

void Evaluator::setOptions(vector<string>& options) {
	for (int i = 1; i < options.size(); i++) {
		char c = options[i][1];
		switch (c) {
		case 's':
			i++;
			seed = atoi(options[i].c_str());
			break;
		case 'x':
			i++;
			folds = atoi(options[i].c_str());
			break;
		case 'k':
			i++;
			k = atoi(options[i].c_str());
			break;
		}
	}
}