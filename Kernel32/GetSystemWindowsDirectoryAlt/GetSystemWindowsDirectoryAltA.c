BOOL GetSystemWindowsDirectoryAltA(DWORD nBufferLength, PCHAR lpBuffer)
{
	PKUSER_SHARED_DATA SharedData = GetKUserSharedData();

	if (nBufferLength < StringLengthW(SharedData->NtSystemRoot))
		return FALSE;

	if (WCharStringToCharString(lpBuffer, SharedData->NtSystemRoot, nBufferLength) != 0)
		return TRUE;
	else
		return FALSE;
}
