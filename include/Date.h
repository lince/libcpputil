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

/**
 * This class wrapper an enumeration that represents the days of the week.
 */

class WeekDay {
public:
	/**
	 * Enumeration of the days of the week.
	 * The days are enumerated as: SUNDAY=0, ..., SATURDAY=6.
	 */
	enum Type {
		SUNDAY=0,
		MONDAY=1,
		TUESDA=2,
		WEDNESDAY=3,
		THURSDAY=4,
		FRIDAY=5,
		SATURDAY=6,
		NONE,
	};
};

/**
 * This class wrapper an enumeration that represents the months of a year.
 */
class Month {
public:

	/**
	 * Enumeration of the months of a year.
	 * The months are enumerated as: JANUARY=1, ..., DECEMBER=12
	 */
	enum Type {
		JANUARY=1,
		FEBRUARY=2,
		MARCH=3,
		APRIL=4,
		MAY=5,
		JUNE=6,
		JULY=7,
		AUGUST=8,
		SEPTEMBER=9,
		OCTOBER=10,
		NOVEMBER=11,
		DECEMBER=12,
		NONE
	};
};

/**
 * This class represents Gregorian Date and holds many useful methods to manipulate Date.
 * Aratimetic and booleans operators are overridden.
 */
class Date {
public:
	/**
	 * Enumeration that represents the differences types of date-formated strings.
	 * - BR_LONG_FORMAT Brazilian-Portuguese long formated strings: "Sexta-Feira, 10 de Feveriro de 2012".
	 * - BR_SHORT_FORMAT Brazilian-Portuguese short formated strings: "10/02/2012".
	 * - US_LONG_FORMAT USA-English long formated strings: "Friday, February 10, 2012".
	 * - US_SHORT_FORMAT USA-English long formated strings: "2-10-2012".
	 */
	enum DateFormat {
		BR_LONG_FORMAT,
		BR_SHORT_FORMAT,
		US_LONG_FORMAT,
		US_SHORT_FORMAT
	};

public:

	/**
	 * Default constructor
	 * Will assume the current data value.
	 */
	Date();

	/**
	 * Integer Constructor.
	 * Instances created with this constructor will have DateFormat::US_SHORT_FORMAT as default
	 * date-formated string.
	 * @param d The numeric representation of a day in range 1-31.
	 * @param m The numeric representation of a month in range 1-12.
	 * @param y The numeric representation of a year bigger than 0.
	 * @throw IllegalParameterException When informed a invalid date.
	 */
	Date(int d, int m, int y);

	/**
	 * Copy Constructor
	 * @param date The instance of class Date that will be coped.
	 */
	Date(const Date& date);

	/**
	 * Destructor.
	 */
	virtual ~Date();

	/**
	 * This method returns the DateFormat utilized to generate strings in this instance.
	 * @return An instance of enumeration DateFormat that represents the date-formated strings.
	 */
	DateFormat getDateFormat() const;

	/**
	 * This method returns day part of Date represented by current instance.
	 * @return A integer representing the day part of the date in range 1-31.
	 */
	int getDay() const;

	/**
	 * This method returns month part of Date represented by current instance.
	 * @return A integer representing the month part of the date in range 1-12.
	 */
	int getMonth() const;

	/**
	 * This method returns year part of date represented by current instance.
	 * @return A integer representing the day part of the date in range 1-31.
	 */
	int getYear() const;

	/**
	 * This method returns the day of week of the date represented by the current instance.
	 * @return An item of WeeDay::Type enumeration representing the day of week.
	 */
	WeekDay::Type getDayOfWeek() const;

	/**
	 * This method returns a string with day of week of the date represented by the current instance.
	 * It can return names in Brazilian-Portuguese ou USA-English. The language of the returned string
	 * depends on the DataFormat of the current instance.
	 * @return A string with the day of week.
	 */
	std::string getDayOfWeekStr() const;

	/**
	 * This method returns a string with the Brazilian-Portuguese name of the day of week represented
	 * by the current instance.
	 * @return A string with the day of week portuguese name.
	 */
	std::string getDayOfWeekStrBR() const;

	/**
	 * This method returns a string with the USA-English name of the day of week represented
	 * by the current instance.
	 * @return A string with the day of week english name.
	 */
	std::string getDayOfWeekStrUS() const;

	/**
	 * This method can be used to discovery if the year of the date represented by the current
	 * instance is a leap year.
	 * @return true is a leap year; false otherwise.
	 */
	bool isLeapYear() const;

	/**
	 * This method returns the Julian Day number of the date represented by the current instance.
	 * return A long number representing the date in Julian Day Number system.
	 */
	long toDays() const;

	/**
	 * This method can be used to set the DateFormat that will be used to generate date-formated string
	 * in the current instance.
	 * @param dateFormat In item of the enumeration DateFormat that determine the date-formated string format.
	 */
	void setDateFormat(DateFormat dateFormat);

	/**
	 * This method can be used to define the day part of date represented by the current instance.
	 * @param day A integer in rage 1-31.
	 * @throw IllegalParameterException When the value to be setted is invalid.
	 */
	void setDay(int day);

	/**
	 * This method can be used to define the month part of date represented by the current instance.
	 * @param month A integer in rage 1-12.
	 * @throw IllegalParameterException When the value to be setted is invalid.
	 */
	void setMonth(int month);

