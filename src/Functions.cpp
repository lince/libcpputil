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
#include <cstdlib>
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
#include <cerrno>
#include <iostream>
using namespace std;

namespace cpputil {

string Functions::numberToString(const double value) {
	return Functions::toString(value);
}

Date Functions::getCurrentDate() {
	return Date::getCurrentDate();
}

Time Functions::getCurrentTime() {
	return Time::getCurrentTime();
}

string Functions::getCurrentTimestampUS() {
	Date nDate = Date::getCurrentDate();
	Time nTime = Time::getCurrentTime();

	std::string aux = nTime.toStringUS() + " - " + nDate.toStringShortUS();

	return aux;
}

string Functions::getCurrentTimestampBR() {
	Date nDate = Date::getCurrentDate();
	Time nTime = Time::getCurrentTime();

	std::string aux = nTime.toStringBR() + " - " + nDate.toStringShortBR();
	return aux;
}

double Functions::getCurrentTimeMillis() {
	static double startTimeMills;
	static bool firstCallTimeMills = true;
	timeb t;

	ftime(&t);
	if(firstCallTimeMills) {
		firstCallTimeMills = false;
		startTimeMills = (double)(t.time) * 1000 + (double)(t.millitm) - 1;
		return 1;
	}
	return (double)(t.time) * 1000 + (double)(t.millitm) - startTimeMills;
}

bool Functions::isIPv4(std::string ip)
{
	sockaddr_in sa;
	return (inet_pton(AF_INET, ip.c_str(), &(sa.sin_addr)) == 1);
}

std::string Functions::toString(const double value) {
	stringstream out;
	out << value;
	string s = out.str();
	return s;
}

std::string Functions::toString(const bool value) {
	if(value){
		return "true";
	}else{
		return "false";
	}
}

bool Functions::isLong(const std::string& str) {
	char* endPoint;
	strtol(str.c_str(), &endPoint, 0);

	if (errno == ERANGE) {
		return false;
	}

	//Ignore possible spaces after the number.
	for (; endPoint[0] == ' ' && endPoint[0] != '\0'; endPoint++);
	return (strlen(endPoint) == 0);
}

long Functions::strToLong(const std::string& str) {
	char* endPoint;
	long retValue = strtol(str.c_str(), &endPoint, 0);

	if (errno == ERANGE) {
		throw IllegalParameterException(
				"The number is out of range of long numbers.",
				"cpputil::Functions",
				"strToLong(const string&)");
	}

	//Ignore spaces.
	for (; endPoint[0] == ' ' && endPoint[0] != '\0'; endPoint++);

	if (strlen(endPoint) != 0) {
		throw IllegalParameterException(
				"String '" + str + "' isn't a valid long number.",
				"cpputil::Functions",
				"strToLong(const string&)");
	}
	return retValue;
}

bool Functions::isDouble(const std::string& str) {
	char* endPoint;
	strtod(str.c_str(), &endPoint);

	if (errno == ERANGE) {
		return false;
	}

	//Ignore possible spaces after the number.
	for (; endPoint[0] == ' ' && endPoint[0] != '\0'; endPoint++);
	return (strlen(endPoint) == 0);
}

double Functions::strToDouble(const std::string& str) {
	char* endPoint;
	double retValue = strtod(str.c_str(), &endPoint);

	if (errno == ERANGE) {
		throw IllegalParameterException(
				"The number is out of range of double numbers.",
				"cpputil::Functions",
				"strToDouble(const string&)");
	}

	//Ignore spaces.
	for (; endPoint[0] == ' ' && endPoint[0] != '\0'; endPoint++);

	if (strlen(endPoint) != 0) {
		throw IllegalParameterException(
				"String '" + str + "' isn't a valid double number.",
				"cpputil::Functions",
				"strToDouble(const string&)");
	}
	return retValue;
}

bool Functions::isIPv6(std::string ip) {
	sockaddr_in6 sa;
	return (inet_pton(AF_INET6, ip.c_str(), &(sa.sin6_addr)) == 1);
}

std::string Functions::generateUUID() {
	char string[37];
	uuid_t gen;
	uuid_generate(gen);
	uuid_unparse(gen, string);
	return string;
}

std::string Functions::toUpperCase(const std::string & str) {
	std::string result = str;
	std::transform(result.begin(), result.end(), result.begin(), (int(*)(int))(std::toupper));
	return result;
}

std::string Functions::toLowerCase(const std::string & str) {
	std::string result = str;
	std::transform(result.begin(), result.end(), result.begin(), (int(*)(int))(std::tolower));
	return result;
}

std::string Functions::boolToString(const bool value) {
	return Functions::toString(value);
}

/* namespace cpputil */
}

