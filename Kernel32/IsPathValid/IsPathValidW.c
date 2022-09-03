/*

IsPathValid function

Summary:
	Determines if a file exists.

Parameters:
	A pointer to the full path to the file.

Return value:
	TRUE if file exists. FALSE if file does not exist or the application is unable to get a HANDLE on the file specified
	
Remarks:
	Use GetLastError() for details on failure

Author:
smelly__vx | June 4th, 2021

*/

BOOL IsPathValidW(PWCHAR FilePath)
{
    HANDLE hFile = INVALID_HANDLE_VALUE;

    hFile = CreateFileW(FilePath, GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hFile == INVALID_HANDLE_VALUE)
        return FALSE;
		
    if(hFile)
	CloseHandle(hFile);

    return TRUE;
}


