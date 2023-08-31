#ifndef ADDER_H
#define ADDER_H
#include <vector>
#include <iostream>

/// <summary>
/// The goal of this class is to create a simple adder 
/// made out of perceptrons put together to behave like 
/// logic gates - concept from book: http://neuralnetworksanddeeplearning.com/chap1.html
/// 
/// </summary>
class Adder
{
private:
	int x, y;
public: 
	// Construct adder
	Adder(int x, int y)
	{
		this->x = x;
		this->y = y;
	}




};

#endif // !ADDER_H