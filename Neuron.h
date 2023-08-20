#ifndef NEURON_H
#define NEURON_H
#include <vector>


using namespace std;

class Neuron
{
public:

	//weights
	double w1 = 0.0;
	double w2 = 0.0;
	double w3 = 0.0;

	// learning rate and bias
	double nL = 0.2;
	double b = 1;

	// input vector
	// TODO give io for text file instead
	std::vector<std::vector<double>> inputs{
		{-1.0, -1.0},
		{-1.0, -2.0},
		{-3.0, -3.0},
		{-2.0, -1.0},
		{-5.0, -1.0},
		{1.0, 1.0},
		{1.0, 2.0},
		{1.0, 3.0},
		{4.0, 1.0},
		{2.0, 2.0}
	};

	// target classifications
	// TODO io instead
	vector<double> target{
		0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0
	};

	// forward pass
	double getY(double x1, double x2);
	double sigmoidFun(double y);
	double thresholdOut(double out);

	// back pass
	double getError(double target, double result);
	void updateWeights(double x1, double x2, double error);

};
#endif 
