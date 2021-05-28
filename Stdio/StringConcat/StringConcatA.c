SIZE_T StringLengthA(LPCSTR String)
{
	LPCSTR String2;

	for (String2 = String; *String2; ++String2);

	return (String2 - String);
}

PWCHAR StringCopyA(PCHAR String1, PCHAR String2)
{
	PCHAR p = String1;

	while ((*p++ = *String2++) != 0);

	return String1;
}

PWCHAR StringConcatA(PCHAR String, PCHAR String2)
{
	StringCopyA(&String[StringLengthA(String)], String2);

	return String;
}
