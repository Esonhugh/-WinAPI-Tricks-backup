SIZE_T StringLengthA(LPCSTR String)
{
	LPCSTR String2;

	for (String2 = String; *String2; ++String2);

	return (String2 - String);
}

PCHAR StringLocateCharA(PCHAR String, INT Character)
{
	do 
	{
		if (*String == Character)
			return (PCHAR)String;

	} while (*String++);

	return NULL;
}

INT StringCompareStringRegionA(PCHAR String1, PCHAR String2, SIZE_T Count)
{
	UCHAR Block1, Block2;
	while (Count-- > 0)
	{
		Block1 = (UCHAR)*String1++;
		Block2 = (UCHAR)*String2++;

		if (Block1 != Block2)
			return Block1 - Block2;

		if (Block1 == '\0')
			return 0;
	}

	return 0;
}

PCHAR StringFindSubstringA(PCHAR String1, PCHAR String2)
{
	PCHAR pPointer = String1;
	DWORD Length = (DWORD)StringLengthA(String2);

	for (; (pPointer = StringLocateCharA(pPointer, *String2)) != 0; pPointer++)
	{
		if (StringCompareStringRegionA(pPointer, String2, Length) == 0)
			return (PCHAR)pPointer;
	}

	return NULL;
}