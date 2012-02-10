#include "../include/Time.h"
#include "../include/Date.h"
using namespace cpputil;

#include <iostream>
using namespace std;

int main() {
	Date date1(1,1,2012);
	Date date2(1,2,2012);
	Date date3(1,1,2013);
	Date date4(date1);
	cout << "date1: " << date1 << " -> " << date1.toDays() << " ->  "
			<< Date::daysToDate(date1.toDays())<< endl;

	cout << "date2: " << date2 << " -> " << date2.toDays() << " ->  "
			<< Date::daysToDate(date2.toDays()) << endl;

	cout << "date3: " << date3 << " -> " << date3.toDays() << " ->  "
			<< Date::daysToDate(date3.toDays()) << endl;

	cout << "date4: " << date4.toStringShortBR() << " -> " << date4.toDays() << " ->  "
			<< Date::daysToDate(date4.toDays()) << endl;

	cout << "date1 > date2: " << (date1 > date2) << endl;
	cout << "date3 > date4: " << (date3 > date4) << endl;
	cout << "date1 >= date2: " << (date1 >= date2) << endl;
	cout << "date3 >= date4: " << (date1 >= date2) << endl;

	cout << "date1 < date2: " << (date1 < date2) << endl;
	cout << "date3 < date4: " << (date3 < date4) << endl;
	cout << "date1 <= date2: " << (date1 <= date2) << endl;
	cout << "date3 <= date4: " << (date1 <= date2) << endl;

	cout << "date1 == date2: " << (date1 == date2) << endl;
	cout << "date1 == date3: " << (date1 == date3) << endl;
	cout << "date1 == date4: " << (date1 == date4) << endl;

	cout << "date1 != date2: " << (date1 != date2) << endl;
	cout << "date1 != date3: " << (date1 != date3) << endl;
	cout << "date1 != date4: " << (date1 != date4) << endl;

	cout << "date2 - date1: " << (date2 - date1) << endl;
	cout << "date3 - date1: " << (date3 - date1) << endl;
	cout << "date4 - date1: " << (date4 - date1) << endl;

	cout << "date1 + 1: " << (date1 + 1) << endl;
	cout << "date1 + 365: " << (date1 + 365) << endl;
	cout << "date1 - 30: " << (date1 - 30) << endl;

	return 0;
}
