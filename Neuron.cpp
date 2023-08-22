#include "Neuron.h"

/// <summary>
/// Get output of inputs pushed through weights of the neuron.
/// </summary>
/// <param name="x1">Input 1 (x1)</param>
/// <param name="x2">Input 2 (x2)</param>
/// <returns>Output from weights/input to activation (y)</returns>
double Neuron::getY()
{
	// Return if bad input vector lengths
	if (inputs.size() != target.size())
	{
		cout << "Input vector and target vector are different lengths.";
		throw exception("Input vector and target vector are different lengths.");
	}
	if (inputs.size() != weights.size())
	{
		cout << "Input vector and weights vector are different lengths.";
		throw exception("Input vector and weights vector are different lengths.");
	}
	if (target.size() != weights.size())
	{
		cout << "Target vector and weights vector are different lengths.";
		throw exception("Target vector and weights vector are different lengths.");
	}

	// Work through list
	int len = inputs.size();
	int dp_sum = 0;
	for (int i = 0; i < len; i++)
	{
		int x = inputs[i];
		int w = weights[i];
		dp_sum += x * w;
	}
	dp_sum += b;
	return dp_sum;
}

/// <summary>
/// Sigmoid activation function for neuron
/// </summary>
/// <param name="y">Output of inputs pushed through weights</param>
/// <returns>Transformed output of sigmoid activation function</returns>
double Neuron::sigmoidFun(double y)
{
	return 1 / (1 + exp(-1 * y));
}

/// <summary>
/// Step function [-1, 1] activation function for neuron
/// </summary>
/// <param name="y">Output of inputs pushed through weights</param>
/// <returns>Transformed output of sigmoid activation function</returns>
double Neuron::stepFun(double y)
{
	return y < 0 ? -1 : 1;
}

/// <summary>
/// RelU activation function for neuron
/// </summary>
/// <param name="y">Output of inputs pushed through weights</param>
/// <returns>Transformed output of relU activation function</returns>
double Neuron::relU(double y)
{
	return max(0.0, y);
}

/// <summary>
/// TanH activation function for neuron
/// </summary>
/// <param name="y"></param>
/// <returns></returns>
double Neuron::tanH(double y)
{
	return ((exp(y) - exp(-1 * y)) / (exp(y) + exp(-1 * y)));
}

/// <summary>
/// 
/// </summary>
/// <param name="out"></param>
/// <returns></returns>
double Neuron::thresholdOut(double out)
{
	return out < 0.5 ? 0 : 1;

}

/// <summary>
/// Get prediction error - [1, -1]
/// </summary>
/// <param name="target">expected value</param>
/// <param name="result">actual output value</param>
/// <returns>difference between actual and expected (error)</returns>
double Neuron::getError(double target, double result)
{
	return target - result;
}

/// <summary>
/// Update layer (neuron) weights for output.
/// </summary>
/// <param name="x1">x1 - first input value</param>
/// <param name="x2">x2 - second input value</param>
/// <param name="error">prediction error for data point</param>
void Neuron::updateWeights(double error)
{

	for (int i = 0; i < weights.size(); i++)
	{
		double w = weights[i];
		double x = inputs[i];
		weights[i] = w + nL * error * x;
	}
}




