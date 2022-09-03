SIZE_T StringLengthW(LPCWSTR String)
{
	LPCWSTR String2;

	for (String2 = String; *String2; ++String2);

	return (String2 - String);
}

UINT32 HashStringRotr32SubW(UINT32 Value, UINT Count)
{
	DWORD Mask = (CHAR_BIT * sizeof(Value) - 1);
	Count &= Mask;
#pragma warning( push )
#pragma warning( disable : 4146)
	return (Value >> Count) | (Value << ((-Count) & Mask));
#pragma warning( pop ) 
}

INT HashStringRotr32W(PWCHAR String)
{
	INT Value = 0;

	for (INT Index = 0; Index < StringLengthW(String); Index++)
		Value = String[Index] + HashStringRotr32SubW(Value, 7);

	return Value;
}