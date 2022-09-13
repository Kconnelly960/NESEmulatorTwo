#ifndef MEMORY_H
#define MEMORY_H

#include "config.H"

class Memory {
private:
	WORD memory[TOTAL_MEMORY];

public:
	void SetMemoryWord(Memory& memory, DOUBLE_WORD address, WORD data);
	void SetMemoryDoubleWord(Memory& mem, DOUBLE_WORD address, DOUBLE_WORD data);
	WORD GetMemoryWord(Memory& memory, DOUBLE_WORD address);
	DOUBLE_WORD GetMemoryDoubleWord(Memory& mem, DOUBLE_WORD address);
	void init();
};

#endif