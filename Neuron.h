#ifndef NEURON_H
#define NEURON_H
#include <vector>
#include <iostream>

using namespace std;

class Neuron
{
public:
	vector<int> inputs;
	vector<int> target;
	vector<double> weights;

	Neuron(vector<int> inputs, vector<int> target, vector<double> weights) {
		this->inputs = inputs;
		this->target = target;
		this->weights = weights;
	}

	//weights
	double w1 = 0.0;
	double w2 = 0.0;
	double w3 = 0.0;

	// learning rate and bias
	double nL = 0.2;
	double b = 1;

	// forward pass
	double getY();
	double sigmoidFun(double y);
	double stepFun(double y);
	double relU(double y);
	double tanH(double y);
	double thresholdOut(double out);

	// back pass
	double getError(double target, double result);
	void updateWeights(double error);

};
#endif 
