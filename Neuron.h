#ifndef NEURON_H
#define NEURON_H
#include <vector>
#include <iostream>

using namespace std;

/// <summary>
/// The neuron class may be instantiated with an n-dimensional input vector and a 1-dimensional target vector.
/// It provides functions to return the dot product of an inputs vector and weights vector in order to 
/// create a binary prediction of the target class.
/// </summary>
class Neuron
{

private:
	vector<vector<int>> inputs;
	vector<int> target;
	vector<double> weights;
	int nDim;
	double bias;
public:
	Neuron(vector<vector<int>> inputs, vector<int> target, vector<double> weights, int nDim, double bias) {
		this->inputs = inputs;
		this->target = target;
		this->weights = weights;
		this->nDim = nDim;
		this->bias = bias;
	}

	// Overload for functionality as adder (NAND adder example from deep learning ebook)
	Neuron(int x1, int x2)
	{
		// This is a very simple "NAND" neuron for demonstration purposes.
		this->nDim = 2;
		this->weights = { -2, -2 };
		this->bias = 3;
		// Since the input vector is multidimensional, it is necessary to just set and take the 0th element in this case
		this->inputs.push_back({ x1, x2 });
	}

	//weights /// TODO
	double w1 = 0.1;
	double w2 = 0.1;

	// learning rate and bias
	double nL = 0.2;

	// forward pass
	double getY(vector<int> inputs);
	double getY();
	double sigmoidFun(double y);
	double stepFun(double y);
	double relU(double y);
	double tanH(double y);
	double thresholdOut(double out);

	// back pass
	double getError(double target, double result);
	void updateWeights(vector<int> xInputs, double error);
	int getInputSize();
	int getTargetSize();
	int getNumWeights();
	int getNumDimensions();

	

};
#endif 
