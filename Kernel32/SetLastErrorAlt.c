#include <windows.h>

/*
DEFINITIONS FOR TEB MUST BE PRESENT
*/

PTEB GetTeb(VOID)
{
#if defined(_WIN64)
	return (PTEB)__readgsqword(0x30);
#elif define(_WIN32)
	return (PTEB)__readfsdword(0x18);
#endif
}

VOID SetLastErrorAlt(DWORD ErrorCode)
{
	PTEB Teb = (PTEB)GetTeb();
	Teb->LastErrorValue = ErrorCode;
	return;
}

INT main(VOID)
{
	DWORD dwError = 1;

	SetLastErrorAlt(1);

	return ERROR_SUCCESS;
}
