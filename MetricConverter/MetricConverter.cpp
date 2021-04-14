//-------------------------------------------
// Program Name: Metric Converter
// Purpose: This program converts two
//			English measurements to
//			metric.
// Coder: Josh Megahan
// Date: 9/24/2014
// Last Modified: Josh Megahan, 9/25/2015
//-------------------------------------------


#include <iostream>
#include <string>
using namespace std;

double convertInput(string inputStr);

int main(void)
{
	const double INCHES_PER_METER = 39.37;
	const double POUNDS_PER_KG = 2.24;

	string inputStr;
	double height;
	double weight;

	cout << "METRIC CONVERTER" << endl << endl;
	cout << "Enter your height in inches : ";
	getline(cin, inputStr);
	height = convertInput(inputStr);

	cout << "Enter your weight in pounds : ";
	getline(cin, inputStr);
	weight = convertInput(inputStr);
	cout << endl;

	double metric_height = height / INCHES_PER_METER;
	double metric_weight = weight / POUNDS_PER_KG;

	cout << "Your height is " << metric_height << " meters." << endl;
	cout << "Your weight is " << metric_weight << " kilograms." << endl;

	return 0;
}

double convertInput(string inputStr) {
	double numerator;
	double denominator;
	double value;

	size_t found = inputStr.find("/");
	if (found != string::npos) {
		numerator = stod(inputStr.substr(0, inputStr.find("/")));
		denominator = stod(inputStr.substr(inputStr.find("/") + 1, inputStr.length() - 1));
		value = numerator / denominator;
		return value;
	}
	value = stod(inputStr);
	return value;
}