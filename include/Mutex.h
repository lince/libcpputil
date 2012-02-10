/*
 * Mutex.h
 *
 *  Created on: Sep 19, 2011
 *      Author: caioviel
 */

#ifndef MUTEX_H_
#define MUTEX_H_

#include <string>
#include <pthread.h>
#include <map>

namespace cpputil {

/**
 * This class can be used to ensure mutual exclusion of threads.
 * It can be usefull to keep consistency of shared data structures or variables.
 */
class Mutex {
public:
	/**
	 * Simple Constructor
	 */
	Mutex();

	/**
	 * Named Constructor.
	 * Naming a Mutex, it can be easily retrieved in others threads without
	 * passing it as a pointer or reference.
	 * @param name The name of the Mutex.
	 */
	Mutex(std::string name);

	/**
	 * Destructor
	 */
	virtual ~Mutex();

	/**
	 * Lock the area of mutual exclusion for any other thread.
	 */
	void lock();

	/**
	 * Unlock the are of mutal exclusion for others threads.
	 */
	void unlock();

public:
	/**
	 * This methods allows to get a pointer to a previously created named Mutex.
	 * @param name The name of the Mutex to be retrieved.
	 * @return A pointer to named Mutex.
	 * @throw IllegalParameterException When there isn't a Mutex with the specified name.
	 */
	static Mutex* getNamedMutex(std::string name);

private:
	pthread_mutex_t linux_mutex;
	std::string name;

	static std::map<std::string, Mutex*> namedMutex;

};

} /* namespace cpputil */
#endif /* MUTEX_H_ */
