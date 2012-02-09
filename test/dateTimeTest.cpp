#include "../include/Time.h"
#include "../include/Date.h"
using namespace cpputil;

#include <iostream>
using namespace std;

int main() {
	Time time1(23,40,50);
	time1.setTimeFormat(Time::BR_FORMAT);
	Time time2 = Time::getCurrentTime();
	Time time3(time2);
	Time time4(11,11,11);

	cout << "time1: " << time1 << endl;
	cout << "time2: " << time2 << endl;
	cout << "time3: " << time3 << endl;
	cout << "time4: " << time4 << endl;

	time4.setTime(20, 20 ,20);
	cout << "time4 after setted: " << time4 << endl;

	cout << "time1 + 60: " << time1 + 60 << endl;
	cout << "time2 + 3666: " << time2 + 3666 << endl;
	cout << "time3 - 89: " << time3 - 89 << endl;
	cout << "time4 - 60: " << time4 - 60 << endl;

	time1.setTime(10, 20, 20);
	time1.setTimeFormat(Time::BR_FORMAT);
	time2.setTime(10, 20, 40);
	time2.setTimeFormat(Time::BR_FORMAT);
	cout << time2 << " - " << time1 << " = " << time2 - time1 << endl;

	Date date(80,15,-9);

	cout << date.toString() << endl;

	return 0;
}
