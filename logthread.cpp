
#include <pthread.h>
#include <errno.h>
#include <cstring>
#include <iostream>
using namespace std;
#include "logthread.h"

void LogThread::start (void) throw (ThreadException) {
	cout << "启动线程开始..." << endl;
	pthread_t tid;
	int error = pthread_create (&tid, NULL, run, this);
	if (error)
	{
		throw ThreadException (strerror (error));
	}
	cout << "启动线程完成。" << endl;
}


void* LogThread::run (void* arg) {
	pthread_detach (pthread_self ());
	static_cast<LogThread*> (arg)->run ();
	return NULL;
}
