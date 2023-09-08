#ifndef ADDER_H
#define ADDER_H
#include <vector>
#include <iostream>

using namespace std;

/// <summary>
/// The goal of this class is to create a simple adder 
/// made out of perceptrons (set up as NAND gates) put together to behave like 
/// logic gates - concept from book: http://neuralnetworksanddeeplearning.com/chap1.html
/// 
/// </summary>
class Adder
{

private:
	vector<vector<int>> inputs;
	vector<double> weights;
	double bias = 3;

public: 
	
	// Construct adder
	Adder()
	{
		this->weights.push_back(-2);
		this->weights.push_back(-2);
	}

	// Addition method
	int add(int x1, int x2);

};

#endif // !ADDER_H