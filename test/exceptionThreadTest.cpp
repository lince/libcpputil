#include <iostream>
#include <unistd.h>
using namespace std;


#include "../include/Thread.h"
#include "../include/SimpleException.h"
using namespace cpputil;

#include <iostream>
using namespace std;

class MyThread : public Thread {
public:
	void run() {
		this->sleep(3);
		throw SimpleException(
				"Thread had throwed a exception",
				"MyThread",
				"run()");
	}
};

class MyControl : public ThreadExceptionListener {
public:
	void catchExceptionOnThread(cpputil::SimpleException& exception) throw() {
		cout << "Exception capturada: " << exception.what() << endl;
	}
};


int main() {
	MyThread* t = new MyThread();
	MyControl* c = new MyControl();
	t->setExceptionListener(c);
	t->start();
	usleep(6000000);
	return 0;
}
