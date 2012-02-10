/*
 * SimpleException.h
 *
 *  Created on: Jul 21, 2011
 *      Author: caioviel
 */

#ifndef SIMPLEEXCEPTION_H_
#define SIMPLEEXCEPTION_H_

#include <exception>
#include <string>

namespace cpputil {

/**
 * This class can be used as a general-purpose exception or extented to create specific-purpose exception.
 * It's very simple to create new exceptions using this class, see an exemple at IllegalParameterException.
 * The SimpleException extends the std::exception for compatibility issues.
 */
class SimpleException : public std::exception {
public:

	/**
	 * Simple Constructor.
	 * This constructor allow to create simple exceptions with just the error message.
	 * @param errorMsg The error message of the exception.
	 */
	SimpleException(
			std::string errorMsg);

	/**
	 * Complete Constructor.
	 * Using this contructor is possible to inform the method and class where the exception was throwed.
	 * @param errorMsg The error message of the exception.
	 * @param classStr The class where the exception occurred.
	 * @param methodStr The method where the exception occurred.
	 */
	SimpleException(
			std::string errorMsg,
			std::string classStr,
			std::string methodStr);

	/**
	 * Destructor.
	 */
	virtual ~SimpleException() throw();

	/**
	 * This method returns the complete message of the exception.
	 * It was overwrited from std::exception.
	 */
	virtual const char* what() const throw();

	/**
	 * This method returns the exception sign.
	 * @return string holding the exception sing.
	 */
	virtual std::string getExceptionSign();

	/**
	 * This method returns the name of the class that throws the exception.
	 * @return string holding the class name.
	 */
	virtual std::string getClassName();

	/**
	 * This method returns the name of the method that throws the exception.
	 * @return string holding the method name.
	 */
	virtual std::string getMethodName();

	/**
	 * This method returns error message of the exception.
	 * @return string holding the error message.
	 */
	virtual std::string getErrorMessage();

protected:
	/**
	 * This method is used to set he Exception Sign (name) of the classes that extented
	 * SimpleException.
	 * This method shuld be called in the constructor of the extensions of SimpleException.
	 * @param exceptionSign The Sign of the exception.
	 */
	virtual void setExceptionSign(std::string exceptionSign);

private:
	std::string classStr, methodStr, errorMsg;
	std::string exceptionSign;
};

} /* namespace cpputil */
#endif /* SIMPLEEXCEPTION_H_ */
