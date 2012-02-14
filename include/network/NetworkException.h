#ifndef NETWORKEXCEPTION_H_
#define NETWORKEXCEPTION_H_

#include "../SimpleException.h"

namespace cpputil {
namespace network {

/**
 * An exception throwed when some network problem occurs.
 */
class NetworkException : public cpputil::SimpleException {
public:

	/**
	 * Constructor
	 * @param e The raw error message.
	 * @param c The class where the exception was throwed.
	 * @param m The method where the exceptin was throwed.
	 */
	NetworkException(std::string e, std::string c, std::string m) :
			SimpleException (e, c, m){

		setExceptionSign("cpputil::network::NetworkException");
	}
};


} /* namespace cpputil */
} /* namespace network */
#endif /* NETWORKEXCEPTION_H_ */
