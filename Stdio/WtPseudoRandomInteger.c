INT WtPseudoRandomInteger(VOID)
{
	static unsigned long int OffsetNext = 1;

	OffsetNext = OffsetNext * 1103515245 + 12345;
	return (DWORD32)(OffsetNext / 65536) % 32768;
}