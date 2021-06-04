/*

GetCurrentDirectoryAltW function

Summary:
	Recreation of GetCurrentDirectory. Relevant for malware dev, eliminates the need to dynamically resolve GetCurrentDirectory from kernel32.dll
	
Parameters:
	DWORD nBufferLength
	The length of the buffer to receive the current binaries directory
	
	PWCHAR lpBuffer
	A buffer which will receive the current binaries directory

Remarks:
	Precise recreation of GetCurrentDirectory. See MSDN for more details.
	Upon failure GetLastError() will not work. This function does not set the error code.
	
	GetCurrentDirectory: https://docs.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-getcurrentdirectory
	
	StringCopyW, PEB, GetPeb, and PRTL_USER_PROCESS_PARAMETERS but be defined

	StringCopy: https://github.com/vxunderground/WinAPI-Tricks/tree/main/Stdio/StringCopy
	PEB + RTL_USER_PROCESS_PARAMETERS: https://github.com/vxunderground/WinAPI-Tricks/blob/main/Headers/RTL_USER_PROCESS_PARAMETERS.h
	GetPeb: https://github.com/vxunderground/WinAPI-Tricks/blob/main/GetPEB.c

Author:
smelly__vx | June 3rd, 2021

*/

#define ERROR_FAILURE_RETURN 0

DWORD GetCurrentDirectoryAltW(DWORD nBufferLength, PWCHAR lpBuffer)
{
	PPEB Peb = (PPEB)GetPeb();
	PRTL_USER_PROCESS_PARAMETERS ProcessParameters = Peb->ProcessParameters;

	if (ProcessParameters->CurrentDirectory.DosPath.Length > nBufferLength)
		return ERROR_FAILURE_RETURN;

	if(StringCopyW(lpBuffer, ProcessParameters->CurrentDirectory.DosPath.Buffer) == NULL)
		return ERROR_FAILURE_RETURN;

	return ProcessParameters->CurrentDirectory.DosPath.Length;
}
