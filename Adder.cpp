
#include "Adder.h"
#include "Neuron.h"


int Adder::add(vector<vector<int>> inputs, vector<double> weights, double bias)
{

	// First "layer"
	Neuron n1(inputs, weights, bias);
	int n1_out = n1.getY(inputs);


}
