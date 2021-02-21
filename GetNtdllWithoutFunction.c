#include <windows.h>
#include "TEB.h"

PPEB GetPebAlt(VOID)
{
	PTEB Teb;
#if defined(_WIN64)
	Teb = (PTEB)__readgsqword(0x30);
#elif define(_WIN32)
	Teb = (PTEB)__readfsdword(0x18);
#endif
	return (PPEB)Teb->ProcessEnvironmentBlock;
}

INT main(VOID)
{
	PPEB Peb = GetPebAlt();
	PLDR_MODULE pLoadModule;

	pLoadModule = (PLDR_MODULE)((PBYTE)Peb->LoaderData->InMemoryOrderModuleList.Flink->Flink - 16);

	return ERROR_SUCCESS;
}
