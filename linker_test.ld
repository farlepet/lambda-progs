ENTRY (start)

SECTIONS
{
	. = 0x80000000;

	.text BLOCK(4K) : ALIGN(4K)
	{
		*(*)
	}
}
