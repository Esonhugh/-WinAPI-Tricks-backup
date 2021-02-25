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

VOID WtSetLastNtStatus(NTSTATUS Status)
{
	PTEB Teb = (PTEB)GetTeb();
	Teb->LastStatusValue = Status;
	return;
}

INT main(VOID)
{
	NTSTATUS Status = 1;

	WtSetLastNtStatus(Status);

	return ERROR_SUCCESS;
}