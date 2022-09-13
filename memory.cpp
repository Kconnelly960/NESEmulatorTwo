#include "memory.h"
#include <string.h>

void Memory::set_memory(Memory& mem, WORD address, WORD data) {
	mem.memory[address] = data;
}

WORD Memory::get_memory(Memory& mem, WORD address) {
	return mem.memory[address];
}

void Memory::init() {
	memset(memory, 0, TOTAL_MEMORY);
}