DWORD GetCurrentDirectoryAltA(DWORD nBufferLength, PCHAR lpBuffer)
{
	PPEB Peb = (PPEB)GetPeb();
	PRTL_USER_PROCESS_PARAMETERS ProcessParameters = Peb->ProcessParameters;

	if (ProcessParameters->CurrentDirectory.DosPath.Length > nBufferLength)
		return ERROR_FAILURE_RETURN;

	return WCharStringToCharString(lpBuffer, ProcessParameters->CurrentDirectory.DosPath.Buffer, ProcessParameters->CurrentDirectory.DosPath.MaximumLength);
}