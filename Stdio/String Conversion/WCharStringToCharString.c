#include <windows.h>

SIZE_T StringLengthW(LPCWSTR String)
{
	LPCWSTR String2;

	for (String2 = String; *String2; ++String2);

	return (String2 - String);
}

SIZE_T WCharStringToCharString(PCHAR Destination, PWCHAR Source, SIZE_T MaximumAllowed)
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
	CHAR Path[MAX_PATH] = { 0 };
	WCHAR CharPath[MAX_PATH * sizeof(WCHAR)] = L"\\Users\\Tmp\\Desktop\\";

	if(WCharStringToCharString(&Path, CharPath, StringLengthW(CharPath)) == 0)
		return 1;

	return ERROR_SUCCESS;
}