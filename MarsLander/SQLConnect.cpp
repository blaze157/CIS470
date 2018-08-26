#include "stdafx.h"
#include "SQLConnect.h"
#include <iostream>


SQLConnector::SQLConnector(std::wstring server, std::wstring username, std::wstring password)
{
	sqlConnHandle = 0;
	sqlStmtHandle = 0;
	sqlEnvHandle = 0;
	SQLWCHAR retconstring[1000];

	SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &sqlEnvHandle);
	SQLSetEnvAttr(sqlEnvHandle, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0);
	SQLAllocHandle(SQL_HANDLE_DBC, sqlEnvHandle, &sqlConnHandle);

	std::wstring connectString;

	connectString += L"DRIVER={SQL Server};";
	connectString += L"SERVER=" + server + L",1433;";
	connectString += L"DATABASE=MarsLander;";
	connectString += L"UID=" + username + L";";
	connectString += L"PWD=" + password + L";";

	switch (SQLDriverConnectW(sqlConnHandle,
		NULL,
		(SQLWCHAR*)connectString.data(),
		SQL_NTS,
		retconstring,
		1024,
		NULL,
		SQL_DRIVER_NOPROMPT)) {
	case SQL_SUCCESS://good connection
		break;
	case SQL_SUCCESS_WITH_INFO://connected with warning but still usable
		break;
	case SQL_INVALID_HANDLE://should probably throw an error or somthing
		std::cout << "error connecting" << std::endl;
		break;
	case SQL_ERROR://should probably throw an error or somthing
		std::cout << "error connecting" << std::endl;
		break;
	default:
		break;
	}

	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
}


SQLConnector::~SQLConnector()
{
	SQLFreeHandle(SQL_HANDLE_STMT, sqlStmtHandle);
	SQLDisconnect(sqlConnHandle);
	SQLFreeHandle(SQL_HANDLE_DBC, sqlConnHandle);
	SQLFreeHandle(SQL_HANDLE_ENV, sqlEnvHandle);
}

std::string SQLConnector::execute(std::wstring code)
{
	std::string ret;
	SQLCHAR sqlTableList[1000];

	SQLLEN ptrSqlTableList;
	if (SQL_SUCCESS != SQLExecDirect(sqlStmtHandle, (SQLWCHAR*)code.data(), SQL_NTS))
	{
		std::cout << "well u did somthin wrong" << std::endl;
		SQLWCHAR SqlState[6], SQLStmt[100], Msg[SQL_MAX_MESSAGE_LENGTH];
		SQLINTEGER NativeError = 0;
		SQLHSTMT hstmt = 0;
		SQLLEN numRecs = 0;
		SQLSMALLINT MsgLen;
		SQLGetDiagField(SQL_HANDLE_STMT, sqlStmtHandle, 0, SQL_DIAG_NUMBER, &numRecs, 0, 0);
		SQLGetDiagRec(SQL_HANDLE_STMT, sqlStmtHandle, 1, SqlState, &NativeError, Msg, sizeof(Msg), &MsgLen);
		for (int i = 0; i < sizeof(Msg); i++)
			std::cout << char(*(Msg+i));
			std::cout << " " << NativeError << " ";
		for (int i = 0; i<5; i++)
		std::cout<< char(*(SqlState+i));
	}
	else
	{
		while (SQL_SUCCESS == SQLFetch(sqlStmtHandle))//get a row
		{
			int i = 1;
			while (SQL_SUCCESS == SQLGetData(sqlStmtHandle, i, SQL_CHAR, sqlTableList, 1000, &ptrSqlTableList))// get a col
			{
				//display query result
				ret += (const char*)sqlTableList;
				ret += "\t";
				i++;
			}
			ret += "\n";
		}
	}

	return ret;
}


