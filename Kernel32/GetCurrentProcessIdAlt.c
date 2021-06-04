#define HandleToUlong (h)((ULONG)(ULONG_PTR)(h))

DWORD GetCurrentProcessIdAlt(VOID)
{
	PTEB Teb = GetTeb();
	
	return HandleToUlong(Teb->ClientId.UniqueProcess);
}
