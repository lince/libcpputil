/*
 * Date.h
 *
 *   Created on: Feb 9, 2012
 *  Last Chance: 11:50:03 AM
 *       Author: caioviel
 *       E-mail: caio_viel@dc.ufscar.br
 */

#ifndef DATE_H_
#define DATE_H_

#include <string>
#include <iostream>

namespace cpputil {

class Date {
enum DateFormat {
	BR_LONG_FORMAT,
	BR_SHORT_FORMAT,
	US_LONG_FORMAT,
	US_SHORT_FORMAT
};

public:
	Date(int d, int m, int y);
	Date(const Date& date);
	virtual ~Date();

	void setDate(int d, int m, int y);
	void setDate(const Date& date);

    DateFormat getDateFormat() const;

    int getDay() const;
    int getMonth() const;
    int getYear() const;
    /**
     * Sunday -> 1; ... ; Saturday -> 7
     */
    int getDayOfWeek() const;
    std::string getDayOfWeekStr() const;
    std::string getDayOfWeekStrBR() const;
    std::string getDayOfWeekStrUS() const;

    bool isLeapYear() const;

    /**
     * Return the number of days since January 1st, 1900.
     * return A long number representing the date.
     */
    long toInt() const;

    void setDateFormat(DateFormat dateFormat);
    void setDay(int day);
    void setMonth(int month);
    void setYear(int year);

    std::string toString();
    std::string toStringLongBR();
    std::string toStringShortBR();
    std::string toStringLongUS();
    std::string toStringShortUS();

public:
   Date& operator=(const Date& date);

   bool operator==(const Date& date);
   bool operator!=(const Date& date);
   bool operator>=(const Date& date);
   bool operator>(const Date& date);
   bool operator<=(const Date& date);
   bool operator<(const Date& date);

   long operator-(const Date& date);

   Date operator-(const int days);
   Date operator+(const int days);

   void operator-=(const int days);
   void operator+=(const int days);


public:
    static Date getCurrentDate();

    static Date intToDate(long days);

private:
	int day;
	int month;
	int year;
	int dayOfWeek;

	DateFormat dateFormat;

	typedef struct {
		std::string engName;
		std::string ptName;
		int numberOfDays;
	} MonthData;

	typedef struct {
		std::string engName;
		std::string ptName;
	} WeekDay;

	static MonthData** months;
	static WeekDay** weekDays;

private:
	void _setDay(int d);
	void _setMonth(int m);
	void _setYear(int y);

	static Date::WeekDay** initializeWeekDays();
	static Date::WeekDay* createWeekDay(std::string engName, std::string ptName);
	static Date::MonthData** initializeMonthsDate();
	static Date::MonthData* createMonthDate(std::string engName, std::string ptName, int days);

	void calcDayOfWeek();
};

} /* namespace cpputil */
#endif /* DATE_H_ */
