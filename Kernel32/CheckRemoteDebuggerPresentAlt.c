BOOL CheckRemoteDebuggerPresentAlt(HANDLE hProcess, PBOOL IsDebuggerPresent)
{
	NTSTATUS Status = ERROR_SUCCESS;
	HANDLE Port = NULL;

	Status = NtQueryInformationProcess(hProcess, ProcessDebugPort, &Port, sizeof(Port), NULL);
	if (NT_SUCCESS(Status))
	{
		*IsDebuggerPresent = Port != NULL;
		return TRUE;
	}

	return FALSE;
}
