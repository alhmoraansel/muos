#include "headers/mukernel.h"

void kernel_main(void)
{
	/* Initialize terminal interface */
	terminal_initialize();

    // for (uint16_t i =0; i<300; i++){
	// 	terminal_buffer[i] = vga_int_entry(i,12);
    // }
	terminal_writestring("beiwjfpa\nadas");

}
