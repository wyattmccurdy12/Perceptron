#include "Adder.h"
#include "Neuron.h"

/// <summary>
/// The adder has an input layer made up of 2 binary integers [0,1],
/// and 5 simple perceptrons, all with input weights of -2, and biases of 3.
/// (In other words, configured as NAND gates).
/// It is simply made for bitwise addition.
/// </summary>
/// <param name="inputs">The bits to be added by the adder.</param>
/// <returns>The addition of the two input bits.</returns>
int Adder::add(int x1, int x2)
{
	if (x1 < 0 || x1 > 1) throw exception("Input x1 is outside of expected range!");
	if (x2 < 0 || x2 > 1) throw exception("Input x2 is outside of expected range!");

	//// I call the below "layers" referencing the NAND gate diagram from the referenced text.
	//
	//// First layer -- 1 perceptron accepting inputs x1 and x2
	Neuron n1(x1, x2);
	int n1Out = n1.getY(); // We will overload this function as well for the simple nand neuron

	//// Second layer -- 3 perceptrons accepting the outputs from the previous layer
	Neuron n2(x1, n1Out);//////
	int n2Out = n2.getY();//////
	Neuron n3(x2, n1Out);////////
	int n3Out = n3.getY();
	Neuron n4(n1Out, n1Out);

	//// Get the carry bit - for if we added two numbers that are both ones
	int carryBit = n4.getY();

	//// Third layer - the output neuron for the addition
	Neuron n5(n2Out, n3Out);
	int adderOutput = n5.getY();
	
	return adderOutput + carryBit * 2;
}
