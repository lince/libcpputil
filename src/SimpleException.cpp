/*
 * SimpleException.cpp
 *
 *  Created on: Jul 21, 2011
 *      Author: caioviel
 */

#include "../include/SimpleException.h"

#include <sstream>
//unspecified
namespace cpputil {

SimpleException::SimpleException(
		std::string e) :  errorMsg(e), classStr("unspecified"), methodStr("unspecified") {

	setExceptionSign("cpputil::SimpleException");
}

SimpleException::SimpleException(
		std::string e, std::string c, std::string m) :  errorMsg(e), classStr(c), methodStr(m) {

	setExceptionSign("cpputil::SimpleException");
}

SimpleException::~SimpleException() throw() {

}

void SimpleException::setExceptionSign(std::string exceptionSign) {
	this->exceptionSign = exceptionSign;
}

std::string SimpleException::getClassName() {
	return classStr;
}

std::string SimpleException::getMethodName() {
	return methodStr;
}

std::string SimpleException::getErrorMessage() {
	return errorMsg;
}

std::string SimpleException::getExceptionSign() {
	return exceptionSign;
}

const char* SimpleException::what() const throw() {
	std::stringstream fullMsg;
	fullMsg<<"A '"<<exceptionSign<<"' has been throwed by class <";
	fullMsg<<classStr<<"> at method <"<<methodStr<<">"<<std::endl;
	fullMsg<<"\terror message: "<<errorMsg<<std::endl;
	return fullMsg.str().c_str();
}

} /* namespace cpputil */
