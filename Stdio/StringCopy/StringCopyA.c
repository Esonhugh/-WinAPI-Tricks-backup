PCHAR StringCopyA(PCHAR String1, PCHAR String2)
{
	PCHAR p = String1;

	while ((*p++ = *String2++) != 0);

	return String1;
}
