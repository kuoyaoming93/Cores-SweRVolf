OUTPUT_ARCH( "riscv" )
ENTRY(_start)

SECTIONS {
    . = 0;
  .text   : { *(.text*) }
  _end = .;
  end = _end;
  .data  :  { *(.*data) *(.rodata*) *(.sbss) *(.got*) STACK = ALIGN(16) + 0x2000;}
  .bss : { *(.bss) }
}