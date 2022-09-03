PCHAR StringLocateCharA(PCHAR String, INT Character)
{
	do 
	{
		if (*String == Character)
			return (PCHAR)String;

	} while (*String++);

	return NULL;
}
