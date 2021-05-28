PWCHAR StringLocateCharW(PWCHAR String, INT Character)
{
	do 
	{
		if (*String == Character)
			return (PWCHAR)String;

	} while (*String++);

	return NULL;
}