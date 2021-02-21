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

INT main(VOID)
{
	PTEB Teb;
	
	Teb = (PTEB)GetTeb();

	return ERROR_SUCCESS;
}
