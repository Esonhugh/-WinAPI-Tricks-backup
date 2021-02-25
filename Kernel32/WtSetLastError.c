#include <windows.h>
#include "TEB.h"

PTEB GetTeb(VOID)
{
#if defined(_WIN64)
	return (PTEB)__readgsqword(0x30);
#elif define(_WIN32)
	return (PTEB)__readfsdword(0x18);
#endif
}

VOID WtSetLastError(DWORD ErrorCode)
{
	PTEB Teb = (PTEB)GetTeb();
	Teb->LastErrorValue = ErrorCode;
	return;
}

INT main(VOID)
{
	DWORD dwError = 1;

	WtSetLastError(1);

	return ERROR_SUCCESS;
}
