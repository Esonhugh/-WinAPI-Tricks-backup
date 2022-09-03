PCHAR StringRemoveSubstringA(PCHAR String, CONST PCHAR Substring)
{
	DWORD Length = (DWORD)StringLengthA(Substring);
	PCHAR pPointer = String;

	if (Length == 0)
		return NULL;

	while ((pPointer = StringFindSubstringA(pPointer, Substring)) != NULL)
		MoveMemory(pPointer, pPointer + Length, StringLengthA(pPointer + Length) + 1);

	return String;
}
