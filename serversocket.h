
#ifndef _SERVERSOCKET_H
#define _SERVERSOCKET_H
#include "except.h"

class ServerSocket {
public:
	ServerSocket (short port, string const ip = "")
		throw (SocketException);
	void acceptClient (void) throw (SocketException);
private:
	int m_sockfd;
};
#endif // _SERVERSOCKET_H
