#include "En_dbio.h"

CRITICAL_SECTION DB_lock;
//4440f0
int DB_EnterCriticalSection() {
	EnterCriticalSection(&DB_lock);
	return 1;
}

//444110
int DB_LeaveCriticalSection() {
	LeaveCriticalSection(&DB_lock);
	return 1;
}

//444130 //TODO more readable
bool ANSItoUTF8(LPCSTR str, char *oBuf, size_t *oSize){
	int cchWideChar;
	LPWSTR lpWideCharStr;
	LPSTR lpMultiByteStr;
	size_t size;

	*oSize = 0;
	cchWideChar = MultiByteToWideChar(CP_ACP, 0, str, -1, (LPWSTR)0x0, 0);
	lpWideCharStr = (LPWSTR)malloc(cchWideChar * 2 + 2);
	MultiByteToWideChar(CP_ACP, 0, str, -1, lpWideCharStr, cchWideChar);
	size = WideCharToMultiByte(CP_UTF8, 0, lpWideCharStr, -1, (LPSTR)0x0, 0, (LPCSTR)0x0, (LPBOOL)0x0);
	if (oBuf == NULL) {
		*oSize = size;
		delete(lpWideCharStr);
		return true;
	}
	lpMultiByteStr = (LPSTR)malloc(size * 2);
	memset(lpMultiByteStr, '\0', size * 2);
	WideCharToMultiByte(CP_UTF8, 0, lpWideCharStr, -1, lpMultiByteStr, size, (LPCSTR)0x0, (LPBOOL)0x0);
	size = lstrlenA(lpMultiByteStr);
	*oSize = size;
	memcpy(oBuf, lpMultiByteStr, size);
	delete(lpWideCharStr);
	delete(lpMultiByteStr);
	return true;
}

//444210
bool UTF8toANSI(LPCSTR str, void *oBuf, size_t *oSize){
	int cchWideChar;
	LPWSTR lpWideCharStr;
	LPSTR lpMultiByteStr;
	size_t sVar1;
	
	*oSize = 0;
	cchWideChar = MultiByteToWideChar(CP_UTF8, 0, str, -1, (LPWSTR)0x0, 0);
	lpWideCharStr = (LPWSTR)malloc(cchWideChar * 2 + 2);
	MultiByteToWideChar(CP_UTF8, 0, str, -1, lpWideCharStr, cchWideChar);
	sVar1 = WideCharToMultiByte(CP_ACP, 0, lpWideCharStr, -1, (LPSTR)0x0, 0, (LPCSTR)0x0, (LPBOOL)0x0);
	if (oBuf == (void *)0x0) {
		*oSize = sVar1;
		delete(lpWideCharStr);
		return true;
	}
	lpMultiByteStr = (LPSTR)malloc(sVar1 * 2);
	memset(lpMultiByteStr, '\0', sVar1 * 2);
	WideCharToMultiByte(CP_ACP, 0, lpWideCharStr, -1, lpMultiByteStr, sVar1, (LPCSTR)0x0, (LPBOOL)0x0);
	sVar1 = lstrlenA(lpMultiByteStr);
	*oSize = sVar1;
	memcpy(oBuf, lpMultiByteStr, sVar1);
	delete(lpWideCharStr);
	delete(lpMultiByteStr);
	return true;
}

//4442f0
int SQL_Run(CSTR queryStr, sqlite3 *sql){
	LPCSTR lpMultiByteStr;
	uint uVar1;
	int cchWideChar;
	LPCWSTR lpWideCharStr;
	size_t sVar2;
	char *oBuf;
	size_t local_10;

	lpMultiByteStr = queryStr;
	cchWideChar = MultiByteToWideChar(CP_ACP, 0, queryStr, -1, (LPWSTR)0x0, 0);
	lpWideCharStr = (LPWSTR)malloc(cchWideChar * 2 + 2);
	
	MultiByteToWideChar(CP_ACP, 0, lpMultiByteStr, -1, (LPWSTR)lpWideCharStr, cchWideChar);
	sVar2 = WideCharToMultiByte(CP_UTF8, 0, lpWideCharStr, -1, (LPSTR)0x0, 0, (LPCSTR)0x0, (LPBOOL)0x0);
	local_10 = sVar2;
	delete(lpWideCharStr);
	oBuf = (char *)malloc(sVar2 + 1);
	
	memset(oBuf, '\0', sVar2 + 1);
	ANSItoUTF8(queryStr, oBuf, &local_10);
	oBuf[local_10] = '\0';
	uVar1 = sqlite3_exec(sql, oBuf, NULL, (void *)0x0, (char **)0x0);
	delete(oBuf);
	return uVar1;
}

//4443f0
int SQL_prepare(CSTR queryStr, sqlite3 *sql, sqlite3_stmt **ppStmt){
	LPCSTR lpMultiByteStr;
	uint uVar1;
	int iVar2;
	LPCWSTR lpWideCharStr;
	size_t sVar3;
	char *oBuf;
	size_t local_10;
	int *local_c;

	lpMultiByteStr = queryStr;

	iVar2 = MultiByteToWideChar(0, 0, queryStr, -1, (LPWSTR)0x0, 0);
	lpWideCharStr = (LPCWSTR)malloc(iVar2 * 2 + 2);
	MultiByteToWideChar(0, 0, lpMultiByteStr, -1, (LPWSTR)lpWideCharStr, iVar2);
	sVar3 = WideCharToMultiByte(0xfde9, 0, lpWideCharStr, -1, (LPSTR)0x0, 0, (LPCSTR)0x0, (LPBOOL)0x0);
	local_10 = sVar3;
	delete(lpWideCharStr);
	oBuf = (char *)malloc(sVar3 + 1);
	memset(oBuf, '\0', sVar3 + 1);
	ANSItoUTF8(queryStr, oBuf, &local_10);
	oBuf[local_10] = '\0';
	iVar2 = sqlite3_prepare(sql, oBuf, -1, ppStmt, NULL);
	delete(oBuf);
	return iVar2;
}

//4444f0
CSTR SQL_GetColumn(int i, sqlite3_stmt *pStmt){
	CSTR oBuf;
	size_t size;
	LPCSTR columnText;

	if (sqlite3_column_type(pStmt, i) == SQLITE_NULL) {
		oBuf.fillzero();
	}
	else {
		sqlite3_column_bytes(pStmt, i);
		columnText = (LPCSTR)sqlite3_column_text(pStmt, i);
		UTF8toANSI(columnText, NULL, &size);
		oBuf.resize2(size + 1);
		memset(oBuf.body, 0, size + 1);
		UTF8toANSI(columnText, oBuf.body, &size);
		*oBuf.atPos(size) = 0;
	}
	return oBuf;
}
