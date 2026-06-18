#ifndef __HEXDUMP_H
#define __HEXDUMP_H

#include<stdint.h>

void print_hex(void* base,uint32_t limit);
int  hex_equal(void* base1,void* base2,uint32_t limit);


#endif