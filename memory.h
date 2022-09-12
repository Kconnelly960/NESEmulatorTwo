#ifndef MEMORY_H
#define MEMORY_H
#include "config.H"

class Memory {
private:
	WORD memory[TOTAL_MEMORY];

public:
	void set_memory(Memory& memory);
	WORD get_memory(Memory& memory, WORD address);
	void init(Memory& mem);


};

#endif