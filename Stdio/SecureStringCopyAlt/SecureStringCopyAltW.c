PWCHAR SecureStringCopyAltW(PWCHAR String1, LPCWSTR String2, SIZE_T Size)
{
	PWCHAR pChar = String1;

	while (Size-- && (*String1++ = *String2++) != '\0');

	return pChar;
}
