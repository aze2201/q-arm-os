ENTRY(_Reset)
SECTIONS
{
 . = 0x10000;
 .startup . : { boot.o(.text) }
 .text : { *(.text) }
 .data : { *(.data) }
 .bss : { *(.bss COMMON) }
 . = ALIGN(8);
 . = . + 0x1000; /* 4kB of stack memory (Usually same) */
 stack_top = .;
}
