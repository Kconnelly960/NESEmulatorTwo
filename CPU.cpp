#include "CPU.h"
#include <iostream>
#include <assert.h>

static void check_inbounds(unsigned short address) {
	assert(address < TOTAL_MEMORY && address > 0);
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
				DOUBLE_WORD address = FetchDoubleWorld(*mem, &cycles, PC);
				A = ReadWord(*mem, &cycles, address);
				LDASetFlags();
			} break;

			case LDA_ABS_X:
			{
				DOUBLE_WORD address = FetchDoubleWorld(*mem, &cycles, PC);
				A = ReadWord(*mem, &cycles, address + X);
				LDASetFlags();
			} break;

			case LDA_ABS_Y:
			{
				DOUBLE_WORD address = FetchDoubleWorld(*mem, &cycles, PC);
				A = ReadWord(*mem, &cycles, address + Y);
				LDASetFlags();
			} break;

			case LDA_IND_X:
			{
				//TODO

			}

			case JSR_ABS:
			{
				DOUBLE_WORD address = FetchWord(*mem, &cycles);
				address << 8;
				address &= FetchWord(*mem, &cycles);
				
				PC = address;
			}

			default:
				printf("Defaulted %i", opcode);
				break;
		}
	}
};

WORD CPU::FetchWord(Memory& mem, short* cycles) {
	check_inbounds(PC);
	WORD data = mem.GetMemoryWord(mem, PC);
	PC++;
	cycles--;
	return data;
};

WORD CPU::ReadWord(Memory& mem, short* cycles, DOUBLE_WORD address) {
	check_inbounds(address);
	WORD data = mem.GetMemoryWord(mem, address);
	cycles--;
	return data;
};

DOUBLE_WORD CPU::FetchDoubleWorld(Memory& mem, short* cycles, DOUBLE_WORD address) {
	check_inbounds(PC);
	DOUBLE_WORD data = mem.GetMemoryDoubleWord(mem, address);
	PC++;
	cycles--;
	return data;
};