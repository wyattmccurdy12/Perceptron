/*
	This is the main function where the perceptron is employed on some data from a text file.
	It is put together for educational purposes, and has been helped significantly by stack overflow and
	Computer Vision Lab from Youtube. Most of the code is based closely on the Perceptron tutorial by
	Computer Vision Lab.
	Created in Visual Studio 2022

	Note: text file must have header for this code to work correctly.
*/

#include <iostream>
#include <fstream>
#include <string>
#include "Neuron.h"

int main()
{

	// Empty vectors for the inputs
	vector<vector<int>> inputs;
	vector<int> target;
	int numInputDimensions = 0;

	// Take in a text file and ingest inputs and target values
	// TODO - ingest inputs of variable dimensions
	string in_path = "perceptron_inputs_x_y_t.txt";
	string temp;
	string delimiter = " ";
	ifstream fin;
	fin.open(in_path);

	// Put in extra print outputs for clarity
	cout << "Reading text file" << endl;

	// Take off header and determine number of dimensions
	std::getline(fin, temp);
	int pos = 0;
	while (temp.find(delimiter) != -1)
	{
		numInputDimensions++;
		pos = temp.find(delimiter);
		cout << temp.substr(0, pos) << " ";
		temp.erase(0, pos + delimiter.length());
	}
	std::cout << endl;
	std::cout << "Number of dimensions: " << numInputDimensions << endl;

	// Create weights vector with n dimensions (zeros for initially)
	std::vector<double> weights(numInputDimensions + 1, 0.0); // last zero weight at the end for a bias weight
	std::cout << "weights: " << endl;
	for (int i = 0; i < weights.size(); i++)
	{
		std::cout << weights[i] << " ";
	}
	std::cout << endl;
	std::cout << endl;
	std::cout << "Reading in data: " << endl;
	// Execute a loop until EOF (End of File)
	while (fin) {
		std::getline(fin, temp);
		std::string token;

		// Go through delimiters to pull out inputs and push as a list to inputs
		vector<int> inInputsVec;
		while (temp.find(delimiter) != -1)
		{
			pos = temp.find(delimiter);
			token = temp.substr(0, pos);
			temp.erase(0, pos + delimiter.length());
			inInputsVec.push_back(stoi(token));
			std::cout << token << " ";
		}
		inputs.push_back(inInputsVec);
		//// # 1
		//pos = temp.find(delimiter);
		//token = temp.substr(0, pos);
		//temp.erase(0, pos + delimiter.length());
		//inputs.push_back(stoi(token));

		// # 3
		target.push_back(stoi(temp));
		std::cout << temp;
		std::cout << endl;
	}
	std::cout << endl << "Done reading data \n++++++++++++++++++++++++\n\n";
	fin.close();

	// Implement neuron
	Neuron nn(inputs, target, weights, numInputDimensions);

	std::cout << "Neuron created. Dimensions: " << nn.nDim << endl;

	int epochNum = 0;

	while (epochNum < 30)
	{
		cout << "==================" << endl;
		cout << "epoch: " << epochNum << endl;

		int goodEstimationNumber = 0;
		int inputSize = nn.inputs.size(); // TODO fix zero input size

		for (int i = 0; i < inputSize; i++)
		{
			cout << "getting y...\n";
			double y = nn.getY(inputs[i]); // FAILURE - why is the last element of xInputs of size zero?
			cout << "y: " << y << endl;
			cout << "sigmoid function being called...\n";
			double sig = nn.sigmoidFun(y);
			cout << "thresholding on sigmoid output...\n";
			double threshOut = nn.thresholdOut(sig);
			cout << "getting error...\n";
			double error = nn.getError(nn.target[i], threshOut);
			cout << "error: " << error << endl;
			if (error == 0) goodEstimationNumber++;
			nn.updateWeights(inputs[i], error);
			cout << "weights: ";
			for (int i = 0; i < weights.size(); i++)
			{
				cout << i << ": " << weights[i] << ", ";
			}
			cout << "\n\n";

			if (goodEstimationNumber == inputSize)
			{

				cout << "epoch num: " << epochNum << "\n";
				cout << "ending epochs...";
				return 0;
			}
		}
		epochNum++;
		cout << "good estimation number: " << goodEstimationNumber << endl;
		cout << "==================" << "\n\n";
	}


	cout << "========================" << endl;
	cout << "Final Weights: " << endl;
	for (int i = 0; i < weights.size(); i++)
	{
		cout << i << ": " << weights[i] << ", ";
	}
	cout << endl;

}

