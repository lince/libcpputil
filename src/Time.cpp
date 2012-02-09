/*
 * Time.cpp
 *
 *   Created on: Feb 9, 2012
 *  Last Chance: 10:10:40 AM
 *       Author: caioviel
 *       E-mail: caio_viel@dc.ufscar.br
 */

#include "../include/IllegalParameterException.h";

#include "../include/Functions.h"

#include "../include/Time.h"

#include <ctime>
#include <ctype.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/timeb.h>
#include <sys/time.h>

#include <ctime>
#include <ctype.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/timeb.h>
#include <sys/time.h>

namespace cpputil {

Time::Time(int h, int m, int s) {
	setTime(h, m, s);
	setTimeFormat(Time::US_FORMAT);
}

Time::~Time() {

}

void Time::setTime(const Time& time) {
	this->hour = time.hour;
	this->minute = time.minute;
	this->second = time.second;
}

int Time::getHour() const {
	return hour;
}

int Time::getMinute() const {
	return minute;
}

int Time::getSecond() const {
	return second;
}

void Time::setHour(int hour) {
	if (hour >= 0 && hour <= 23) {
		this->hour = hour;
	} else {
		throw IllegalParameterException(
				"Invalid value for hour: " + Functions::numberToString(hour),
				"cpputil::Time",
				"setHour(int)");
	}
}

void Time::setMinute(int minute) {
	if (minute >= 0 && minute <= 59) {
		this->minute = minute;
	} else {
		throw IllegalParameterException(
				"Invalid value for minute: " + Functions::numberToString(minute),
				"cpputil::Time",
				"setMinute(int)");
	}
}

void Time::setSecond(int second) {
	if (second >= 0 && second <= 59) {
		this->second = second;
	} else {
		throw IllegalParameterException(
				"Invalid value for second: " + Functions::numberToString(second),
				"cpputil::Time",
				"setSecond(int)");
	}
}

Time::TimeFormat Time::getTimeFormat() const {
	return timeFormat;
}

Time::Time(const Time & time) {
	this->hour = time.hour;
	this->minute = time.minute;
	this->second = time.second;
	this->timeFormat = time.timeFormat;
}

void Time::setTime(int h, int m, int s) {
	setHour(h);
	setMinute(m);
	setSecond(s);
}

std::string Time::toStringUS() const {
	std::string aux = "";
	if (this->hour <= 12) {
		if (this->hour < 10) {
			aux += "0";
		}
		aux += Functions::numberToString(this->hour) + ":";
		if (this->minute < 10) {
			aux += "0";
		}
		aux += Functions::numberToString(this->minute) + ":";
		if (this->second < 10) {
			aux += "0";
		}
		aux += Functions::numberToString(this->second) + " AM";
	} else {
		if ((this->hour -12) < 10) {
			aux += "0";
		}
		aux = Functions::numberToString(this->hour - 12) + ":";
		if (this->minute < 10) {
			aux += "0";
		}
		aux += Functions::numberToString(this->minute) + ":";
		if (this->minute < 10) {
			aux += "0";
		}
		aux += Functions::numberToString(this->second) + " PM";
	}
	return aux;
}

std::string Time::toStringBR() const {
	std::string aux = "";
	if (this->hour < 10) {
		aux += "0";
	}
	aux += Functions::numberToString(this->hour) + ":";
	if (this->minute < 10) {
		aux += "0";
	}
	aux += Functions::numberToString(this->minute) + ":";
	if (this->second < 10) {
		aux += "0";
	}
	aux += Functions::numberToString(this->second);
	return aux;

}

std::string Time::toString() const {
	if (this->timeFormat == Time::US_FORMAT) {
		return toStringUS();
	} else {
		return toStringBR();
	}
}

Time Time::getCurrentTime() {
	time_t rawtime;
	struct tm * timeinfo;
	time ( &rawtime );
	timeinfo = localtime ( &rawtime );

	Time nTime(timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
	//delete timeinfo;
	return nTime;
}

Time Time::operator +(const int seconds) const {
	Time auxTime(*this);
	auxTime.second += seconds;
	if (auxTime.second >= 60) {
		int minutes = auxTime.second / 60;
		auxTime.second = auxTime.second % 60;
		auxTime.minute += minutes;
	}

	if (auxTime.minute >= 60) {
		int hours = auxTime.minute / 60;
		auxTime.minute = auxTime.minute % 60;
		auxTime.hour += hours;
	}

	if (auxTime.hour >= 24) {
		auxTime.hour = auxTime.hour % 24;
	}
	return auxTime;
}

Time Time::operator -(const int seconds) const {
	Time auxTime(*this);
	auxTime.second -= seconds;
	while (auxTime.second < 0) {
		auxTime.second += 60;
		auxTime.minute -= 1;
	}

	while (auxTime.minute < 0) {
		auxTime.minute += 60;
		auxTime.hour -= 1;
	}

	while (auxTime.hour < 0) {
		auxTime.hour += 24;
	}
	return auxTime;
}

int Time::toSeconds() const {
	return this->second + this->minute*60 + this->hour*3600;
}

Time Time::operator -(const Time & time) const {
	return *this - time.toSeconds();
}

Time & Time::operator =(const Time & time) {
	if (&time != this) {
		this->hour = time.hour;
		this->minute = time.minute;
		this->second = time.second;
		this->timeFormat = time.timeFormat;
	}
	return *this;
}

bool Time::operator ==(const Time & time) const {
	return (this->hour == time.hour &&
			this->minute == time.minute &&
			this->second == time.second);
}

bool Time::operator !=(const Time & time) const {
	return !(*this == time);
}

bool Time::operator >(const Time & time) const {
	if (this->hour > time.hour) {
		return true;
	} else if (this->hour == time.hour) {
		if (this->minute > time.minute) {
			return true;
		} else if (this->minute == time.minute) {
			if (this->second > time.second) {
				return true;
			}
		}
	}
	return false;
}

bool Time::operator >=(const Time & time) const {
	if (this->hour > time.hour) {
		return true;
	} else if (this->hour == time.hour) {
		if (this->minute > time.minute) {
			return true;
		} else if (this->minute == time.minute) {
			if (this->second >= time.second) {
				return true;
			}
		}
	}
	return false;
}

bool Time::operator <(const Time & time) const {
	if (this->hour < time.hour) {
		return true;
	} else if (this->hour == time.hour) {
		if (this->minute < time.minute) {
			return true;
		} else if (this->minute == time.minute) {
			if (this->second < time.second) {
				return true;
			}
		}
	}
	return false;
}

void Time::operator+=(const int seconds) {
	*this = *this + seconds;
}

void Time::operator-=(const int seconds) {
	*this = *this - seconds;
}

bool Time::operator <=(const Time & time) const {
	if (this->hour < time.hour) {
		return true;
	} else if (this->hour == time.hour) {
		if (this->minute < time.minute) {
			return true;
		} else if (this->minute == time.minute) {
			if (this->second <= time.second) {
				return true;
			}
		}
	}
	return false;
}

void Time::setTimeFormat(TimeFormat timeFormat) {
	this->timeFormat = timeFormat;
}

Time Time::secondsToTime(int seconds) {
	Time aux(0,0,0);
	aux += seconds;
	return aux;
}

std::ostream &operator<<(std::ostream &out, const Time& time) {
	out << time.toString();
	return out;
}

/* namespace cpputil */
}

