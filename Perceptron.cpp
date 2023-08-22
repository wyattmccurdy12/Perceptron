/*
	This is the main function where the perceptron is employed on some data from a text file.
	It is put together for educational purposes, and has been helped significantly by stack overflow and
	Computer Vision Lab from Youtube. Most of the code is based closely on the Perceptron tutorial by
	Computer Vision Lab.
	Created in Visual Studio 2022

	TODO:
		1. Create adder
		2. More robust
*/

#include <iostream>
#include <fstream>
#include <string>
#include "Neuron.h"

int main()
{

	// Empty vectors for the inputs
	vector<int> inputs;
	vector<int> target;
	vector<double> weights;

	string in_path = "perceptron_inputs_x_y_c.txt";
	string temp;
	string delimiter = " ";
	ifstream fin;
	fin.open(in_path);
	std::getline(fin, temp); // take header off
	// Execute a loop until EOF (End of File)
	int i = 0;
	while (fin) {
		std::getline(fin, temp);

		int pos = 0;
		std::string token;

		// # 1
		pos = temp.find(delimiter);
		token = temp.substr(0, pos);
		temp.erase(0, pos + delimiter.length());
		inputs.push_back(stoi(token));

		// # 3
		target.push_back(stoi(temp));

		// temporary thing to fix weights
		weights.push_back(0.0);

		i++;
	}
	fin.close();


	Neuron nn(inputs, target, weights);

	int epochNum = 0;

	while (epochNum < 10)
	{
		cout << "==================" << endl;
		cout << "epoch: " << epochNum << endl;

		int goodEstimationNumber = 0;
		int inputSize = nn.inputs.size();
		for (int i = 0; i < inputSize; i++)
		{
			double y = nn.getY();
			cout << "y: " << y << "\n";
			double sig = nn.sigmoidFun(y);
			double threshOut = nn.thresholdOut(sig);
			double error = nn.getError(nn.target[i], threshOut);
			cout << "error: " << error << endl;
			if (error == 0) goodEstimationNumber++;
			nn.updateWeights(error); 

			if (goodEstimationNumber == inputSize)
			{

				cout << "epoch num: " << epochNum << "\n";
				cout << "w1: " << nn.w1 << ", " << "w2: " << nn.w2 << ", " << "w3: " << nn.w3 << endl;
				cout << "ending epochs...";
				return 0;
			}
		}
		epochNum++;
		cout << "==================" << "\n\n";
	}


	cout << "========================" << endl;
	cout << "Final Weights: " << endl;
	cout << "w1: " << nn.w1 << ", w2: " << nn.w2 << ", w3: " << nn.w3 << endl;

}

