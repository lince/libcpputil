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

class Time {
public:
	enum TimeFormat {
		US_FORMAT,
		BR_FORMAT
	};

public:
	Time(int h, int m, int s);

	Time(const Time& time);

	virtual ~Time();

	void setTime(int h, int m, int s);

	void setTime(const Time& time);

    int getHour() const;

    int getMinute() const;

    int getSecond() const;

    void setHour(int hour);

    void setMinute(int minute);

    void setSecond(int second);

	std::string toStringUS() const;

	std::string toStringBR() const;

	std::string toString() const;

	int toSeconds() const;

public:
    static Time getCurrentTime();

    static Time secondsToTime(int seconds);

public:
	Time operator+(const int seconds) const;

	Time operator-(const int seconds) const;

	Time operator-(const Time& time) const;

	Time& operator=(const Time& time);

	bool operator==(const Time& time) const;

	bool operator!=(const Time& time) const;

	bool operator>(const Time& time) const;

	bool operator>=(const Time& time) const;

	bool operator<(const Time& time) const;

	bool operator<=(const Time& time) const;

	void operator+=(const int seconds);

	void operator-=(const int seconds);

    TimeFormat getTimeFormat() const;

    void setTimeFormat(TimeFormat timeFormat);

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
