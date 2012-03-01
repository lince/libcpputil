/*
 * Date.cpp
 *
 *   Created on: Feb 9, 2012
 *  Last Chance: 11:50:03 AM
 *       Author: caioviel
 *       E-mail: caio_viel@dc.ufscar.br
 */

#include <ctime>
#include <ctype.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/timeb.h>
#include <sys/time.h>

#include "../include/IllegalParameterException.h"
#include "../include/InitializationException.h"
#include "../include/Functions.h"

#include "../include/Date.h"

namespace cpputil {

Date::MonthData** Date::months = initializeMonthsDate();
char** Date::weekDaysBR = initializeWeekDaysBR();
char** Date::weekDaysUS = initializeWeekDaysUS();

Date::Date() {
	setDate(Date::getCurrentDate());
}

Date::Date(int d, int m, int y) {
	setDate(d, m, y);
	dateFormat = Date::US_SHORT_FORMAT;
}

Date::Date(const Date & date) {
	setDate(date);
	this->dateFormat = date.dateFormat;
}

Date::~Date() {

}

Date::DateFormat Date::getDateFormat() const {
	return dateFormat;
}

int Date::getDay() const {
	return day;
}

int Date::getMonth() const {
	return month;
}

int Date::getYear() const {
	return year;
}

void Date::setDateFormat(DateFormat dateFormat) {
	this->dateFormat = dateFormat;
}

void Date::setDay(int day) {
	_setDay(day);
	calcDayOfWeek();
}

void Date::_setDay(int day) {
	if (day >= 1 && day <= this->months[this->month-1]->numberOfDays) {
		this->day = day;
	} else if (this->month == 2 && isLeapYear() && day <= 29) {
		this->day = day;
	} else {
		throw IllegalParameterException(
				"Invalid value for day:" + Functions::numberToString(day),
				"cpputil::Date",
				"setDay(int)");
	}
}

void Date::setMonth(int month) {
	_setMonth(month);
	calcDayOfWeek();
}

void Date::_setMonth(int month)  {
	if (month >= 0 && month <= 12) {
		this->month = month;
	} else {
		throw IllegalParameterException(
				"Invalid value for month:" + Functions::numberToString(month),
				"cpputil::Date",
				"setMonth(int)");
	}

}

void Date::setYear(int year) {
	_setYear(year);
	calcDayOfWeek();
}

void Date::_setYear(int year) {
	if (year > 0) {
		this->year = year;
	} else {
		throw IllegalParameterException(
				"Invalid value for year:" + Functions::numberToString(year),
				"cpputil::Date",
				"setYear(int)");
	}
}

void Date::setDate(int d, int m, int y) {
	_setYear(y);
	_setMonth(m);
	_setDay(d);
	calcDayOfWeek();
}

void Date::setDate(const Date & date) {
	this->year = date.year;
	this->month = date.month;
	this->day = date.day;
	this->dayOfWeek = date.dayOfWeek;
}

std::string Date::toString() const {
	std::string aux;
	switch(this->dateFormat) {
	case Date::BR_LONG_FORMAT:
		aux = toStringLongBR();
		break;
	case Date::BR_SHORT_FORMAT:
		aux = toStringShortBR();
		break;
	case Date::US_LONG_FORMAT:
		aux = toStringLongUS();
		break;
	case Date::US_SHORT_FORMAT:
		aux = toStringShortUS();
		break;
	}
	return aux;
}

std::string Date::toStringShortBR() const {
	std::string aux = "";
	if (this->day < 10) {
		aux += "0";
	}
	aux += Functions::numberToString(this->day) + "/";
	if (this->month < 10) {
		aux += "0";
	}
	aux += Functions::numberToString(this->month) + "/";
	aux += Functions::numberToString(this->year);
	return aux;
}

std::string Date::toStringLongUS() const {
	std::string aux = "";
	aux += this->getDayOfWeekStrUS() + ", ";
	aux += this->months[this->month-1]->engName + " ";
	aux += Functions::numberToString(this->day) + ", ";
	aux += Functions::numberToString(this->year);
	return aux;
}

std::string Date::toStringLongBR() const {
	std::string aux = "";
	aux += this->getDayOfWeekStrBR() + ", ";
	aux += Functions::numberToString(this->day);
	aux += " de " + this->months[this->month-1]->ptName;
	aux += " de " + Functions::numberToString(this->year);
	return aux;
}

std::string Date::toStringShortUS() const {
	std::string aux = "";
	if (this->month < 10) {
		aux += "0";
	}
	aux += Functions::numberToString(this->month) + "-";
	if (this->day < 10) {
		aux += "0";
	}
	aux += Functions::numberToString(this->day) + "-";
	aux += Functions::numberToString(this->year);
	return aux;
}

WeekDay::Type Date::getDayOfWeek() const {
	return this->dayOfWeek;
}

std::string Date::getDayOfWeekStr() const {
	std::string aux;
	switch(this->dateFormat) {
	case Date::BR_LONG_FORMAT:
	case Date::BR_SHORT_FORMAT:
		aux = getDayOfWeekStrBR();
		break;
	case Date::US_LONG_FORMAT:
	case Date::US_SHORT_FORMAT:
		aux = getDayOfWeekStrUS();
		break;
	}
	return aux;
}

std::string Date::getDayOfWeekStrBR() const {
	return this->weekDaysBR[this->dayOfWeek];
}

std::string Date::getDayOfWeekStrUS() const {
	return this->weekDaysUS[this->dayOfWeek];
}

Date Date::getCurrentDate() {
	time_t rawtime;
	struct tm *timeinfo;
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	Date date(timeinfo->tm_mday, timeinfo->tm_mon + 1, timeinfo->tm_year + 1900);
	return date;
}

bool Date::isLeapYear() const {
	int aux = this->year;
	if(aux % 100 == 0){
		aux = aux / 100;
	}
	return ((aux % 4) == 0);
}

Date Date::daysToDate(long jd) {
	int l, n, i, j, m, y, d;
	/*if (d < 0) {
		throw InitializationException(
				"Trying to convert to date an invalid: "
				+ Functions::numberToString(d),
				"cpputil::Date",
				"toInt()");
	}

	long y, ddd, mm, dd, mi;

	y = (10000*d + 14780)/3652425;
	ddd = d - (y*365 + y/4 - y/100 + y/400);
	if (ddd < 0) {
		y--;
		ddd = d - (y*365 + y/4 - y/100 + y/400);
	}
	mi = (52 + 100*ddd)/3060;
	y = y + (mi + 2)/12;
	mm = (mi + 2)%12 + 1;
	dd = ddd - (mi*306 + 5)/10 + 1;
	return Date(dd, mm, y);*/

    l = jd + 68569;
    n = ( 4 * l ) / 146097;
    l = l - ( 146097 * n + 3 ) / 4;
    i = ( 4000 * ( l + 1 ) ) / 1461001;
    l = l - ( 1461 * i ) / 4 + 31;
    j = ( 80 * l ) / 2447;
    d = l - ( 2447 * j ) / 80;
    l = j / 11;
    m = j + 2 - ( 12 * l );
    y = 100 * ( n - 49 ) + i + l;
    return Date(d, m, y);
}

long Date::toDays() const {
	/*long  y, m;
	m = (this->month + 9)%12;
	y = this->year - m/10;
	return y*365 + y/4 - y/100 + y/400 + (m*306 + 5)/10 + (this->day - 1);*/

	return ( 1461 * ( year + 4800 + ( month - 14 ) / 12 ) ) / 4 +
	          ( 367 * ( month - 2 - 12 * ( ( month - 14 ) / 12 ) ) ) / 12 -
	          ( 3 * ( ( year + 4900 + ( month - 14 ) / 12 ) / 100 ) ) / 4 +
	          day - 32075;
}

Date & Date::operator=(const Date & date) {
	if (this != &date) {
		this->day = date.day;
		this->month = date.month;
		this->year = date.year;
		this->dayOfWeek = date.dayOfWeek;
	}
	return *this;
}

bool Date::operator==(const Date & date) const {
	return (this->day == date.day &&
			this->month == date.month &&
			this->year == date.year);
}

bool Date::operator!=(const Date & date) const {
	return !(*this == date);
}

bool Date::operator>=(const Date & date) const {
	if (this->year > date.year) {
		return true;
	} else if (this->year == date.year) {
		if (this->month > date.month) {
			return true;
		} else if (this->day >= date.day) {
			return true;
		}
	}
	return false;
}

bool Date::operator >(const Date & date) const {
	if (this->year > date.year) {
		return true;
	} else if (this->year == date.year) {
		if (this->month > date.month) {
			return true;
		} else if (this->day > date.day) {
			return true;
		}
	}
	return false;
}

bool Date::operator <=(const Date & date) const {
	if (this->year < date.year) {
		return true;
	} else if (this->year == date.year) {
		if (this->month < date.month) {
			return true;
		} else if (this->day <= date.day) {
			return true;
		}
	}
	return false;
}

bool Date::operator <(const Date & date) const {
	if (this->year < date.year) {
		return true;
	} else if (this->year == date.year) {
		if (this->month < date.month) {
			return true;
		} else if (this->day < date.day) {
			return true;
		}
	}
	return false;
}

long Date::operator -(const Date & date) const {
	long date1 = this->toDays();
	long date2 = this->toDays();
	return date1 - date2;
}

Date Date::operator -(const int days) const {
	long date1 = this->toDays();
	return Date::daysToDate(date1 - days);
}

Date Date::operator +(const int days) const {
	long date1 = this->toDays();
	return Date::daysToDate(date1 + days);
}

void Date::operator -=(const int days) {
	*this = *this - days;
	calcDayOfWeek();
}

void Date::operator +=(const int days) {
	*this = *this + days;
	calcDayOfWeek();
}

char** Date::initializeWeekDaysBR() {
	char** wd = new char*[7];
	wd[0] = "Domingo";
	wd[1] = "Segunda-Feira";
	wd[2] = "Terça-Feira";
	wd[3] = "Quarta-Feira";
	wd[4] = "Quinta-Feira";
	wd[5] = "Sexta-Feira";
	wd[6] = "Sábado";
	return wd;
}

char** Date::initializeWeekDaysUS() {
	char** wd = new char*[7];
	wd[0] = "Sunday";
	wd[1] = "Monday";
	wd[2] = "Tuesday";
	wd[3] = "Wednesday";
	wd[4] = "Thursday";
	wd[5] = "Friday";
	wd[6] = "Saturday";
	return wd;
}

Date::MonthData* Date::createMonthDate(std::string engName, std::string ptName, int days) {
	Date::MonthData* month = new Date::MonthData();
	month->engName = engName;
	month->ptName = ptName;
	month->numberOfDays = days;
	return month;
}

Date::MonthData** Date::initializeMonthsDate() {
	Date::MonthData** months = new Date::MonthData*[12];

	months[0] = createMonthDate("January", "Janeiro", 31);
	months[1] = createMonthDate("February", "Fevereiro", 28);
	months[2] = createMonthDate("March", "Março", 31);
	months[3] = createMonthDate("April", "Abril", 30);
	months[4] = createMonthDate("May", "Maio", 31);
	months[5] = createMonthDate("June", "Junho", 30);
	months[6] = createMonthDate("July", "Julho", 31);
	months[7] = createMonthDate("August", "Agosto", 31);
	months[8] = createMonthDate("September", "Setembro", 30);
	months[9] = createMonthDate("October", "Outubro", 31);
	months[10] = createMonthDate("November", "Novembro", 30);
	months[11] =  createMonthDate("December", "Dezembro", 31);
	return months;
}

void Date::calcDayOfWeek() {
	//*static Date gregorianLimite(4, 10, 1582);
	int a, y, m, q, d;
	a = (14 - month) / 12;
	y = year - a;
	m = month + 12 * a - 2;
	//if (*this > gregorianLimite) {
		q = day + 31*m/12 + y + y/4 - y/100 + y/400;
	//} else {
		//q = day + 31*m/12 + y + y/4 + 5;
	//}

	d = q % 7;
	this->dayOfWeek = (WeekDay::Type) d;
}

std::ostream &operator<<(std::ostream &out,
		   const Date& date) {

	out<<date.toString();
	return out;
}

} /* namespace cpputil */
