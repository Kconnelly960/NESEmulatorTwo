#ifndef MEMORY_H
#define MEMORY_H

#include "config.H"

class Memory {
private:
	WORD memory[TOTAL_MEMORY];

public:
	void SetMemory(Memory& memory, WORD address, WORD data);
	WORD GetMemoryWord(Memory& memory, WORD address);
	DOUBLE_WORD GetMemoryDoubleWord(Memory& mem, WORD address);
	void init();
};

#endif