// Perceptron.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Neuron.h"

// ISSUE : weights don't change

int main()
{
    Neuron nn;

    int epochNum = 0;
    
    while (epochNum < 10)
    {
        cout << "==================" << endl;
        cout << "epoch: " << epochNum << endl;

        int goodEstimationNumber = 0;
        int inputSize = nn.inputs.size();
        for (int i = 0; i < inputSize; i++)
        {
            double y = nn.getY(nn.inputs[i][0], nn.inputs[i][1]);
            cout << "y: " << y << "\n";
            double sig = nn.sigmoidFun(y);
            double threshOut = nn.thresholdOut(sig);
            double error = nn.getError(nn.target[i], threshOut);
            cout << "error: " << error << endl;
            if (error == 0) goodEstimationNumber++;
            nn.updateWeights(nn.inputs[i][0], nn.inputs[i][1], error);

            if (goodEstimationNumber == inputSize)
            {
                
                cout << "epoch num: " << epochNum << "\n";
                cout << "w1: " << nn.w1 << ", " << "w2: " << nn.w2 << ", " << "w3: " << nn.w3 << endl;
            }
        }
        epochNum++;
        cout << "==================" << "\n\n";
    }
}

