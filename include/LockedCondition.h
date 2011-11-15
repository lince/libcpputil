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

class LockedCondition {
public:
	LockedCondition();
	virtual ~LockedCondition();
	void waitCondition();
	bool waitCondition(int milliseconds);
	void signal();
	bool isWaiting();

private:
	pthread_mutex_t waitCondMutex;
	pthread_cond_t waitCond;
	bool waiting;
};

} /* namespace cpputil */
#endif /* LOCKEDCONDITION_H_ */
