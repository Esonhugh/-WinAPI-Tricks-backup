PCHAR CaplockStringA(PCHAR Ptr)
{
	PCHAR sv = Ptr;
	while (*sv != '\0')
	{
		if (*sv >= 'a' && *sv <= 'z')
			*sv = *sv - ('a' - 'A');

		sv++;
	}
	return Ptr;
}
