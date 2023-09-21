#pragma once
#ifndef DIGITRECOGNIZER_H
#define DIGITRECOGNIZER_H
#include <vector>
#include <iostream>

using namespace std;

/// <summary>
/// The digit recognizer is under construction! It is modeled from the Neural Networks and Deep Learning book Chapter 1, 
/// and it will provide the user with the tools to classify input vectors of size 784 (784 dimensional vector) - from 28x28
/// pixel MNIST handwritten digit samples. 
/// </summary>
class DigitRecognizer
{

public: 
	// MSE COST FUNCTION
	int classifyZeroToNine(vector<int> inImg);
};

#endif // !ADDER_H