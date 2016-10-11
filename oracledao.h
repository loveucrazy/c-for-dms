
#ifndef _ORACLEDAO_H
#define _ORACLEDAO_H
#include "logdao.h"

class OracleDao : public LogDao {
public:
	OracleDao (string const& username,
		string const& password) throw (DBException);
	~OracleDao (void);
	void insert (MLogRec const& log)
		throw (DBException);
};
#endif // _ORACLEDAO_H
