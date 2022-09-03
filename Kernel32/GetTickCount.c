INT main(VOID) {
	_KUSER_SHARED_DATA* kusd = (_KUSER_SHARED_DATA*)0x7FFE0000;
	DWORD tickCount = (kusd->TickCountMultiplier * kusd->TickCount->LowPart) << 0x18;

	return 0;
}
