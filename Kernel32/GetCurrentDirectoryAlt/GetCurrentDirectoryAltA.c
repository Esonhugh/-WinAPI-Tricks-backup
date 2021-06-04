/*

GetCurrentDirectoryAltA function

Summary:
	Recreation of GetCurrentDirectory. Relevant for malware dev, eliminates the need to dynamically resolve GetCurrentDirectory from kernel32.dll

Remarks:
	Precise recreation of GetCurrentDirectory. See MSDN for more details.
	Upon failure GetLastError() will not work. This function does not set the error code.
	
	GetCurrentDirectory: https://docs.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-getcurrentdirectory
	
	WCharStringToCharString, PEB, GetPeb, and PRTL_USER_PROCESS_PARAMETERS but be defined

	WCharStringToCharString: https://github.com/vxunderground/WinAPI-Tricks/blob/main/Stdio/String%20Conversion/WCharStringToCharString.c
	PEB + RTL_USER_PROCESS_PARAMETERS: https://github.com/vxunderground/WinAPI-Tricks/blob/main/Headers/RTL_USER_PROCESS_PARAMETERS.h
	GetPeb: https://github.com/vxunderground/WinAPI-Tricks/blob/main/GetPEB.c

Author:
smelly__vx | June 3rd, 2021

*/

#define ERROR_FAILURE_RETURN 0

DWORD GetCurrentDirectoryAltA(DWORD nBufferLength, PCHAR lpBuffer)
{
	PPEB Peb = (PPEB)GetPeb();
	PRTL_USER_PROCESS_PARAMETERS ProcessParameters = Peb->ProcessParameters;

	if (ProcessParameters->CurrentDirectory.DosPath.Length > nBufferLength)
		return ERROR_FAILURE_RETURN;

	return WCharStringToCharString(lpBuffer, ProcessParameters->CurrentDirectory.DosPath.Buffer, ProcessParameters->CurrentDirectory.DosPath.MaximumLength);
}
