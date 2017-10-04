#include "Main.h"

using namespace std;

int main(int argc, char* argv[]) {
	vector<string> options(argc);
	for (int i = 0; i < argc; i++) {
		options[i] = argv[i];
	}
	TrainTestSets tts(options);
	Evaluator eval(tts.getTrainingSet());
	eval.setOptions(options);
	eval.evaluateKNN();
	eval.evaluateNaiveBayes();
	return 0;
}