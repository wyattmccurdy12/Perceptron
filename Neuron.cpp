#include "Neuron.h"

/// <summary>
/// Get output of inputs pushed through weights of the neuron.
/// </summary>
/// <param name="x1">Input 1 (x1)</param>
/// <param name="x2">Input 2 (x2)</param>
/// <returns>Output from weights/input to activation (y)</returns>
double Neuron::getY(vector<int> xInputs)
{
	int dp_sum = 0;
	for (int i = 0; i < nDim; i++)
	{
		int x = xInputs[i]; 
		int w = weights[i];
		dp_sum += x * w;
	}
	dp_sum += bias * weights[nDim];
	return dp_sum;
}

/// <summary>
/// Get neuron's output value (to input to an activation function).
/// </summary>
/// <returns>Output value for input to activation function.</returns>
double Neuron::getY()
{
	// Return x1 * w1 + x2 * w2 + b
	int x1 = inputs[0][0];
	int x2 = inputs[0][1];

	int outSign = x1 * weights[0] + x2 * weights[1] + bias;
	return (outSign > 0) ? 1 : 0;

	//return x1 * w1 + x2 * w2 + bias;
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
/// Update neuron weights for output.
/// </summary>
/// <param name="xInputs">Input vector</param>
/// <param name="error">Prediction error for data point.</param>
void Neuron::updateWeights(vector<int> xInputs, double error)
{
	cout << "updating weights..." << endl;
	int wLen = weights.size() - 1;
	for (int i = 0; i < wLen; i++)
	{
		double w = weights[i];
		weights[i] = weights[i] + nL * error * xInputs[i];
	}
	double w = weights[wLen];
	weights[wLen] = w + nL * error * bias;
	cout << "weights updated!\n";
}

/// <summary>
/// Return size of inputs vector (number of inputs).
/// </summary>
/// <returns>Size of inputs vector.</returns>
int Neuron::getInputSize()
{
	return inputs.size();
}

/// <summary>
/// Get size of targets vector (number of target values).
/// </summary>
/// <returns>Size of targets vector.</returns>
int Neuron::getTargetSize()
{
	return target.size();
}

/// <summary>
/// Get number of weights.
/// </summary>
/// <returns>Number of weights.</returns>
int Neuron::getNumWeights()
{
	return weights.size();
}

/// <summary>
/// Get number of input dimensions.
/// </summary>
/// <returns>Number of input dimensions.</returns>
int Neuron::getNumDimensions()
{
	return nDim;
}
