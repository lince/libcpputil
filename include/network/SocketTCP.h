#ifndef CLIENTSOCKETTCP_H_
#define CLIENTSOCKETTCP_H_

//#define USE_LOGGER

#include <sys/socket.h>
#include <arpa/inet.h>
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


namespace cpputil {
namespace network {

/**
 * The payload of the packages sent and received by sockets communications.
 */
class DataPayload {
public:
	/**
	 * Constructor for string messages.
	 * This constructor can be used when the payload of the packages is a string message.
	 * @param str The string message.
	 */
	DataPayload(const std::string& str);

	/**
	 * Constructor for byte array payload.
	 * This constructor can be used to hold any format of message coded in a byte array.
	 * @param length The size of the array.
	 * @param data The byte array.
	 * @param copy If true, the byte array will be copied inside the current instance. Default false.
	 */
	DataPayload(const int length, unsigned char* data, bool copy=false);

	/**
	 * Destructor.
	 * The data payload passed as an argument to the constructor will be always deleted.
	 * If you want to keep the date copy=true in the contrusctor.
	 */
	~DataPayload();

	/**
	 * Returns the size in bytes of the data.
	 * @return An integer with the size of the payload.
	 */
	int getLenght();

	/**
	 * Returns a pointer to the data in the current instance.
	 * @return A pointer to the data payload.
	 */
	const unsigned char* getData();

	/**
	 * Converts the data to an std::string and returns it.
	 * @return The string converted.
	 */
	std::string getDataAsString();

private:
	int lenght;
	unsigned char* data;

friend class SocketTCP;
};

class ServerSocketTCP;

/**
 * A TCP Socket used to send and receive messages.
 */
class SocketTCP
#ifdef USE_LOGGER
: public cpputil::logger::Loggable
#endif
  {

public:
	/**
	 * Constructor.
	 * @param ip The IPv4 address of the socket witch the communication will be performed.
	 * @param port The port number of the socket witch the communication will be performed.
	 * @throw IllegalParameterException When the string ip is not a valid IPv4 address.
	 * @throw NetworkException When the socket cannot be created due OS problems.
	 */
	SocketTCP(std::string ip, unsigned short port);

	/**
	 * This methods connects the current instance with the tcp-socket informed by the constructor parameters.
	 * @throw InitializationException If the socket is already connected.
	 * @throw NetworkException If the connected cannot be established.
	 */
	void connectSocket();

	/**
	 * This method is used to receive data from the remote socket.
	 * It's a blocking call. After call receiveDate(), the current thread will be blocked until receive the desired data.
	 * @return An object DataPayload with the data received.
	 * @throw InitializationException If the socket hasn't been connected yet.
	 * @throw NetworkException If some error occurs.
	 */
	DataPayload* receiveData();

	/**
	 * This method is used to send data to the remote socket.
	 * It's a blocking call. After call receiveData(), the current thread will be blocked until the remote socket receive the data.
	 * @param An object DataPayload with the data to send.
	 * @throw InitializationException If the socket hasn't been connected yet.
	 * @throw NetworkException If some error occurs.
	 */
	int sendData(DataPayload* data);

	/**
	 * This method halt the communication with the remote socket.
	 * @throw InitializationException If the socket hasn't been connected yet.
	 */
	void closeConnection();

	/**
	 * Returns the ip adress of the current instance.
	 * @return A string with the ip adress.
	 */
	std::string getIPAddress();

	/**
	 * Returns the port number of the current instance.
	 * @return An integer with the port number.
	 */
	unsigned short getPortNumber();

protected:
	/**
	 * Constructor for already instanceted OS sockets.
	 * This method is used ServerSocketTCP to create the instances of SocketTCP
	 * @param clientSocket The id of the OS socket,
	 * @param clientAddress The ip address of the socket.
	 */
	SocketTCP(int clientSocket, sockaddr_in clientAddres);

private:
	int _socket;
	std::string ipAddress;
	unsigned short portNumber;
	sockaddr_in addres;
	bool isConnected;

#ifdef USE_LOGGER
	cpputil::logger::Logger* logger;
#endif

friend class ServerSocketTCP;
};

}
}

#endif /*CLIENTSOCKETTCP_H_*/
