/*Nota.
 Esta classe não foi desenvolvida por nós. Apenas a adaptamos para utilizar no miniprojeto.

 A versão original desta classe pode ser encontrada em:
 http://svn.softwarepublico.gov.br/trac/ginga/browser/telemidia-util-cpp/trunk/include/Thread.h
 http://svn.softwarepublico.gov.br/trac/ginga/browser/telemidia-util-cpp/trunk/src/Thread.cpp

 É necessário se cadastrar no site http://www.softwarepublico.gov.br/ para ter acesso ao svn.
 */

#ifndef THREAD_H_
#define THREAD_H_

#include <pthread.h>

#include "ThreadExceptionListener.h"

namespace cpputil {

/**
 * This abstracted class can be used to create and control threads in a Java-Like style.
 * Any class that extend Thread will must implement the method run. When the method
 * start is called, a new thread will be started and the method run will be executed
 * by the new thread.
 */

class Thread {
public:
	/*
	 * Constructor.
	 * It must be called by all the classes that extends this.
	 */
	Thread();

	/**
	 * Destrutor.
	 */
	virtual ~Thread();

	/**
	 * This methods starts the execution of the thread.
	 */
	virtual void start();

	/**
	 * This methods makes the thread sleeps for a specified time.
	 * @param seconds Time that the thread will sleep in seconds.
	 * @return true, if the thread had sleepet the specified time; false, if had woke up befero the time.
	 */
	bool sleep(long int seconds);

	/**
	 * This methods makes the thread sleeps for a specified time.
	 * @param milliseconds Time that the thread will sleep in milliseconds.
	 * @return true, if the thread had sleepet the specified time; false, if had woke up befero the time.
	 */
	bool usleep(long int milliseconds);

	/**
	 * This method wake up an sleeping thread.
	 */
	void wakeUp();

	/**
	 * This method can be used to generate mutual exclusion in the thread, locking a
	 * region.
	 * @sa Mutex
	 */
	void lock();

	/**
	 * This method can be used to generate mutual exclusion in the thread, unlocking a
	 * region.
	 * @sa Mutex
	 */
	void unlock();

	/**
	 * This method can be used to make the thread wait for an condition to be matt.
	 * @sa LockedCondition
	 */
	void waitForUnlockCondition();

	/**
	 * This method sinalize that the condition by which the thread was waiting was matted.
	 * @sa LockedCondition
	 */
	bool unlockConditionSatisfied();

	/**
	 * Register the instance of ThreadExceptionListener that will handle the
	 * exceptions throwed by the thread.
	 * @param listener The instance that will catch the exceptions.
	 */
	void setExceptionListener(ThreadExceptionListener* listener);

protected:

	/**
	 * This is the method by which the thread will start its execution.
	 * This method must be implemented by all the class that extends Thread.
	 */
	virtual void run() = 0;

	pthread_mutex_t threadMutex;
	bool isSleeping;

	pthread_mutex_t threadFlagMutex;
	pthread_cond_t threadFlagConditionVariable;
	bool isWaiting;

	pthread_mutex_t threadFlagMutexLockUntilSignal;
	pthread_cond_t threadFlagCVLockUntilSignal;

private:
	ThreadExceptionListener* exceptionlistener;
	pthread_t threadId_;
	static void* function(void* ptr);
};


}

#endif /*THREAD_H_*/
