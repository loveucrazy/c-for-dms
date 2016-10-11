#ifndef _STORETHREAD_H
#define _STORETHREAD_H
#include "logthread.h"
#include "logdao.h"

class StoreThread : public LogThread {
public:
	StoreThread (LogDao& dao);
private:
	void run (void);
	LogDao& m_dao;
};
#endif // _STORETHREAD_H
