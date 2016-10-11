
#include <iostream>
using namespace std;
#include "logqueue.h"
#define MAX_LOGS 1024*1024
LogQueue g_logQueue;
LogQueue::LogQueue (void) {
	pthread_mutex_init (&m_mutex, 0);
	pthread_cond_init (&m_full, 0);
	pthread_cond_init (&m_empty, 0);
}

LogQueue::~LogQueue (void) {
	pthread_cond_destroy (&m_empty);
	pthread_cond_destroy (&m_full);
	pthread_mutex_destroy (&m_mutex);
}

LogQueue& LogQueue::operator<< (MLogRec const& log) {
	cout << "压入日志记录开始..." << endl;
	pthread_mutex_lock (&m_mutex);
	while (m_logs.size () >= MAX_LOGS) {
		cout << "等待日志队列非满..." << endl;
		pthread_cond_wait (&m_full, &m_mutex);
	}
	m_logs.push_back (log);
	pthread_cond_signal (&m_empty);
	pthread_mutex_unlock (&m_mutex);
	cout << "压入日志记录完成。" << endl;
	return *this;
}

LogQueue& LogQueue::operator>> (MLogRec& log) {
	cout << "弹出日志记录开始..." << endl;
	pthread_mutex_lock (&m_mutex);
	while (m_logs.empty ()) {
		cout << "等待日志队列非空..." << endl;
		pthread_cond_wait (&m_empty, &m_mutex);
	}
	log = m_logs.front ();
	m_logs.pop_front ();
	pthread_cond_signal (&m_full);
	pthread_mutex_unlock (&m_mutex);
	cout << "弹出日志记录完成。" << endl;
	return *this;
}
