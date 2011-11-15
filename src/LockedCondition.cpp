/*
 * LockedCondition.cpp
 *
 *  Created on: Nov 15, 2011
 *      Author: caioviel
 */

#include "../include/LockedCondition.h"

#include <sys/time.h>
#include <errno.h>

namespace cpputil {

LockedCondition::LockedCondition() {
	pthread_mutex_init(&waitCondMutex, NULL);

	waiting = false;
	pthread_cond_init(&waitCond, NULL);
}

LockedCondition::~LockedCondition() {
	pthread_cond_signal(&waitCond);
	pthread_cond_destroy(&waitCond);

	pthread_mutex_unlock(&waitCondMutex);
	pthread_mutex_destroy(&waitCondMutex);
}

void LockedCondition::waitCondition() {
	pthread_mutex_lock(&waitCondMutex);
	waiting = true;
	pthread_cond_wait(
		    &waitCond,
		    &waitCondMutex);
	waiting = false;
	pthread_mutex_unlock(&waitCondMutex);
}

bool LockedCondition::waitCondition(int milliseconds) {
	int res;
	struct timeval time;
	struct timespec timeOut;

	gettimeofday(&time, NULL);
	timeOut.tv_sec = time.tv_sec + (long int)(milliseconds / 1000);
	long int micro;
	micro = ((milliseconds%1000) * 1000) + time.tv_usec;
	if (micro > 1000000) {
		timeOut.tv_sec++;
		micro -= 1000000;
	}

	timeOut.tv_nsec = micro * 1000;

	pthread_mutex_lock(&waitCondMutex);
	waiting = true;
	res = pthread_cond_timedwait(
		    &waitCond,
		    &waitCondMutex,
		    (const struct timespec*)(&timeOut));

	pthread_mutex_unlock(&waitCondMutex);
	waiting = false;
	return (res == ETIMEDOUT);
}

void LockedCondition::signal() {
	if (waiting) {
		pthread_cond_signal(&waitCond);
	}
	waiting = false;
}

bool LockedCondition::isWaiting() {
	return waiting;
}

} /* namespace cpputil */
