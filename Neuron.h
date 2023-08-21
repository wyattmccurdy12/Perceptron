#ifndef NEURON_H
#define NEURON_H
#include <vector>

using namespace std;

class Neuron
{
public:
	vector<vector<int>> inputs;
	vector<int> target;

	Neuron(vector<vector<int>> i, vector<int> t) {
		inputs = i;
		target = t;
	}

	//weights
	double w1 = 0.0;
	double w2 = 0.0;
	double w3 = 0.0;

	// learning rate and bias
	double nL = 0.2;
	double b = 1;

	// forward pass
	double getY(double x1, double x2);
	double sigmoidFun(double y);
	double stepFun(double y);
	double relU(double y);
	double tanH(double y);
	double thresholdOut(double out);

	// back pass
	double getError(double target, double result);
	void updateWeights(double x1, double x2, double error);

};
#endif 
