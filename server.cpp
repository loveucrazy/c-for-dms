
#include "server.h"

Server::Server (LogDao& dao, short port,
	string const ip /* = "" */)
	throw (ServerException) : m_store (dao),
	m_socket (port, ip) {}

void Server::dataMine (void) throw (ServerException) {
	m_store.start ();
	m_socket.acceptClient ();
}
