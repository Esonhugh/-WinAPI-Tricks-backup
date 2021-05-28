PWCHAR StringRemoveSubstringW(PWCHAR String, CONST PWCHAR Substring)
{
	DWORD Length = (DWORD)StringLengthW(Substring);
	PWCHAR pPointer = String;

	if (Length == 0)
		return NULL;

	while ((pPointer = StringFindSubstringW(pPointer, Substring)) != NULL)
		MoveMemory(pPointer, pPointer + Length, StringLengthW(pPointer + Length) + 1);

	return String;
}