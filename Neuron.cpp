#include "Neuron.h"

double Neuron::getY(double x1, double x2)
{
	return w1 * x1 + w2 * x2 + b * w3;
}

double Neuron::sigmoidFun(double y)
{
	return 1 / (1 + exp(-1 * y));
}

double Neuron::thresholdOut(double out)
{
	return out < 0.5 ? 0 : 1;

}

double Neuron::getError(double target, double result)
{
	return target - result;
}

double Neuron::updateWeights(double x1, double x2, double error)
{
	w1 = w1 + nL * error * x1;
	w2 = w2 + nL * error * x2;
	w3 = w3 + nL * error * b;
}




