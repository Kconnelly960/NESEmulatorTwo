#pragma once


#define TOTAL_MEMORY 0xFFFF
#define WORD unsigned char
#define DOUBLE_WORD unsigned short

#define ZERO_PAGE_START 0x0000
#define ZERO_PAGE_END 0x00FF
#define ZERO_PAGE_SIZE 0x00FF

#define STACK_START 0x0100
#define STACK_END 0x01FF
#define STACK_SIZE 0x00FF