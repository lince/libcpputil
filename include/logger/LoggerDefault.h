/*
 * LoggerDefault.h
 *
 *  Created on: Jul 20, 2011
 *      Author: caioviel
 */

#ifndef LOGGERDEFAULT_H_
#define LOGGERDEFAULT_H_

#include "Logger.h"

namespace cpputil {
namespace logger {

/**
 * The simplest concrete array that prints the messages on the standard output stream.
 */
class LoggerDefault : public Logger {
public:

	/**
	 * Constructor.
	 * @param loggerLvl The lowest loggerLvl that will be reported.
	 */
	LoggerDefault(Logger::LoggerLvl loggerLvl);

protected:
	virtual void internalMessage(std::string completeMessage, LoggerLvl lvl);
};

} /* namespace logger */
} /* namespace cpputil */
#endif /* LOGGERDEFAULT_H_ */
