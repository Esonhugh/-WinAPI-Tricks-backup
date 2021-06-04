#define ERROR_FAILURE_RETURN 0

DWORD GetInMemoryModulePathW(DWORD nBufferLength, PWCHAR lpBuffer)
{
	PPEB Peb = (PPEB)GetPeb();
	PRTL_USER_PROCESS_PARAMETERS ProcessParameters = Peb->ProcessParameters;

	if (nBufferLength < ProcessParameters->ImagePathName.Length)
		return ERROR_FAILURE_RETURN;

	if (StringCopyW(lpBuffer, ProcessParameters->ImagePathName.Buffer) == NULL)
		return ERROR_FAILURE_RETURN;

	return ProcessParameters->ImagePathName.Length;
}

