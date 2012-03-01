/*
 * Time.h
 *
 *   Created on: Feb 9, 2012
 *  Last Chance: 10:10:40 AM
 *       Author: caioviel
 *       E-mail: caio_viel@dc.ufscar.br
 */

#ifndef TIME_H_
#define TIME_H_

#include <string>
#include <iostream>

namespace cpputil {

/**
 * This class contains representation of time and holds several usefull methods to handle time.
 */
class Time {
public:
	/**
	 * Enumeration which holds the possible time-formated string generated by the class.
	 * - US_FORMAT USA time format: "10:05:26 PM"
	 * - BR_FORMAT Brazilian time format: "22:05:26"
	 */
	enum TimeFormat {
		US_FORMAT,
		BR_FORMAT
	};

public:

	/**
	 * Default constructor
	 * Will assume the current time value.
	 */
	Time();

	/**
	 * Integer Constructor.
	 * Instances created with this constructor will have DateFormat::US_FORMAT as default
	 * time format.
	 * @param h The numeric representation of time in range 0-23.
	 * @param m The numeric representation of time in range 0-59.
	 * @param s The numeric representation of time in range 0-59.
	 * @throw IllegalParameterException When informed a invalid time.
	 */
	Time(int h, int m, int s);

	/**
	 * Copy Constructor
	 * @param time The instance of class Time that will be coped.
	 */
	Time(const Time& time);

	/**
	 * Destructor
	 */
	virtual ~Time();

	/**
	 * This method can be used to define the time represented by the current instance using
	 * the interger representation of the time.
	 * @param h The numeric representation of time in range 0-23.
	 * @param m The numeric representation of time in range 0-59.
	 * @param s The numeric representation of time in range 0-59.
	 * @throw IllegalParameterException When informed a invalid date.
	 */
	void setTime(int h, int m, int s);

	/**
	 * This method can be used to define the time represented by the current instance using
	 * another instance of Time.
	 * @param time An instance of Time that will be coped.
	 */
	void setTime(const Time& time);

	/**
	 * This method returns hour part of time represented by current instance.
	 * @return A integer representing the hour part of the time in range 0-23.
	 */
    int getHour() const;

	/**
	 * This method returns hour minute of time represented by current instance.
	 * @return A integer representing the minute part of the time in range 0-59.
	 */
    int getMinute() const;

	/**
	 * This method returns hour second of time represented by current instance.
	 * @return A integer representing the second part of the time in range 0-59.
	 */
    int getSecond() const;

	/**
	 * This method can be used to define the hour part of time represented by the current instance.
	 * @param hour A integer in rage 0-23.
	 * @throw IllegalParameterException When the value to be setted is invalid.
	 */
    void setHour(int hour);

	/**
	 * This method can be used to define the minute part of time represented by the current instance.
	 * @param minute A integer in rage 0-59.
	 * @throw IllegalParameterException When the value to be setted is invalid.
	 */
    void setMinute(int minute);

	/**
	 * This method can be used to define the second part of time represented by the current instance.
	 * @param second A integer in rage 0-59.
	 * @throw IllegalParameterException When the value to be setted is invalid.
	 */
    void setSecond(int second);

	/**
	 * This method returns a time-formated string of the time represented by the current instance.
	 * The format of the string returned depends on the Time::TimeFormat of the current instance.
	 * @return A time-formated string.
	 */
    std::string toString() const;

    /**
	 * This method returns a USA time-formated string of the time represented by the current instance.
	 * @return A USA time-formated string.
	 */
	std::string toStringUS() const;

    /**
	 * This method returns a Brasilian time-formated string of the time represented by the current instance.
	 * @return A Brasilian time-formated string.
	 */
	std::string toStringBR() const;

	/**
	 * This method returns the number of seconds since 00:00:00 until the time represented bt the current instance.
	 * @return a intenger number of seconds.
	 */
	long toSeconds() const;

	/**
	 * This method returns the TimeFormat utilized to generate strings in this instance.
	 * @return An instance of enumeration TimeFormat that represents the time-formated strings.
	 */
    TimeFormat getTimeFormat() const;

	/**
	 * This method can be used to set the TimeFormat that will be used to generate time-formated string
	 * in the current instance.
	 * @param timeFormat In item of the enumeration TimeFormat that determine the time-formated string format.
	 */
    void setTimeFormat(TimeFormat timeFormat);

public:
	/**
	 * This method return a instance of Time representing the current time of the system.
	 * @return A Time instance representing the current time.
	 */
    static Time getCurrentTime();

	/**
	 * This method converts a number of seconds into a Time using the 00:00:00 as reference.
	 * This convertion is due by adding the seconds to the reference time.
	 * @param seconds The number of seconds to be converted.
	 * @return A Time instance correspondent to the convertion.
	 */
    static Time secondsToTime(long seconds);

public:

	/**
	 * Makes the leftmost instance represent the same time of the rightmost.
	 * @param time The rightmost instance that will be coped.
	 * @return A reference to the leftmost instance.
	 */
	Time& operator=(const Time& time);

	/**
	 * Compare the the leftmost instance with the rightmost.
	 * @return true if they represent the same time; false otherwise.
	 */
	bool operator==(const Time& time) const;

	/**
	 * Compare the the leftmost instance with the rightmost.
	 * @return true if they don't represent the same time; false otherwise.
	 */
	bool operator!=(const Time& time) const;

	/**
	 * Compare the the leftmost instance with the rightmost.
	 * @return true if they leftmost is bigger than the rightmost; false otherwise.
	 */
	bool operator>(const Time& time) const;

	/**
	 * Compare the the leftmost instance with the rightmost.
	 * @return true if they leftmost is equal or bigger than the rightmost; false otherwise.
	 */
	bool operator>=(const Time& time) const;

	/**
	 * Compare the the leftmost instance with the rightmost.
	 * @return true if they leftmost is bigger than the rightmost; false otherwise.
	 */
	bool operator<(const Time& time) const;

	/**
	 * Compare the the leftmost instance with the rightmost.
	 * @return true if they leftmost is equal or minor than the rightmost; false otherwise.
	 */
	bool operator<=(const Time& time) const;

	/**
	 * This methods can be used to calculate a positive offset of the current instance.
	 * @param seconds The number of seconds that will be added to the current instance.
	 * @return A new instance with the offset calculated.
	 */
	Time operator+(const int seconds) const;

	/**
	 * This methods can be used to calculate a negative offset of the current instance.
	 * @param seconds The number of seconds that will be removed from the current instance.
	 * @return A new instance with the offset calculated.
	 */
	Time operator-(const int seconds) const;

	/**
	 * This methods returns the amount of seconds betwen the rightmost and the leftmost times instances.
	 * @param time The date that will be used to calculate the difference.
	 * @return The amount of seconds of difference between the two times.
	 */
	long operator-(const Time& time) const;

	/**
	 * This methods can be used to add a positive offset in the current instance.
	 * @param seconds The number of seconds that will be added to the current instance.
	 */
	void operator+=(const int seconds);

	/**
	 * This methods can be used to add a negative offset in the current instance.
	 * @param seconds The number of seconds that will be removed from the current instance.
	 */
	void operator-=(const int seconds);

	friend std::ostream &operator<<(std::ostream &out,
			const Time& time);

private:
    int hour;
    int minute;
    int second;
    TimeFormat timeFormat;
};

} /* namespace cpputil */
#endif /* TIME_H_ */
