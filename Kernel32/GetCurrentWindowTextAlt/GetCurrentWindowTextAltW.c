#define ERROR_FAILURE_RETURN 0

DWORD GetCurrentWindowTextAltW(DWORD nBufferLength, PWCHAR lpBuffer)
{
	PPEB Peb = (PPEB)GetPeb();
	PRTL_USER_PROCESS_PARAMETERS ProcessParameters = Peb->ProcessParameters;

	if (nBufferLength < ProcessParameters->WindowTitle.Length)
		return ERROR_FAILURE_RETURN;

	if (StringCopyW(lpBuffer, ProcessParameters->WindowTitle.Buffer) == NULL)
		return ERROR_FAILURE_RETURN;

	return ProcessParameters->WindowTitle.Length;
}
