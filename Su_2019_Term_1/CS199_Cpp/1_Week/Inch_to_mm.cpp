/*
Austen Hsiao
CS199- Intro to programming 2
Convert inches to mm
*/

#include <iostream>
using namespace std;

const double INCH_TO_MM = 25.4;
int main(void)
{
	//Variables
	double converted, measure;
	//Converter
	cout << "Enter a measurement in inches: ";
	cin >> measure;
	//cin.ignore(100,'\n'); no need for this because only convert 1 thing
	converted = measure * INCH_TO_MM;
	cout << converted << " mm\n"; 
	return 0;
}
