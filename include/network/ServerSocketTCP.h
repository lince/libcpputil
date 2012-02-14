#ifndef SERVERSOCKETTPC_H_
#define SERVERSOCKETTPC_H_

#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <string>
#include <unistd.h>
#include <netinet/in.h>
#include <iostream>

#include "../Functions.h"
#include "../InitializationException.h"
#include "../IllegalParameterException.h"

#ifdef USE_LOGGER
#include "../logger/Logger.h"
#endif

#include "NetworkException.h"

#include "SocketTCP.h"

namespace cpputil {
namespace network {

/**
 * This class create TCP Servers which allows other SocketTCP to connetec.
 */
class ServerSocketTCP
#ifdef USE_LOGGER
: public cpputil::logger::Loggable
#endif
  {
public:
	/**
	 * Constructor.
	 * @param port The port which the server socket will be created.
	 * @throw NetworkException If the socket cannot be created.
	 */
	ServerSocketTCP(unsigned short port);

	/**
	 * Destructor.
	 */
	virtual ~ServerSocketTCP();

	/**
	 * This method binds the ports in the OS, allowing other sockets to connect.
	 * @throw NetworkException If the bind cannot be realised.
	 */
	void bindPort();

	/**
	 * This method makes the ServerSocketTCP instance starts to listen to connections.
	 * When a connection is received it will be put in a queue. The maximun size of
	 * the queue depends on the OS. In Linux implementations it's usually 128.
	 * After this limit is reached, new connections will be refused.
	 * @throw NetworkException If some error occurs.
	 */
	void startListen();

	/**
	 * This method makes the ServerSocketTCP instance starts to listen to connections and allows to dermine the size of the queue.
	 * After the queeq limit size is reached, new connections will be refused.
	 * @param max Size of the queue.
	 * @throw IllegalParameterException If max > 128 or max < 1
	 * @throw NetworkException If some error occurs.
	 */
	void startListen(unsigned int max);

	/**
	 * This methods makes the ServerSocketTCP wait for a remote connection.
	 * It's a blocking method. After call it the current instance will be blocked until the server socket receive a connection.
	 * If it's already connectins wainting in the queue, it will just accept the firts connection.
	 * @return An instance os SocketTCP already configurated to communicate with the remote socket.
	 * @throw NetworkException If some error occurs.
	 */
	SocketTCP* acceptConnection();

	/**
	 * This methdos unbind the port of the socket server.
	 * @throw InitializationException If the port ins't binded.
	 * @throw NetworkException If some error occurs.
	 */
	void releasePort();

protected:
	unsigned short portNumber;

private:
	int serverSocket;
	sockaddr_in serverAddress;
	bool isBinded;
#ifdef USE_LOGGER
	cpputil::logger::Logger* logger;
#endif

};

}
}

#endif /*SERVERSOCKETTPC_H_*/
