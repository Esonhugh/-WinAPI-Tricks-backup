BOOL GetSystemWindowsDirectoryAltW(DWORD nBufferLength, PWCHAR lpBuffer)
{
	PKUSER_SHARED_DATA SharedData = GetKUserSharedData();

	if (nBufferLength < StringLengthW(SharedData->NtSystemRoot))
		return FALSE;

	if (StringCopyW(lpBuffer, SharedData->NtSystemRoot) == NULL)
		return FALSE;

	return TRUE;
}
