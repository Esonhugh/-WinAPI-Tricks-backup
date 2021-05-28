PCHAR SecureStringCopyAltA(PCHAR String1, LPCSTR String2, SIZE_T Size)
{
	PCHAR pChar = String1;

	while (Size-- && (*String1++ = *String2++) != '\0');

	return pChar;
}
