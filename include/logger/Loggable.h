/*
 * Loggable.h
 *
 *  Created on: Jul 20, 2011
 *      Author: caioviel
 */

#ifndef LOGGABLE_H_
#define LOGGABLE_H_

#include <string>

namespace cpputil {
namespace logger {

class Logger;

/**
 * This abstract class must be implemented by all classes what whises to be logged.
 */
class Loggable {
public:

	/**
	 * Old-Style Constructor.
	 * @deprecated Use the named Constructor instead.
	 */
	Loggable();

	/**
	 * Named Constructor
	 * @param className The name of the instance that will be logged.
	 */
	Loggable(std::string className);

	virtual ~Loggable();

	/**
	 * Callback method for the logger.
	 */
	virtual void callBackLogger();

protected:

	/**
	 * This method emits log messages with TRACE level.
	 * @param str The message to be logged.
	 */
	void trace(std::string str);

	/**
	 * This method emits log messages with DEBUG level.
	 * @param str The message to be logged.
	 */
	void debug(std::string str);

	/**
	 * This method emits log messages with INFO level.
	 * @param str The message to be logged.
	 */
	void info(std::string str);

	/**
	 * This method emits log messages with WARNING level.
	 * @param str The message to be logged.
	 */
	void warning(std::string str);

	/**
	 * This method emits log messages with ERROR level.
	 * @param str The message to be logged.
	 */
	void error(std::string str);

	/**
	 * This method emits log messages with FATAL level.
	 * @param str The message to be logged.
	 */
	void fatal(std::string str);

	/**
	 * This method is used to unregister the instance of the logger
	 */
	void unregister();

private:
	Logger* logger;

};



} /* namespace logger */
} /* namespace cpputil */
#endif /* LOGGABLE_H_ */
