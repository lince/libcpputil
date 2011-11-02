#include <iostream>
using namespace std;

#include "../include/Functions.h"
using namespace cpputil;

int main() {

	cout << Functions::generateUUID() << endl;
	cout << Functions::generateUUID() << endl;
	cout << Functions::generateUUID() << endl;
	cout << Functions::generateUUID() << endl;

	return 0;
}
