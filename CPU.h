#ifndef CPU_H
#define CPU_H

#include "config.H"
#include "memory.h"

/*
Emulation of 6502 CPU used in NES
*/
class CPU {
private:

	//A = supports using the status register for carrying, overflow detection, etc.
	//S = stack pointer
	//P = status register, only uses 6 bits, accessesed by PHP, PLP, arithmetic, testing, and branch instructions
	/*
		7  bit  0
	---- ----
	NVss DIZC
	|||| ||||
	|||| |||+- Carry
	|||| ||+-- Zero
	|||| |+--- Interrupt Disable
	|||| +---- Decimal
	||++------ No CPU effect, see: the B flag
	|+-------- Overflow
	+--------- Negative
	*/

	WORD A, X, Y, S, P;
	DOUBLE_WORD PC;
	Memory* mem;


public:

	void power_up(Memory* memory);
	void reset(CPU& cpu);
	void stack_pop(CPU& cpu);
	void stack_push(CPU& cpu);
	void execute(short cycles);
	WORD FetchWord(Memory& mem, short* cycles);
	WORD ReadWord(Memory& mem, short* cycles, DOUBLE_WORD address);
	void LDASetFlags();
};
#endif