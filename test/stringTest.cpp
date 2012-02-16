#include <iostream>
#include <string>
using namespace std;


#include "../include/Functions.h"
using namespace cpputil;


int main() {
	char str[200];
	cout << "Enter a string: ";
	cin.getline(str, 200);

	cout << endl << "Normal String: " << str << endl;
	cout << "Upper Case String: " << Functions::toUpperCase(str) << endl;
	cout << "Lower Case String: " << Functions::toLowerCase(str) << endl << endl;


	cout << "Enter a double number: ";
	cin.getline(str, 200);
	string doubleStr = str;

	cout << "The string '" << doubleStr << "' is a valid double number? " <<
			Functions::toString(Functions::isDouble(doubleStr)) << endl;

	cout << "String '" << doubleStr << "' converted to double -> " << Functions::strToDouble(doubleStr) << endl;

	cout << "Enter a long number: ";
	cin.getline(str, 200);
	string longStr = str;

	cout << "The string '" << longStr << "' is a valid long number? " <<
			Functions::toString(Functions::isLong(longStr)) << endl;

	cout << "String '" << longStr << "' converted to long -> " << Functions::strToLong(longStr) << endl;

	cout << endl;

	return 0;
}
