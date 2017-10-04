#include "NaiveBayes.h"

NaiveBayes::NaiveBayes() {};

NaiveBayes::NaiveBayes(DataSet& ds) {
	classCounts.resize(dynamic_cast<NominalAttribute*>(ds.getAttributes().getClassAttribute())->getSize(), 1);
	conditionalCounts.resize(ds.getAttributes().getSize()-1);
	for (int i = 0; i < ds.getAttributes().getSize()-1; i++) {
		conditionalCounts[i].resize(dynamic_cast<NominalAttribute*>(ds.getAttributes().get(i))->getSize(), vector<int>(classCounts.size(), 1));
	}
	for (int i = 0; i < ds.getExamples().size(); i++) {
		int ndx = ds.getExamples()[i][ds.getExamples()[i].size()-1];
		classCounts[ndx]++;
		for (int j = 0; j < ds.getExamples()[i].size()-1; j++) {
			conditionalCounts[j][ds.getExamples()[i][j]][ndx]++;
		}
	}
}

Classification NaiveBayes::classify(Example& ex) {
	double maxProb = -1;
	int maxClass = -1;
	double total = 0;
	for (int i = 0; i < classCounts.size(); i++) {
		total += classCounts[i];
	}
	vector<double> PCi(classCounts.size());
	vector< vector<double> > PVjCi(ex.size()-1, vector<double>(classCounts.size()));
	for (int i = 0; i < classCounts.size(); i++) {
		PCi[i] = (classCounts[i] / total);
		for (int j = 0; j < ex.size()-1; j++) {
			PVjCi[j][i] = (conditionalCounts[j][ex[j]][i] / total) / PCi[i];
		}
	}
	for (int i = 0; i < classCounts.size(); i++) {
		double numerator = PCi[i];
		for (int j = 0; j < ex.size() - 1; j++) {
			numerator *= PVjCi[j][i];
		}
		double denominator = 0;
		for (int k = 0; k < classCounts.size(); k++) {
			double temp = PCi[k];
			for (int j = 0; j < ex.size() - 1; j++) {
				temp *= PVjCi[j][k];
			}
			denominator += temp;
		}
		double P = numerator / denominator;
		if (P > maxProb) {
			maxProb = P;
			maxClass = i;
		}
	}
	return Classification(maxClass, maxProb);
}

vector<Classification> NaiveBayes::classify(DataSet& ds) {
	vector<Classification> results(ds.getExamples().size());
	for (int i = 0; i < ds.getExamples().size(); i++) {
		results[i] = classify(ds.getExamples()[i]);
	}
	return results;
}

void NaiveBayes::train(DataSet& ds) {
	classCounts.resize(dynamic_cast<NominalAttribute*>(ds.getAttributes().getClassAttribute())->getSize(), 1);
	conditionalCounts.resize(ds.getAttributes().getSize() - 1);
	for (int i = 0; i < ds.getAttributes().getSize() - 1; i++) {
		conditionalCounts[i].resize(dynamic_cast<NominalAttribute*>(ds.getAttributes().get(i))->getSize(), vector<int>(classCounts.size()));
	}
	for (int i = 0; i < ds.getExamples().size(); i++) {
		int ndx = ds.getExamples()[i][ds.getExamples()[i].size() - 1];
		classCounts[ndx]++;
		for (int j = 0; j < ds.getExamples()[i].size() - 1; j++) {
			conditionalCounts[j][ds.getExamples()[i][j]][ndx]++;
		}
	}
}