	/**
	 * This method can be used to define the year part of date represented by the current instance.
	 * @param year A integer bigger than 0.
	 * @throw IllegalParameterException When the value to be setted is invalid.
	 */
	void setYear(int year);

	/**
	 * This method can be used to define the date represented by the current instance using
	 * the interger representation of the date.
	 * @param d The numeric representation of a day in range 1-31.
	 * @param m The numeric representation of a month in range 1-12.
	 * @param y The numeric representation of a year bigger than 0.
	 * @throw IllegalParameterException When informed a invalid date.
	 */
	void setDate(int d, int m, int y);

	/**
	 * This method can be used to define the date represented by the current instance using
	 * another instance of Date.
	 * @param date An instance of Date that will be coped.
	 */
	void setDate(const Date& date);

	/**
	 * This method returns a date-formated string of the date represented by the current instance.
	 * The format of the string returned depends on the Date::DateFormat of the current instance.
	 * @return A date-formated string.
	 */
	std::string toString() const;

	/**
	 * This method returns a long Brazilian-Portuguese date-formated string of the date represented
	 * by the current instance.
	 * @return A long date-formated string in portuguese.
	 */
	std::string toStringLongBR() const;

	/**
	 * This method returns a short Brazilian-Portuguese date-formated string of the date represented
	 * by the current instance.
	 * @return A short date-formated string in Portuguese.
	 */
	std::string toStringShortBR() const;

	/**
	 * This method returns a long USA-English date-formated string of the date represented
	 * by the current instance.
	 * @return A long date-formated string in English.
	 */
	std::string toStringLongUS() const;

	/**
	 * This method returns a short USA-English date-formated string of the date represented
	 * by the current instance.
	 * @return A short date-formated string in English.
	 */
	std::string toStringShortUS() const;

public:
	/**
	 * Makes the leftmost instance represent the same date of the rightmost.
	 * @param date The rightmost instance that will be coped.
	 * @return A reference to the leftmost instance.
	 */
	Date& operator=(const Date& date);

	/**
	 * Compare the the leftmost instance with the rightmost.
	 * @return true if they represent the same date; false otherwise.
	 */
	bool operator==(const Date& date) const;

	/**
	 * Compare the the leftmost instance with the rightmost.
	 * @return true if they don't represent the same date; false otherwise.
	 */
	bool operator!=(const Date& date) const;

	/**
	 * Compare the the leftmost instance with the rightmost.
	 * @return true if they leftmost is equal or bigger than the rightmost; false otherwise.
	 */
	bool operator>=(const Date& date) const;

	/**
	 * Compare the the leftmost instance with the rightmost.
	 * @return true if they leftmost is bigger than the rightmost; false otherwise.
	 */
	bool operator>(const Date& date) const;

	/**
	 * Compare the the leftmost instance with the rightmost.
	 * @return true if they leftmost is equal or minor than the rightmost; false otherwise.
	 */
	bool operator<=(const Date& date) const;

	/**
	 * Compare the the leftmost instance with the rightmost.
	 * @return true if they leftmost is minor than the rightmost; false otherwise.
	 */
	bool operator<(const Date& date) const;

	/**
	 * This methods returns the number of days between the rightmost and the leftmost dates.
	 * @param date The date that will be used to calculate the difference.
	 * @return The number of days of difference between the two dates.
	 */
	long operator-(const Date& date) const;

	/**
	 * This methods can be used to calculate a negative offset of the current instance.
	 * @param days The number of days that will be removed from the current instance.
	 * @return A new instance with the offset calculated.
	 */
	Date operator-(const int days) const;

	/**
	 * This methods can be used to calculate a positive offset of the current instance.
	 * @param days The number of days that will be added from the current instance.
	 * @return A new instance with the offset calculated.
	 */
	Date operator+(const int days) const;

	/**
	 * This methods can be used to add a positive offset in the current instance.
	 * @param days The number of days that will be added to the current instance.
	 */
	void operator-=(const int days);

	/**
	 * This methods can be used to add a negative offset in the current instance.
	 * @param days The number of days that will be removed from the current instance.
	 */
	void operator+=(const int days);

	friend std::ostream &operator<<(std::ostream &out,
			const Date& date);

public:
	/**
	 * This method return a instance of Date representing the current date of the system.
	 * @return A Date instance representing the current date.
	 */
	static Date getCurrentDate();

	/**
	 * This converts a number into a Date using the Julian Day Number system.
	 * @param days The number of days in Julian Day Number systeam.
	 * @return A Date instance of the correspondent day.
	 */
	static Date daysToDate(long days);

private:
	int day;
	int month;
	int year;
	WeekDay::Type dayOfWeek;

	DateFormat dateFormat;

	typedef struct {
		std::string engName;
		std::string ptName;
		int numberOfDays;
	} MonthData;

	static MonthData** months;
	static char** weekDaysBR;
	static char** weekDaysUS;

private:
	void _setDay(int d);
	void _setMonth(int m);
	void _setYear(int y);

	static Date::MonthData** initializeMonthsDate();
	static Date::MonthData* createMonthDate(std::string engName, std::string ptName, int days);
	static char** initializeWeekDaysBR();
	static char** initializeWeekDaysUS();

	void calcDayOfWeek();
};

} /* namespace cpputil */
#endif /* DATE_H_ */
