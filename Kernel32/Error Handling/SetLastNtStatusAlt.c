/*
SetLastErrorAlt function

Summary:
	Sets last NTSTATUS

Parameters:
	NTSTATUS Status
	The last-error code for the thread.
	
Return value:
	N/A
	
Remarks:
	Requires:
	
	GetTeb: https://github.com/vxunderground/WinAPI-Tricks/blob/main/GetTEB.c
	TEB structure: https://github.com/vxunderground/WinAPI-Tricks/blob/main/Headers/TEB.h

Author:

smelly__vx | June 3rd, 2021
*/

VOID SetLastNtStatusAlt(NTSTATUS Status)
{
	PTEB Teb = (PTEB)GetTeb();
	Teb->LastStatusValue = Status;
	return;
}
