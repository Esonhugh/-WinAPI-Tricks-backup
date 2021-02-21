#include <windows.h>
#include "TEB.h"

PPEB GetPebAlt(VOID)
{
	PTEB Teb;
#if defined(_WIN64)
	PTEB Teb = (PTEB)__readgsqword(0x30);
#elif define(_WIN32)
	//32bit
	PTEB Teb = (PTEB)__readfsdword(0x18);
#endif
	return (PPEB)Teb->ProcessEnvironmentBlock;
}

INT main(VOID)
{
	PPEB Peb;
	
	Peb = GetPebAlt();

	return ERROR_SUCCESS;
}
