#include <windows.h>
#include "TEB.h"

#define HandleToUlong	(	 	h	)	   ((ULONG)(ULONG_PTR)(h) )


PTEB GetTeb(VOID)
{
#if defined(_WIN64)
	return (PTEB)__readgsqword(0x30);
#elif define(_WIN32)
	return (PTEB)__readfsdword(0x18);
#endif
}

DWORD WtGetCurrentProcessId(VOID)
{
	PTEB Teb = GetTeb();
	
	return HandleToUlong(Teb->ClientId.UniqueProcess);
}