/*
 * LoggerNetworkStream.h
 *
 *  Created on: Jul 21, 2011
 *      Author: caioviel
 */

#ifndef LOGGERNETWORKSTREAM_H_
#define LOGGERNETWORKSTREAM_H_

#include "Logger.h"

#include "../network/SocketTCP.h"

namespace cpputil {
namespace logger {

/**
 * A concrete logger that sends the log messagens via network protocols to a servere.
 */
class LoggerNetworkStream: public cpputil::logger::Logger {
public:
	/**
	 * Enumaration that holds the supported network protocols.
	 * Actualy only the TCP protocol is supported.
	 */
	enum Protocol {UDP, TCP};

public:
	/**
	 * Constructor.
	 * @param protocol The protocol to be used.
	 * @param ipAddres A string with the Ip Address of the logger server.
	 * @param portNumber The port number of the logger server.
	 * @param loggerLvl The lowest LoggerLvl messages to be posted.
	 * @throw NotImplementedException If try to use UDP protocol.
	 */
	LoggerNetworkStream(Protocol protocol,
						std::string ipAddres,
						unsigned short portNumber,
						Logger::LoggerLvl loggerLvl);

	/**
	 * Destructor.
	 */
	virtual ~LoggerNetworkStream();

protected:
	/**
	 * Connects to the logger server.
	 * @throw cpputil::network::NetworkException If some network problem occurs.
	 */
	void connectToLoggerServer();

	/**
	 * @throw cpputil::network::NetworkException If some network problem occurs
	 */
	virtual void internalMessage(std::string completeMessage, Logger::LoggerLvl lvl);

private:
	Protocol protocol;
	std::string idAddres;
	unsigned short portNumber;
	cpputil::network::SocketTCP* socketTCP;
};

} /* namespace logger */
} /* namespace cpputil */
#endif /* LOGGERNETWORKSTREAM_H_ */
