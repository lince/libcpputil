/*
 * Functions.cpp
 *
 *  Created on: Jul 15, 2011
 *      Author: caioviel
 */

#include "../include/Functions.h"
#include <sstream>
#include <ctime>
#include <ctype.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/timeb.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <arpa/inet.h>
#include <net/if.h>
#include <sys/ioctl.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <pwd.h>
#include <uuid/uuid.h>
#include <algorithm>
#include <cctype>
using namespace std;

namespace cpputil {

string Functions::numberToString(double value) {
	stringstream out;
	out << value;
	string s = out.str();
	return s;
}

Date Functions::getCurrentDate() {
	return Date::getCurrentDate();
}

Time Functions::getCurrentTime() {
	return Time::getCurrentTime();
}

string Functions::timeToStringUS(Time time) {
	return time.toStringUS();
}

string Functions::timeToStringBR(Time time) {
	return time.toStringBR();
}

string Functions::dateToStringUS(Date date) {
	return date.toStringShortUS();
}

string Functions::dateToStringBR(Date date) {
	return date.toStringShortBR();
}

string Functions::getCurrentTimestampUS() {
	Date nDate = Date::getCurrentDate();
	Time nTime = Time::getCurrentTime();

	std::string aux = Functions::timeToStringUS(nTime) + " - " +
			Functions::dateToStringUS(nDate);

	return aux;
}

string Functions::getCurrentTimestampBR() {
	Date nDate = Date::getCurrentDate();
	Time nTime = Time::getCurrentTime();

	std::string aux = Functions::timeToStringBR(nTime) + " - " +
			Functions::dateToStringBR(nDate);

	return aux;
}

double Functions::getCurrentTimeMillis() {
	static double startTimeMills;
	static bool firstCallTimeMills = true;
	timeval result;
	rusage usage;
	timeb t;

	ftime(&t);
	if(firstCallTimeMills) {
		firstCallTimeMills = false;
		startTimeMills = (double)t.time*1000 + (double)t.millitm - 1;
		return 1;
	}
	return (double)t.time*1000 + (double)t.millitm - startTimeMills;
}

bool Functions::isIPv4(const char* ip){
    if(ip == NULL) {
        return false;
    } else {
        sockaddr_in sa;
        return (inet_pton(AF_INET, ip, &(sa.sin_addr)) == 1);
    }
}

bool Functions::isIPv6(const char* ip){
    if(ip == NULL) {
        return false;
    } else {
        sockaddr_in6 sa;
        return (inet_pton(AF_INET6, ip, &(sa.sin6_addr)) == 1);
    }
}

std::string Functions::generateUUID() {
	char string[37];
	uuid_t gen;

	uuid_generate(gen);
	uuid_unparse(gen, string);
	return string;
}

std::string Functions::toUpperCase(const std::string& str) {
	std::string result = str;
	std::transform(result.begin(), result.end(), result.begin(),
			(int(*)(int)) std::toupper);
	return result;
}

std::string Functions::toLowerCase(const std::string& str) {
	std::string result = str;
	std::transform(result.begin(), result.end(), result.begin(),
			(int(*)(int)) std::tolower);
	return result;
}

std::string Functions::boolToString(const bool value) {
	if (value) {
		return "true";
	} else {
		return "false";
	}
}

}
 /* namespace cpputil */
