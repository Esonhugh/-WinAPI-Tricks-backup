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

NTSTATUS GetLastNtStatusAlt(VOID)
{
	PTEB Teb = (PTEB)GetTeb();
	return Teb->LastStatusValue;
}

INT main(VOID)
{
	NTSTATUS Status;

	Status = GetLastNtStatusAlt();

	return ERROR_SUCCESS;
}
