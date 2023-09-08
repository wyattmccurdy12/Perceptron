#include "Adder.h"
#include "Neuron.h"

/// <summary>
/// The adder has an input layer made up of 2 binary integers [0,1],
/// and 5 simple perceptrons, all with input weights of -2, and biases of 3.
/// It is simply made for bitwise addition.
/// </summary>
/// <param name="inputs"></param>
/// <param name="weights"></param>
/// <param name="bias"></param>
/// <returns></returns>
int Adder::add(int x1, int x2)
{
	//if (x1 < 0 || x1 > 1) throw exception("Input x1 is outside of expected range!");
	//if (x2 < 0 || x2 > 1) throw exception("Input x2 is outside of expected range!");
	//// Input layer - see above for inputs

	//// I call the below "layers" referencing the NAND gate diagram from the referenced text.
	//
	//// First layer -- 1 perceptron accepting inputs x1 and x2
	Neuron n1(x1, x2);
	int n1_out = n1.getY(); // We will overload this function as well for the simple nand neuron

	//// Second layer -- 3 perceptrons accepting the outputs from the previous layer
	Neuron n2(x1, n1.getY());
	Neuron n3(x2, n1.getY());
	Neuron n4(n1.getY(), n1.getY());

	//// Get the carry bit - for if we added two numbers that are both ones
	int carryBit = n4.getY();

	//// Third layer - the output neuron for the addition
	Neuron n5(n2.getY(), n3.getY());
	//
	int adderOutput = n5.getY();
	
	std::cout << "The adder outputs " << adderOutput << ",\nwith a carry bit of " << carryBit << endl << endl;
	return adderOutput + carryBit * 2;
}
