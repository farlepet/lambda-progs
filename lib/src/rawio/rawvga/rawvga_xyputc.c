#include <rawio/rawvga/rawvga_data.h>
#include <stdint.h>

void rawvga_xyputc(int x, int y, char c) {
	uint16_t char_data = c | (rawvga_data_color << 8);
	int char_idx = x + (y * rawvga_data_width);

	((uint16_t *)0xB8000)[char_idx] = char_data;
}
