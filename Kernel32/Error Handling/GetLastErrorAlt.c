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

DWORD GetLastErrorAlt(VOID)
{
	PTEB Teb = (PTEB)GetTeb();
	return Teb->LastErrorValue;
}

INT main(VOID)
{
	DWORD dwError;

	dwError = GetLastErrorAlt();

	return ERROR_SUCCESS;
}
