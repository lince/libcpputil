/*
 * LoggerException.h
 *
 *  Created on: Jul 21, 2011
 *      Author: caioviel
 */

#ifndef LOGGEREXCEPTION_H_
#define LOGGEREXCEPTION_H_

#include "../SimpleException.h"

namespace cpputil {
namespace logger {

/**
 * Exception throwed by the classes of module cpputil::logger.
 */
class LoggerException: public cpputil::SimpleException {
public:

	/**
	 * Constructor.
	 * @param e The raw message.
	 * @param c The name of the class that throwed the exception.
	 * @param m The name of the method that throwed the exception.
	 */
	LoggerException(std::string e, std::string c, std::string m) :
			SimpleException (e, c, m){
		setExceptionSign("cpputil::logger::LoggerException");
	}

};

} /* namespace logger */
} /* namespace cpputil */
#endif /* LOGGEREXCEPTION_H_ */
