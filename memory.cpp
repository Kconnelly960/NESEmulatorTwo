#include "memory.h"
#include <string.h>

void Memory::SetMemory(Memory& mem, WORD address, WORD data) {
	mem.memory[address] = data;
}

WORD Memory::GetMemoryWord(Memory& mem, WORD address) {
	return mem.memory[address];
}

DOUBLE_WORD Memory::GetMemoryDoubleWord(Memory& mem, WORD address) {
	DOUBLE_WORD address = mem.memory[address];
	address << 8;
	address &= mem.memory[address + 1];
	return address;
}

void Memory::init() {
	memset(memory, 0, TOTAL_MEMORY);
}