/*
GetLastNtStatusAlt function

Summary:
	Gets last NTSTATUS
	
Parameters:
	N/A
	
Return value:
	The return value is the calling thread's last NTSTATUS code.
	
Remarks:
	Requires:
	
	GetTeb: https://github.com/vxunderground/WinAPI-Tricks/blob/main/GetTEB.c
	TEB structure: https://github.com/vxunderground/WinAPI-Tricks/blob/main/Headers/TEB.h
	
Author:
smelly__vx | June 3rd, 2021

*/

NTSTATUS GetLastNtStatusAlt(VOID)
{
	PTEB Teb = (PTEB)GetTeb();
	return Teb->LastStatusValue;
}
