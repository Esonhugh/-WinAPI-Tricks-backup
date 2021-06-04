/*

DeleteFileAlt function

Summary:
	Deletes an existing file using the CreateFile FILE_FLAG_DELETE_ON_CLOSE flag.

Parameters:
	- PWCHAR Path
	Path to file to delete

Return value:
	TRUE for success, FALSE for failure. Use GetLastError or GetLastErrorAlt for more information
	
Remarks:
	The code below uses IsPathValid, an existing function from this repo, to determine if the file path is valid

Author:
smelly__vx | June 3rd, 2021

*/

BOOL DeleteFileAltW(PWCHAR Path)
{
	HANDLE hHandle = INVALID_HANDLE_VALUE;

	if (Path == NULL)
		return FALSE;

	if (!IsPathValidW(Path))
		return FALSE;

	hHandle = CreateFileW(Path, GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_FLAG_DELETE_ON_CLOSE, NULL);
	if (hHandle == INVALID_HANDLE_VALUE)
		return FALSE;

	CloseHandle(hHandle);

	return TRUE;
}

