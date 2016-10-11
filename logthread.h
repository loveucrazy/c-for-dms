#ifndef _LOGTHREAD_H
#define _LOGTHREAD_H
#include "except.h"

class LogThread {
public:
	virtual ~LogThread (void) {}
	void start (void) throw (ThreadException);
private:
	static void* run (void* arg);
	virtual void run (void) = 0;
};
#endif // _LOGTHREAD_H
