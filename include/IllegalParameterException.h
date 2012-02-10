#ifndef ILLEGALPARAMETEREXPECTION_H_
#define ILLEGALPARAMETEREXPECTION_H_

#include "SimpleException.h"

namespace cpputil {

/**
 * An exception used to sinalize invalid or wrong arguments past to methods.
 * This class extends the SimpleException class.
 */
class IllegalParameterException : public cpputil::SimpleException  {
public:

	/**
	 * Complete Constructor.
	 * @param errorMsg The error message of the exception.
	 * @param classStr The class where the exception occurred.
	 * @param methodStr The method where the exception occurred.
	 */
	IllegalParameterException(std::string e, std::string c, std::string m) :
			SimpleException (e, c, m) {

		setExceptionSign("cpputil::IllegalParameterException");
	}

	/**
	 * Simple Constructor.
	 * @param errorMsg The error message of the exception.
	 */
	IllegalParameterException(std::string e) : SimpleException(e) {
		setExceptionSign("cpputil::IllegalParameterException");
	}
};

} /* namespace cpputil */
#endif /* ILLEGALPARAMETEREXPECTION_H_ */
