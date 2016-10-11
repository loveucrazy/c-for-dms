#ifndef _SERVER_H
#define _SERVER_H
#include <string>
using namespace std;
#include "storethread.h"
#include "serversocket.h"

class Server {
public:
	Server (LogDao& dao, short port,
		string const ip = "")
		throw (ServerException);
	void dataMine (void) throw (ServerException);
private:
	StoreThread  m_store;
	ServerSocket m_socket;
};
#endif // _SERVER_H
