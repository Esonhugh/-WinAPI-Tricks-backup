SIZE_T StringLengthW(LPCWSTR String)
{
	LPCWSTR String2;

	for (String2 = String; *String2; ++String2);

	return (String2 - String);
}

PWCHAR StringLocateCharW(PWCHAR String, INT Character)
{
	do 
	{
		if (*String == Character)
			return (PWCHAR)String;

	} while (*String++);

	return NULL;
}

INT StringCompareStringRegionW(PWCHAR String1, PWCHAR String2, SIZE_T Count)
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

PWCHAR StringFindSubstringW(PWCHAR String1, PWCHAR String2)
{
	PWCHAR pPointer = String1;
	DWORD Length = (DWORD)StringLengthW(String2);

	for (; (pPointer = StringLocateCharW(pPointer, *String2)) != 0; pPointer++)
	{
		if (StringCompareStringRegionW(pPointer, String2, Length) == 0)
			return (PWCHAR)pPointer;
	}

	return NULL;
}