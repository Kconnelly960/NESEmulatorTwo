#include "memory.h"
#include <string.h>

void Memory::set_memory(Memory& memory) {

}

WORD Memory::get_memory(Memory& mem, WORD address) {
	return mem.memory[address];
}

void Memory::init(Memory& mem) {
	memset(mem.memory, 0, TOTAL_MEMORY);
}