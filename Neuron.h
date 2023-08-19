#ifndef NEURON_H
#define NEURON_H
#include <vector>


using namespace std;

class Neuron
{
public:
	Neuron();
	//weights
	double w1 = 0.0;
	double w2 = 0.0;
	double w3 = 0.0;

	// learning rate and bias
	double nL = 0.2;
	double b = 1;

	// input vector
	// TODO give io for text file instead
	std::vector<std::vector<int>> inputs{
		{-1, -1},
		{-1, -2},
		{-3, -3},
		{-2, -1},
		{-5, -1},
		{1, 1},
		{1, 2},
		{1, 3},
		{4, 1},
		{2, 2}
	};

	// target classifications
	// TODO io instead
	vector<int> target{
		0, 0, 0, 0, 0, 1, 1, 1, 1, 1
	};

	// forward pass
	double getY(double x1, double x2);
	double sigmoidFun(double y);
	double thresholdOut(double out);

	// back pass
	double getError(double target, double result);
	double updateWeights(double x1, double x2, double error);

};
#endif 
