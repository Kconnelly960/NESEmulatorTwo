#include "CPU.h"
#include <iostream>

void CPU::power_up(Memory& memory) {
	A, X, Y, P = 0;
	S = STACK_START;
	PC = 0xFFFC;
	mem = memory;
	mem.init(mem);
};

void CPU::reset(CPU& cpu) {

};

void CPU::stack_pop(CPU& cpu) {
	
};

void CPU::stack_push(CPU& cpu) {

};


void CPU::execute(short cycles) {
	WORD opcode = FetchByte(mem);

	switch (opcode) {
		case 0xA9:
			A = FetchByte(mem);
			if (A == 0) P |= 0b10;
			if ((A & 0b10000000) != 0) P |= 0b10000000;
			break;
		case 0xA1:
			break;
	}
};

WORD CPU::FetchByte(Memory& mem) {
	WORD instruction = mem.get_memory(mem, PC);
	PC++;
	return instruction;
};

