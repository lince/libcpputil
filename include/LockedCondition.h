/*
 * LockedCondition.h
 *
 *  Created on: Nov 15, 2011
 *      Author: caioviel
 */

#ifndef LOCKEDCONDITION_H_
#define LOCKEDCONDITION_H_

#include <pthread.h>

namespace cpputil {

/**
 * This class can be used to create thread-blocking conditions.
 * When the method waitCondition is called, the current thread will be blocked until
 * some thread call the method signal.
 */
class LockedCondition {
public:

	/**
	 * Constructor
	 */
	LockedCondition();

	/**
	 * Destructor
	 */
	virtual ~LockedCondition();

	/**
	 * This method will block the current thread until the method signal() be called.
	 */
	void waitCondition();

	/**
	 * This method will block the current thread until the method signal() be called or
	 * a timeout occur.
	 * @param millisecons The maxinum amount of time that the thread will wait until be unblocked.
	 * @return true, if the thread was unblocked by a timeout; false, otherwise.
	 */
	bool waitCondition(int milliseconds);

	/**
	 * This method will unblock threads that had called waitCondition method.
	 */
	void signal();

	/**
	 * This method can be used to discover if the LockedCondition instance is locked.
	 * @return true, if the instance is locked; false, otherwise.
	 */
	bool isWaiting();

private:
	pthread_mutex_t waitCondMutex;
	pthread_cond_t waitCond;
	bool waiting;
};

} /* namespace cpputil */
#endif /* LOCKEDCONDITION_H_ */
