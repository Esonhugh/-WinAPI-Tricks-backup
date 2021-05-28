#include <windows.h>

SIZE_T StringLengthA(LPCSTR String)
{
	LPCSTR String2;

	for (String2 = String; *String2; ++String2);

	return (String2 - String);
}

SIZE_T CharStringToWCharString(PWCHAR Destination, PCHAR Source, SIZE_T MaximumAllowed)
{
	INT Length = MaximumAllowed;

	while (--Length >= 0)
	{
		if (!(*Destination++ = *Source++))
			return MaximumAllowed - Length - 1;
	}

	return MaximumAllowed - Length;
}

INT main(VOID)
{
	WCHAR Path[MAX_PATH * sizeof(WCHAR)] = { 0 };
	CHAR CharPath[MAX_PATH] = "\\Users\\Tmp\\Desktop\\";

	if(CharStringToWCharString(&Path, CharPath, StringLengthA(CharPath)) == 0)
		return 1;

	return ERROR_SUCCESS;
}