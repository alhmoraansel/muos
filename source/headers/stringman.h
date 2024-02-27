#ifndef __stringman
#define __stringman

#include "mukernel.h"

size_t terminal_row;
size_t terminal_column;
uint8_t terminal_color;
uint16_t* terminal_buffer;

size_t strlen(const char* str){
	size_t len = 0;
	while (str[len])
		len++;
	return len;
}

void terminal_put_char_entryat(char c, uint8_t color, size_t x, size_t y)
{
	const size_t index = y * VGA_WIDTH + x;
	terminal_buffer[index] = vga_entry(c, color);
}

void terminal_putchar(char c)
{
	terminal_put_char_entryat(c, terminal_color, terminal_column, terminal_row);
	if (++terminal_column == VGA_WIDTH) {
		terminal_column = 0;
		if (++terminal_row == VGA_HEIGHT)
			terminal_row = 0;
	}
}

void terminal_write(const char* data, size_t size)
{
	for (size_t i = 0; i < size; i++)  {
        if (data[i] == '\n' ){
            terminal_row++;
            terminal_column = 0 ;
        }
        else    terminal_putchar(data[i]);
    }
}

void terminal_writestring(const char* data)
{
	terminal_write(data, strlen(data));
}



#endif //stringman.h