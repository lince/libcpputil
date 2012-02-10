/*
 * Functions.h
 *
 *  Created on: Jul 15, 2011
 *      Author: caioviel
 */

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include <string>
#include "Time.h"
#include "Date.h"

namespace cpputil {

/**
 * This class wrappers static functions for string manipulation an several others utilitary functions.
 */
class Functions {
public:
	/**
	 * Virtual Descructors
	 */
	virtual ~Functions() {

	}

	/**
	 * Converts a number into a std::string.
	 * @param value A number.
	 * @return A string with the representation of the number.
	 */
	static std::string numberToString(double value);

	/**
	 * This methods returns the current date.
	 * @return An instance of Date class representing the current date.
	 * @deprecated Use class Date instead.
	 */
	static Date getCurrentDate();

	/**
	 * This methods returns the current time.
	 * @return An instance of Time class representing the current time.
	 * @deprecated Use class Time instead.
	 */
	static Time getCurrentTime();

	/**
	 * This methods returns a timestamp in US Date/Time Style.
	 * @return An string contains a US-Style timestamp.
	 */
	static std::string getCurrentTimestampUS();

	/**
	 * This method returns a timestamp in Brazilian Date/Time Style.
	 * @return An string contains a Brazilian-Style timestamp.
	 */
	static std::string getCurrentTimestampBR();

	/**
	 * This method returns a number representing the system time with millisecond pression.
	 * @return a double representing the number
	 */
	static double getCurrentTimeMillis();

    /**
     * This method Verifies if the string is a valid IPv4 address.
     * @param ip A string with a IP address
     * @return true, if it's a valid IPv4 address; false, otherwise.
     */
    static bool isIPv4(std::string ip);

    /**
     * This method Verifies if the string is a valid IPv6 address.
     * @param ip A string with a IP address
     * @return true, if it's a valid IPv6 address; false, otherwise.
     */
    static bool isIPv6(std::string ip);

    /**
     * This method generates an Universally unique identifier.
     * @return A string with the UUID generated.
     */
    static std::string generateUUID();

    /**
     * This method converts an string to uppercase.
     * @param str The string to be converted.
     * @return The uppercased string.
     */
    static std::string toUpperCase(const std::string& str);

    /**
     * This method converts an string to lowercase.
     * @param str The string to be converted.
     * @return The lowercased string.
     */
    static std::string toLowerCase(const std::string& str);

    /**
     * This method convert booleans values to strings.
     * @param value The boolean value to be converted.
     * @return A string "true" or a string "false".
     */
    static std::string boolToString(const bool value);

};

} /* namespace cpputil */
#endif /* FUNCTIONS_H_ */
