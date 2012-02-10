#ifndef _INITIALIZATIONEXCEPTION_H
#define	_INITIALIZATIONEXCEPTION_H

#include "SimpleException.h"

namespace cpputil {

/**
 *  An exception thrown when some method is called without its requirements been matted.
 *  For instance, if you have a player with a method play(), but needs the method load() been called
 *  before, you should throw an InitializationException if the method play() is called first.
 */
class InitializationException : public cpputil::SimpleException {
public:

	/**
	 * Complete Constructor.
	 * @param errorMsg The error message of the exception.
	 * @param classStr The class where the exception occurred.
	 * @param methodStr The method where the exception occurred.
	 */
	InitializationException(std::string e, std::string c, std::string m) :
			SimpleException (e, c, m){

		setExceptionSign("cpputil::InitializationException");
	}

	/**
	 * Simple Constructor.
	 * @param errorMsg The error message of the exception.
	 */
	InitializationException(std::string e) : SimpleException(e) {
		setExceptionSign("cpputil::InitializationException");
	}
};

} /* namespace cpputil */
#endif	/* _INITIALIZATIONEXCEPTION_H */

