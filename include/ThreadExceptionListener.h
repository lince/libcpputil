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

class ThreadExceptionListener {
public:
	virtual ~ThreadExceptionListener() {

	}

	virtual void catchExceptionOnThread(cpputil::SimpleException& exception) throw() = 0;
};

}

#endif /* THREADEXCEPTIONLISTENER_H_ */
