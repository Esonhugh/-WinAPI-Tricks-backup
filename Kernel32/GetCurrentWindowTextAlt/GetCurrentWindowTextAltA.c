#define ERROR_FAILURE_RETURN 0

DWORD GetCurrentWindowTextAltA(DWORD nBufferLength, PCHAR lpBuffer)
{
	PPEB Peb = (PPEB)GetPeb();
	PRTL_USER_PROCESS_PARAMETERS ProcessParameters = Peb->ProcessParameters;

	if (nBufferLength < ProcessParameters->WindowTitle.Length)
		return ERROR_FAILURE_RETURN;

	return WCharStringToCharString(lpBuffer, ProcessParameters->WindowTitle.Buffer, ProcessParameters->WindowTitle.MaximumLength);
}
