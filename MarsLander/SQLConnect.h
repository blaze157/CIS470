#pragma once

#include "stdafx.h"
#include <string>
#include <windows.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <sql.h>

class SQLConnector
{
public:
	SQLConnector(std::wstring server, std::wstring username, std::wstring password);
	~SQLConnector();

	std::string execute(std::wstring code);
private:
	SQLHANDLE sqlConnHandle;
	SQLHANDLE sqlStmtHandle;
	SQLHANDLE sqlEnvHandle;
};

