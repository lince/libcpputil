/*
 * NotImplementedException.h
 *
 *  Created on: Sep 14, 2011
 *      Author: caioviel
 */

#ifndef NOTIMPLEMENTEDEXCEPTION_H_
#define NOTIMPLEMENTEDEXCEPTION_H_

#include "SimpleException.h"

namespace cpputil {

/**
 *  An exception thrown when some feature that are not currently implemented is called.
 */
class NotImplementedException: public cpputil::SimpleException {
public:

	/**
	 * Complete Constructor.
	 * @param errorMsg The error message of the exception.
	 * @param classStr The class where the exception occurred.
	 * @param methodStr The method where the exception occurred.
	 */
	NotImplementedException(std::string e, std::string c, std::string m) :
		SimpleException(e, c, m) {

		setExceptionSign("cpputil::NotImplementedException");
	}

	/**
	 * Simple Constructor.
	 * @param errorMsg The error message of the exception.
	 */
	NotImplementedException(std::string e) : SimpleException(e) {
		setExceptionSign("cpputil::NotImplementedException");
	}
};

} /* namespace cpputil */
#endif /* NOTIMPLEMENTEDEXCEPTION_H_ */
