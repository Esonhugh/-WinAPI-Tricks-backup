DWORD HashStringSdbmW(PWCHAR String)
{
	ULONG Hash = 0;
	INT c;

	while (c = *String++)
		Hash = c + (Hash << 6) + (Hash << 16) - Hash;

	return Hash;
}
