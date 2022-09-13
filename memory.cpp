#include "memory.h"
#include <string.h>

void Memory::SetMemoryWord(Memory& mem, DOUBLE_WORD address, WORD data) {
	mem.memory[address] = data;
}

void Memory::SetMemoryDoubleWord(Memory& mem, DOUBLE_WORD address, DOUBLE_WORD data) {
	mem.memory[address] = data & 0xFF;
	mem.memory[address + 1] = (data >> 8);
}

WORD Memory::GetMemoryWord(Memory& mem, DOUBLE_WORD address) {
	return mem.memory[address];
}

DOUBLE_WORD Memory::GetMemoryDoubleWord(Memory& mem, DOUBLE_WORD address) {
	DOUBLE_WORD address = mem.memory[address];
	address |= (mem.memory[address + 1] << 8);
	return address;
}

void Memory::init() {
	memset(memory, 0, TOTAL_MEMORY);
}