#include <windows.h>
#include <psapi.h>

INT StringCompareW(LPCWSTR String1, LPCWSTR String2)
{
	for (; *String1 == *String2; String1++, String2++)
	{
		if (*String1 == '\0')
			return 0;
	}

	return ((*(LPCWSTR)String1 < *(LPCWSTR)String2) ? -1 : +1);
}

PWCHAR CaplockStringW(PWCHAR Ptr)
{
	PWCHAR sv = Ptr;
	while (*sv != '\0')
	{
		if (*sv >= 'a' && *sv <= 'z')
			*sv = *sv - ('a' - 'A');

		sv++;
	}
	return Ptr;
}

BOOL IsProcessRunningW(PWCHAR ProcessNameWithExtension, BOOL IsCaseSensitive)
{
	HANDLE hProcess = NULL;

	DWORD ProcessIdArray[1024] = { 0 };
	DWORD ProcessIdArraySize = 0;
	DWORD NumberOfBytesReturned = 0;

	if (!EnumProcesses(ProcessIdArray, sizeof(ProcessIdArray), &NumberOfBytesReturned))
		return FALSE;

	ProcessIdArraySize = NumberOfBytesReturned / sizeof(DWORD);

	for (DWORD dwIndex = 0; dwIndex < ProcessIdArraySize; dwIndex++)
	{
		HMODULE Module = NULL;
		WCHAR ProcessStringName[MAX_PATH] = { 0 };
		
		if (ProcessIdArray[dwIndex] == 0)
			continue;

		hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, ProcessIdArray[dwIndex]);
		if (hProcess == NULL)
			continue;

		if(!EnumProcessModules(hProcess, &Module, sizeof(Module), &NumberOfBytesReturned))
			continue;

		if(GetModuleBaseNameW(hProcess, Module, ProcessStringName, sizeof(ProcessStringName)/sizeof(WCHAR)) == 0)
			continue;

		if (hProcess)
			CloseHandle(hProcess);

		if (!IsCaseSensitive)
		{
			PWCHAR String1 = CaplockStringW(ProcessNameWithExtension);
			PWCHAR String2 = CaplockStringW(ProcessStringName);

			if (StringCompareW(String1, String2) == 0)
				return TRUE;
		}
		else {
			if (StringCompareW(ProcessStringName, ProcessNameWithExtension) == 0)
				return TRUE;
		}
	}

	return FALSE;
}

INT main(VOID)
{
	IsProcessRunningW((PWCHAR)L"chrome.exe", FALSE);
}