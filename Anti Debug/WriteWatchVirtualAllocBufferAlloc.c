BOOL WriteWatchVirtualAllocBufferAlloc(VOID)
{
	ULONG_PTR Count = NULL;
	DWORD Granularity = 0;
	BOOL bFlag = FALSE;
	PVOID Address = NULL;
	PINT Buffer = NULL;

	Address = VirtualAlloc(NULL, (4096 * sizeof(PVOID)), MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
	if (Address == NULL)
		return FALSE;

	Buffer = (PINT)VirtualAlloc(NULL, (4096 * 4096), MEM_RESERVE | MEM_COMMIT | MEM_WRITE_WATCH, PAGE_READWRITE);
	if (Buffer == NULL)
		goto EXIT_ROUTINE;

	Buffer[0] = 1024;
	Count = 4096;

	if (GetWriteWatch(0, Buffer, 4096, Address, &Count, &Granularity) != ERROR_SUCCESS)
		bFlag = Count != 1;

EXIT_ROUTINE:

	if (Buffer)
		VirtualFree(Buffer, 0, MEM_RELEASE);

	if (Address)
		VirtualFree(Address, 0, MEM_RELEASE);

	return bFlag;
}
