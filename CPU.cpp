#include "CPU.h"
#include <iostream>
#include <assert.h>

static void check_inbounds(unsigned short pc) {
	assert(pc < TOTAL_MEMORY && pc > 0);
}

void CPU::LDASetFlags() {
	if (A == 0) P |= 0b10;
	if ((A & 0b10000000) != 0) P |= 0b10000000;
}

void CPU::power_up(Memory* memory) {
	A, X, Y, P = 0;
	S = STACK_START;
	PC = 0xFFFC;
	mem = memory;
	mem->init();
};

void CPU::reset(CPU& cpu) {

};

void CPU::stack_pop(CPU& cpu) {
	
};

void CPU::stack_push(CPU& cpu) {

};


void CPU::execute(short cycles) {

	while (cycles > 0) {
		WORD opcode = FetchWord(*mem, &cycles);

		switch (opcode) {
			case LDA_I:
				A = FetchWord(*mem, &cycles);
				LDASetFlags();
				break;

			case LDA_ZP:
			{
				WORD zero_page_address = FetchWord(*mem, &cycles);
				A = ReadWord(*mem, &cycles, zero_page_address);
				LDASetFlags();
			} break;

			case LDA_ZP_X:
			{
				WORD zero_page_address = FetchWord(*mem, &cycles);
				A = ReadWord(*mem, &cycles, zero_page_address + X);
				cycles--;
				LDASetFlags();
			} break;

			case LDA_ABS:
			{
				DOUBLE_WORD address = ( (FetchWord(*mem, &cycles) << 8) & FetchWord(*mem, &cycles) );
				A = ReadWord(*mem, &cycles, address);
			} break;

			default:
				printf("Defaulted %i", opcode);
				break;
		}
	}
};

WORD CPU::FetchWord(Memory& mem, short* cycles) {
	check_inbounds(PC);
	WORD data = mem.get_memory(mem, PC);
	PC++;
	cycles--;
	return data;
};

WORD CPU::ReadWord(Memory& mem, short* cycles, DOUBLE_WORD address) {
	check_inbounds(PC);
	WORD data = mem.get_memory(mem, address);
	cycles--;
	return data;
};

