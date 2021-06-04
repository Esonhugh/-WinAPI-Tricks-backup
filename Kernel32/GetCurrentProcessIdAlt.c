#define HandleToUlong (h)((ULONG)(ULONG_PTR)(h))

DWORD GetCurrentProcessId(VOID)
{
	PTEB Teb = GetTeb();
	
	return HandleToUlong(Teb->ClientId.UniqueProcess);
}
