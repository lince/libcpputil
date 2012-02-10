/*
 * LoggerLogFile.h
 *
 *  Created on: Jul 21, 2011
 *      Author: caioviel
 */

#ifndef LOGGERLOGFILE_H_
#define LOGGERLOGFILE_H_

#include <fstream>

#include "Logger.h"

namespace cpputil {
namespace logger {

/**
 * A concrete logger that save the log messages into a file.
 */
class LoggerLogFile: public cpputil::logger::Logger {
public:

	/**
	 * Enumeration that holds the possibles write modes.
	 * - APPEND_FILE: If the file exits, it starts to write on the end,
	 * - OVERWRITE_FILE: If the file exits, overwrite the file.
	 */
	enum WriteMode {
		APPEND_FILE,
		OVERWRITE_FILE,
	};

public:
	/**
	 * Constructor
	 * @param fileName The name of the file where the messages will be logged.
	 * @param writemode The WriteMode used to open the file.
	 * @param loggerLvl The lowest LoggerLvl to be posted.
	 * @throw LoggerException If it wasn't able to open the file.
	 */
	LoggerLogFile(std::string fileName, WriteMode writemode, Logger::LoggerLvl loggerLvl);

protected:
	virtual void internalMessage(std::string completeMessage, LoggerLvl lvl);

private:
	WriteMode writemode;
	std::string fileName;
	std::fstream file;
};

} /* namespace logger */
} /* namespace cpputil */
#endif /* LOGGERLOGFILE_H_ */
