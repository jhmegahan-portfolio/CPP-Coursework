//---------------------------------------------
// Program Name: Exercise2_Fibonacci_Numbers
// Purpose: To take a user input number for
//          n and calculate fn using the the
//          Fibonacci Sequence.
// Coder: Josh Megahan
// Date: 10/2/2015
// Last Modified: Josh Megahan, 10/3/2015
//---------------------------------------------

#include <iostream>
#include <cmath>
using namespace std;

int main(void)
{
	double n;
	double fn;
	int answer;
	double diff;

	//Describe to user the purpose of the program
	cout << "The purpose of this program is to calculate" << endl
		 << "the value \"fn\" with the Fibonacci Equation" << endl
		 << "for a user defined value of \"n\"" << endl << endl;

	//User defines input
	cout << "Input value for n: ";
	cin >> n;

	//Calculate via Fibonacci equation and round value to become an int, find the difference between values
	fn = ((5.0 + sqrt(5.0))/10.0) * (pow((1.0 + sqrt(5.0))/2.0, n)) + ((5.0 - sqrt(5.0))/10.0) * (pow((1.0 - sqrt(5.0))/2.0, n));
	answer = floor (fn + 0.5);
	diff = fn - answer;

	//Output calculation of fn, answer, and diff
	cout << endl << "Calculated for " << n << " = " << fn << endl;
	cout << "As an integer fn = " << answer << endl;
	cout << "The difference between values = " << fn-answer << endl << endl;

	return 0;
}