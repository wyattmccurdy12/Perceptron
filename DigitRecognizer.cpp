#include "DigitRecognizer.h"
#include "Neuron.h"
#include <vector>
#include <iostream>

using namespace std;

int DigitRecognizer::classifyZeroToNine(vector<int> inImg)
{
	// Create a vector of neurons for the input layer
	vector<Neuron> inputLayer;
	for (int i = 0; i < 784; i++)
	{
		Neuron n(0, 0);
		inputLayer.push_back(n);
	}

	// Create a vector of neurons for the one hidden layer
	vector<Neuron> hiddenLayer1;
	for (int i = 0; i < 16; i++)
	{
		Neuron n(0, 0);
		hiddenLayer1.push_back(n);
	}

	// Create a vector of neurons for the output layer
	vector<Neuron> outputLayer;
	for (int i = 0; i < 10; i++)
	{
		Neuron n(0, 0);
		outputLayer.push_back(n);
	}

	return 0;
}
