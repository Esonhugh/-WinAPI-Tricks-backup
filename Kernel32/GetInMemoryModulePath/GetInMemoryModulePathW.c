/*

GetInMemoryModulePathW function

Summary:
	Recreation of GetModuleFileName with the first parameter being set to NULL. Relevant for malware dev, eliminates the need to dynamically resolve GetModuleFileName from kernel32.dll

Remarks:
	Incomplete recreation of GetModuleFileName
	Upon failure GetLastError() will not work. This function does not set the error code.
	
	GetCurrentDirectory: https://docs.microsoft.com/en-us/windows/win32/api/libloaderapi/nf-libloaderapi-getmodulefilenamea
	
	StringCopyW, PEB, GetPeb, and PRTL_USER_PROCESS_PARAMETERS but be defined

	StringCopy: https://github.com/vxunderground/WinAPI-Tricks/tree/main/Stdio/StringCopy
	PEB + RTL_USER_PROCESS_PARAMETERS: https://github.com/vxunderground/WinAPI-Tricks/blob/main/Headers/RTL_USER_PROCESS_PARAMETERS.h
	GetPeb: https://github.com/vxunderground/WinAPI-Tricks/blob/main/GetPEB.c

Author:
smelly__vx | June 4th, 2021

*/

#define ERROR_FAILURE_RETURN 0

DWORD GetInMemoryModulePathW(DWORD nBufferLength, PWCHAR lpBuffer)
{
	PPEB Peb = (PPEB)GetPeb();
	PRTL_USER_PROCESS_PARAMETERS ProcessParameters = Peb->ProcessParameters;

	if (nBufferLength < ProcessParameters->ImagePathName.Length)
		return ERROR_FAILURE_RETURN;

	if (StringCopyW(lpBuffer, ProcessParameters->ImagePathName.Buffer) == NULL)
		return ERROR_FAILURE_RETURN;

	return ProcessParameters->ImagePathName.Length;
}

