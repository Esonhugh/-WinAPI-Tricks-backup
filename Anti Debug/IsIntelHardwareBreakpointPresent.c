BOOL IsIntelHardwareBreakpointPresent(VOID)
{
	BOOL bFlag = FALSE;
	PCONTEXT Context = NULL;

	Context = (PCONTEXT)VirtualAlloc(NULL, sizeof(CONTEXT), MEM_COMMIT, PAGE_READWRITE);
	if (Context == NULL)
		return FALSE; //check GetLastError();

	RtlZeroMemory(Context, sizeof(Context));

	Context->ContextFlags = CONTEXT_DEBUG_REGISTERS;

	if(!GetThreadContext(GetCurrentThreadAlt(), Context))
		return FALSE; //check GetLastError();

	if (Context->Dr0 || Context->Dr1 || Context->Dr2 || Context->Dr3)
		bFlag = TRUE;

	VirtualFree(Context, 0, MEM_RELEASE);

	return bFlag;
}
