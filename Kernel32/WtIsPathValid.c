BOOL WtIsPathValid(PWCHAR FilePath)
{
    HANDLE hFile = INVALID_HANDLE_VALUE;

    hFile = CreateFileW(FilePath, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hFile == INVALID_HANDLE_VALUE)
        return FALSE;
		
	if(hFile)
		CloseHandle(hFile);

    return TRUE
}