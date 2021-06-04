/*

SetLastErrorAlt function

Summary:
	Custom implementation of SetLastError. Relevant for malware dev, eliminates the need to dynamically resolve SeyLastError from kernel32.dll

Parameters:
	DWORD ErrorCode
	The last-error code for the thread.

Return value:
	N/A
	
Remarks:
	TEB and GetPeb must be defined.

Author:
smelly__vx | June 3rd, 2021

*/


VOID SetLastErrorAlt(DWORD ErrorCode)
{
	PTEB Teb = (PTEB)GetTeb();
	Teb->LastErrorValue = ErrorCode;
	return;
}
