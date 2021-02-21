SIZE_T WtStringLength(LPCWSTR String)
{
	LPCWSTR String2;

	for (String2 = String; *String2; ++String2);

	return (String2 - String);
}

PWCHAR WtStringCopyW(PWCHAR String1, PWCHAR String2)
{
	PWCHAR p = String1;

	while ((*p++ = *String2++) != 0);

	return String1;
}

PWCHAR WtStringConcatW(PWCHAR String, PWCHAR String2)
{
	WtStringCopyW(&String[WtStringLength(String)], String2);

	return String;
}