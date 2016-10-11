
#include <iostream>
using namespace std;
#include "storethread.h"
#include "logqueue.h"

StoreThread::StoreThread (LogDao& dao) : m_dao (dao) {}

void StoreThread::run (void) {
	MLogRec log;
	for (;;) {
		g_logQueue >> log;
		try {
			m_dao.insert (log);
		}
		catch (DBException& ex) {
			cout << ex.what () << endl;
		}
	}
}
