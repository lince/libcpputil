/*
 * Date.cpp
 *
 *   Created on: Feb 9, 2012
 *  Last Chance: 11:50:03 AM
 *       Author: caioviel
 *       E-mail: caio_viel@dc.ufscar.br
 */

#include "../include/IllegalParameterException.h"
#include "../include/InitializationException.h"
#include "../include/Functions.h"

#include "../include/Date.h"

namespace cpputil {

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

Date::MonthData** Date::months = initializeMonthsDate();

Date::WeekDay* Date::createWeekDay(std::string engName, std::string ptName) {
	Date::WeekDay* weekDay = new Date::WeekDay();
	weekDay->engName = engName;
	weekDay->ptName = ptName;
	return weekDay;
}

Date::WeekDay** Date::initializeWeekDays() {
	Date::WeekDay** weekDays = new Date::WeekDay*[7];

	weekDays[0] = createWeekDay("Sunday", "Domingo");
	weekDays[1] = createWeekDay("Monday", "Segunda-Feira");
	weekDays[2] = createWeekDay("Tuesday", "Terça-Feira");
	weekDays[3] = createWeekDay("Wednesday", "Quarta-Feira");
	weekDays[4] = createWeekDay("Thursday", "Quinta-Feira");
	weekDays[5] = createWeekDay("Friday", "Sexta-Feira");
	weekDays[6] = createWeekDay("Saturday", "Sábado");
	return weekDays;
}

Date::WeekDay** Date::weekDays = initializeWeekDays();

Date::Date(int d, int m, int y) {
	setDate(d, m, y);
	dateFormat = Date::US_SHORT_FORMAT;
	calcDayOfWeek();
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

void Date::_setMonth(int m)  {

}

void Date::_setYear(int y) {

}

void Date::setDay(int day) {

	calcDayOfWeek();
}

void Date::setMonth(int month) {
	if (month >= 0 && month <= 12) {
		this->month = month;
	} else {
		throw IllegalParameterException(
				"Invalid value for month:" + Functions::numberToString(month),
				"cpputil::Date",
				"setMonth(int)");
	}
	calcDayOfWeek();
}

void Date::setYear(int year) {
	if (year > 0) {
		this->year = year;
	} else {
		throw IllegalParameterException(
				"Invalid value for year:" + Functions::numberToString(year),
				"cpputil::Date",
				"setYear(int)");
	}
	calcDayOfWeek();
}

void Date::setDate(int d, int m, int y) {
	setYear(y);
	setMonth(m);
	setDay(d);
}

void Date::setDate(const Date & date) {
	this->year = date.year;
	this->month = date.month;
	this->day = date.day;
	this->dayOfWeek = date.dayOfWeek;
}

std::string Date::toString() {
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

std::string Date::toStringShortBR() {
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

std::string Date::toStringLongUS() {
	std::string aux = "";
	if (this->year >= 1900) {
		aux += this->getDayOfWeekStrUS() + ", ";
	}
	aux += this->months[this->month-1]->engName + " ";
	aux += Functions::numberToString(this->day) + ", ";
	aux += Functions::numberToString(this->year);
	return aux;
}

std::string Date::toStringLongBR() {
	std::string aux = "";
	if (this->year >= 1900) {
		aux += this->getDayOfWeekStrBR() + ", ";
	}
	aux += Functions::numberToString(this->day);
	aux += " de " + this->months[this->month-1]->engName;
	aux += " de " + Functions::numberToString(this->year);
	return aux;
}

std::string Date::toStringShortUS() {
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

int Date::getDayOfWeek() {
	calcDayOfWeek();
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
	return this->weekDays[this->dayOfWeek-1]->ptName;
}

std::string Date::getDayOfWeekStrUS() const {
	return this->weekDays[this->dayOfWeek-1]->engName;
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

Date Date::intToDate(long days) {
	if (days < 0) {
		throw InitializationException(
				"Trying to convert to date an invalid: "
				+ Functions::numberToString(days),
				"cpputil::Date",
				"toInt()");
	}

	int completeYears = 1900 + days/365;
	int remainingDays = days%365;
	long leapYearAdjust = completeYears/4 - completeYears/100 + completeYears/400;
	remainingDays -= leapYearAdjust;
	/*while (remainingDays < 0) {

	}*/
	return Date(1,1,1900);
}

long Date::toInt() const {
	if (this->year < 1900) {
		throw InitializationException(
				"Trying to convert to integer a date before 1900: "
				+ Functions::numberToString(this->year),
				"cpputil::Date",
				"toInt()");
	}

	long daysOfCurrentYear = this->day;
	for (int i = 0; i < this->month-1; i++) {
		daysOfCurrentYear += this->months[i]->numberOfDays;
	}

	if (isLeapYear() && this->month > 2) {
		daysOfCurrentYear++;
	}

	long completedYear = this->year - 1901;
	long daysOfCompletedYear = 0;
	if (completedYear > 0) {
		daysOfCompletedYear = completedYear*365;
	}

	long leapYearAdjust = completedYear/4 - completedYear/100 + completedYear/400;

	return daysOfCurrentYear + daysOfCompletedYear + leapYearAdjust;
}

Date & Date::operator =(const Date & date) {
	if (this != &date) {
		this->day = date.day;
		this->month = date.month;
		this->year = date.year;
		this->dayOfWeek = date.dayOfWeek;
		this->dayOfWeekCalculed = date.dayOfWeekCalculed;
	}
	return *this;
}

bool Date::operator ==(const Date & date) {
	return (this->day == date.day &&
			this->month == date.month &&
			this->year == date.year);
}

bool Date::operator !=(const Date & date) {
	return !(*this == date);
}

bool Date::operator >=(const Date & date) {
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

bool Date::operator >(const Date & date) {
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

bool Date::operator <=(const Date & date) {
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

bool Date::operator <(const Date & date) {
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

long Date::operator -(const Date & date) {
	long date1 = this->toInt();
	long date2 = this->toInt();
	return date1 - date2;
}

Date Date::operator -(const int days) {
	long date1 = this->toInt();
	return Date::intToDate(date1 - days);
}

Date Date::operator +(const int days) {
	long date1 = this->toInt();
	return Date::intToDate(date1 + days);
}

void Date::operator -=(const int days) {
	*this = *this - days;
}

void Date::operator +=(const int days) {
	*this = *this + days;
}

void Date::calcDayOfWeek() {
	//January 1st, 1900 was a Monday.
	if (dayOfWeekCalculed) {
		return;
	}

	if (this->year >= 1900) {
		int days = toInt();
		dayOfWeek = 1 + ((days%7) + 1)%7;
	} else {
		dayOfWeek = -1;
	}
	dayOfWeekCalculed = true;
}

} /* namespace cpputil */
