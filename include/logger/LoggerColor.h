/*
 * LoggerColor.h
 *
 *  Created on: Sep 16, 2011
 *      Author: caioviel
 */

#ifndef LOGGERCOLOR_H_
#define LOGGERCOLOR_H_

#include "Logger.h"

namespace cpputil {
namespace logger {

/**
 * A concrete Logger that prints colored messages on the standard output stream.
 * The colors are associeted with the LoggerLvl, this way a ERROR message can be red
 * and a INFO message can be BLUE.
 */
class LoggerColor: public cpputil::logger::Logger {
public:

	/**
	 * Enumeration that holds the colors options for the logs messages.
	 */
	enum Color {
		BLACK=0, RED, GREEN, BROWN, BLUE, MAGENTA, CYAN,
		GRAY, DARK_GRAY, LIGHT_RED, LIGHT_GREEN, YELLOW,
		LIGHT_BLUE, LIGHT_MAGENTA, LIGHT_CYAN, WHITE,
		DEFAULT};

	/**
	 * Constructor.
	 * @param loggerLvl The lowest loggerLvl that will be reported.
	 * @param A array with the colors that will be used by which message category.
	 */
	LoggerColor(Logger::LoggerLvl loggerLvl, Color* colors=NULL);

public:
	/**
	 * Converts the a string into a Color item.
	 * @param str The string to be converted.
	 * @return A Color Item.
	 * @throw LoggerException If the string is invalid.
	 */
	static Color stringToColor(std::string str);

	/**
	 * Converts the a Color item to a string representation.
	 * @param color the Color item to be converted.
	 * @return The string with the name of the color.
	 */
	static std::string colorToString(Color color);

	/**
	 * Return an array with the default colors of wich message category.
	 */
	static Color* getDefaultColors();

protected:
	virtual void internalMessage(std::string completeMessage, LoggerLvl lvl);

private:
	static std::string colorsStr[];
	Color* colors;
};

} /* namespace logger */
} /* namespace cpputil */
#endif /* LOGGERCOLOR_H_ */
