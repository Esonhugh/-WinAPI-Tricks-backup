#define ERROR_FAILURE_RETURN 0

DWORD GetInMemoryModulePathA(DWORD nBufferLength, PCHAR lpBuffer)
{
	PPEB Peb = (PPEB)GetPeb();
	PRTL_USER_PROCESS_PARAMETERS ProcessParameters = Peb->ProcessParameters;

	if (nBufferLength < ProcessParameters->ImagePathName.Length)
		return ERROR_FAILURE_RETURN;

	return WCharStringToCharString(lpBuffer, ProcessParameters->ImagePathName.Buffer, ProcessParameters->ImagePathName.MaximumLength);
}
