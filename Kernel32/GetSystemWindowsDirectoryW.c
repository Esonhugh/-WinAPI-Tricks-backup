#include <windows.h>

INT main(VOID) {
	_KUSER_SHARED_DATA* kusd = (_KUSER_SHARED_DATA*)0x7FFE0000;
	WCHAR SysDir[MAX_PATH + 1] = {0};

	StringCchCopyW(SysDir, sizeof(SysDir) - sizeof(WCHAR), kusd->NtSystemRoot);

	return ERROR_SUCCESS;
}

