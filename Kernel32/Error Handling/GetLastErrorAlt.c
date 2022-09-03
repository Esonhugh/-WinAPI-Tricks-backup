/*

GetLastErrorAlt function

Summary:
	Custom implementation of GetLastError. Relevant for malware dev, eliminates the need to dynamically resolve GetLastError from kernel32.dll

Parameters:
	N/A

Return value:
	The return value is the calling thread's last-error code.
	
Remarks:
	Requires:
	
	GetTeb: https://github.com/vxunderground/WinAPI-Tricks/blob/main/GetTEB.c
	TEB structure: https://github.com/vxunderground/WinAPI-Tricks/blob/main/Headers/TEB.h

Author:
smelly__vx | June 3rd, 2021

*/

DWORD GetLastErrorAlt(VOID)
{
	PTEB Teb = (PTEB)GetTeb();
	return Teb->LastErrorValue;
}
