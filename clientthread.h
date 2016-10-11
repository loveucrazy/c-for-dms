
#ifndef _CLIENTTHREAD_H
#define _CLIENTTHREAD_H
#include "logthread.h"

class ClientThread : public LogThread {
public:
	ClientThread (int connfd);
private:
	void run (void);
	int m_connfd;
};
#endif // _CLIENTTHREAD_H
