/*

DeleteFileAlt function

Summary:
	Deletes an existing file using the CreateFile FILE_FLAG_DELETE_ON_CLOSE flag.

Parameters:
	PCHAR Path
	Path to file to delete

Return value:
	TRUE for success, FALSE for failure. Use GetLastError or GetLastErrorAlt for more information
	
Remarks:
	Requires IsPathValid

	IsPathValid: https://github.com/vxunderground/WinAPI-Tricks/tree/main/Kernel32/IsPathValid

Author:
smelly__vx | June 3rd, 2021

*/

BOOL DeleteFileAltA(PCHAR Path)
{
	HANDLE hHandle = INVALID_HANDLE_VALUE;

	if (Path == NULL)
		return FALSE;

	if (!IsPathValidA(Path))
		return FALSE;

	hHandle = CreateFileA(Path, GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_FLAG_DELETE_ON_CLOSE, NULL);
	if (hHandle == INVALID_HANDLE_VALUE)
		return FALSE;

	CloseHandle(hHandle);

	return TRUE;
}
