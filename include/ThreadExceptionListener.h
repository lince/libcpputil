/*
 * ThreadExceptionListener.h
 *
 *  Created on: Nov 9, 2011
 *      Author: caioviel
 */

#ifndef THREADEXCEPTIONLISTENER_H_
#define THREADEXCEPTIONLISTENER_H_

#include "SimpleException.h"

namespace cpputil {

/**
 * An interface that allows classes to catch exceptions throwed by others threds.
 * Your class must implement this interface and register itself at the exceptions
 * it wishes to catch exceptions.
 * When an exception occurs on that threads, the registerd instance will be notified
 * by the method catchExceptionOnThread. The notification is done by the other thread,
 * and after the conclusion of the method catchExceptionOnThread, the thread will be killed.
 */
class ThreadExceptionListener {
public:
	virtual ~ThreadExceptionListener() {

	}

	/**
	 * Method by which the instances will be notified.
	 * @param exception The exception throwed by the thread.
	 */
	virtual void catchExceptionOnThread(cpputil::SimpleException& exception) throw() = 0;
};

}

#endif /* THREADEXCEPTIONLISTENER_H_ */
