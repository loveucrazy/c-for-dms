#include "filedao.h"
#include "oracledao.h"
#include "server.h"
int main (void) {
	try {
		OracleDao dao ("openlab", "open123");
		Server server (dao, 8888);
		server.dataMine ();
	}
	catch (exception& ex) {
		cout << ex.what () << endl;
		return -1;
	}
	return 0;
}
