OUTPUT_ARCH( "riscv" )
ENTRY(_start)

SECTIONS {
    . = 0;
  .text   : { *(.text*) }
  .data  :  { *(.*data) STACK = ALIGN(16) + 0x2000;}
  .bss : { *(.bss) }
}