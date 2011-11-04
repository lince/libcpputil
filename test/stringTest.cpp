#include <iostream>
using namespace std;


#include "../include/Functions.h"
using namespace cpputil;


int main() {
	char str[200];
	cout << "Enter a string: ";
	cin.getline(str, 200);

	cout << endl << "Normal String: " << str << endl;
	cout << "Upper Case String: " << Functions::toUpperCase(str) << endl;
	cout << "Lower Case String: " << Functions::toLowerCase(str) << endl;
	return 0;
}
