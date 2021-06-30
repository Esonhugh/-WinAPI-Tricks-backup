BOOL IsRemoteDebuggerPresentOnProcess(VOID)
{
	BOOL bFlag = FALSE;

	CheckRemoteDebuggerPresentAlt(GetCurrentProcessAlt(), &bFlag);
	
	return bFlag;
}
